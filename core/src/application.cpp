//
// Created by fanboyan on 2025/6/11.
//

#include "application.h"

namespace DreamEngine {
    Application::Application(const WindowConfiguration& configuration) {
        // Initialize SDL image and audio
        if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS)) LOG_ERROR(Logger::onInitialize(Application::self, SDL_TYPE, LOG_FAILURE));
        else LOG_INFO(Logger::onInitialize(Application::self, SDL_TYPE, LOG_SUCCESS));

        // Initialize SDL window
        window = SDL_CreateWindow(configuration.title.c_str(), static_cast<int>(configuration.size.x), static_cast<int>(configuration.size.y), NONE);
        if (!window) LOG_ERROR(Logger::onInitialize(Application::self, SDL_WINDOW_TYPE, LOG_FAILURE));
        else LOG_INFO(Logger::onInitialize(Application::self, SDL_WINDOW_TYPE, LOG_SUCCESS));

        // Initialize SDL renderer
        renderer = SDL_CreateRenderer(window, nullptr);
        if (!renderer) LOG_ERROR(Logger::onInitialize(Application::self, SDL_RENDERER_TYPE, LOG_FAILURE));
        else LOG_INFO(Logger::onInitialize(Application::self, SDL_RENDERER_TYPE, LOG_SUCCESS));

        // Initialize SDL mixer
        if (!Mix_OpenAudio(NONE, nullptr)) LOG_ERROR(Logger::onInitialize(Application::self, SDL_MIXER_TYPE, LOG_FAILURE));
        else LOG_INFO(Logger::onInitialize(Application::self, SDL_MIXER_TYPE, LOG_SUCCESS));

        // Initialize SDL TTF
        if (!TTF_Init()) LOG_ERROR(Logger::onInitialize(Application::self, SDL_TTF_TYPE, LOG_FAILURE));
        else LOG_INFO(Logger::onInitialize(Application::self, SDL_TTF_TYPE, LOG_SUCCESS));

        // Create camera
        mainCamera = new Camera(renderer);

        // Create the entry scene
        SceneManager::getInstance()->switchCurrentScene(new OpeningPresentation(mainCamera, GeometryProxy(window)));

        // Set the fixed frame rate
        frameRate = configuration.frameRate;

        // Start running the application
        isRunning = true;
    }

    Application::~Application() {
        ResourceManager::destroyInstance();
        SceneManager::destroyInstance();
        delete mainCamera;

        Mix_Quit();
        LOG_INFO(Logger::onDeinitialize(Application::self, SDL_MIXER_TYPE));
        TTF_Quit();
        LOG_INFO(Logger::onDeinitialize(Application::self, SDL_TTF_TYPE));

        SDL_DestroyRenderer(renderer);
        LOG_INFO(Logger::onDeinitialize(Application::self, SDL_RENDERER_TYPE));
        SDL_DestroyWindow(window);
        LOG_INFO(Logger::onDeinitialize(Application::self, SDL_WINDOW_TYPE));

        SDL_QuitSubSystem(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
        SDL_Quit();
        LOG_INFO(Logger::onDeinitialize(Application::self, SDL_TYPE));

        Logger::destroyInstance();
    }

    void Application::execute() {
        // Get the duration of one frame in nanosecond for the given frame rate
        const std::chrono::nanoseconds frameDuration = std::chrono::nanoseconds(NANOSECONDS_PER_SECOND / frameRate);

        // Record the time point before the first update to compute delta time
        std::chrono::time_point<std::chrono::steady_clock> tickBeforeUpdate = std::chrono::steady_clock::now();

        // Polling input events to handle any user input
        SDL_Event event;

        while (isRunning) {
            // Get the current scene
            Scene* currentScene = SceneManager::getInstance()->getCurrentScene();

            // Poll all SDL events to handel user input
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_EVENT_QUIT) isRunning = false;
                if (currentScene) currentScene->onEvent(event);
            }

            // Record the time point right before this frame's update logic and compute delta time for updating
            std::chrono::time_point<std::chrono::steady_clock> tickDidUpdate = std::chrono::steady_clock::now();
            const float interval = duration_cast<std::chrono::duration<float>>(tickDidUpdate - tickBeforeUpdate).count();

            // Update game logic, render the current frame and present it to the screen
            if (currentScene) {
                currentScene->onUpdate(interval);
                currentScene->onRender(*mainCamera);
            }
            SDL_RenderPresent(renderer);

            // Calculate how much time remains before the next frame
            std::chrono::nanoseconds tickWillUpdate = frameDuration - (std::chrono::steady_clock::now() - tickDidUpdate);

            // Sleep the thread for the remaining time to cap the frame rate
            if (tickWillUpdate > std::chrono::nanoseconds(0)) std::this_thread::sleep_for(tickWillUpdate);
            tickBeforeUpdate = std::chrono::steady_clock::now();
        }
    }

    bool WindowConfiguration::configurateFromFile(const std::string &filepath) {
        // Try to open the configuration file
        std::ifstream file(filepath);

        if (!file.is_open()) {
            LOG_ERROR(Logger::onFileLoad(WindowConfiguration::self, filepath, LOG_FAILURE));
            return false;
        }
        LOG_INFO(Logger::onFileLoad(WindowConfiguration::self, filepath, LOG_SUCCESS));

        // Parse the key-value pairs from the configuration file line by line
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream stream(line);
            std::string key, value;

            // Get the key and the value
            if (std::getline(stream, key, WINDOW_CONFIGURATION_SEPARATOR) && std::getline(stream, value)) {
                if (key == WINDOW_CONFIGURATION_TITLE_KEY) title = value;
                else if (key == WINDOW_CONFIGURATION_WIDTH_KEY) size.x = std::stof(value);
                else if (key == WINDOW_CONFIGURATION_HEIGHT_KEY) size.y = std::stof(value);
                else if (key == WINDOW_CONFIGURATION_FRAME_RATE_KEY) frameRate = std::stoi(value);
            }
        }

        file.close();
        LOG_INFO(Logger::onFileUnload(WindowConfiguration::self, filepath));
        return true;
    }
}
