//
// Created by fanboyan on 2025/6/11.
//

#include "application.h"

namespace DreamEngine {
    bool WindowConfiguration::configurateFromFile(const std::string &path) {
        // Try to open the configuration file
        std::ifstream file(path);
        if (!file.is_open()) return false;

        // Parse the key-value pairs from the configuration file line by line
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream stream(line);
            std::string key, value;

            // Get the key and the value
            if (std::getline(stream, key, '=') && std::getline(stream, value)) {
                if (key == "title") title = value;
                else if (key == "width") width = std::stoi(value);
                else if (key == "height") height = std::stoi(value);
                else if (key == "frameRate") frameRate = std::stoi(value);
            }
        }

        // The file was successfully loaded and parsed
        return true;
    }


    Application::Application(const WindowConfiguration& configuration) {
        // Initialize SDL image and audio
        if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) SDL_Log("[ERROR]: %s\n", SDL_GetError());

        // Create the window and renderer
        window = SDL_CreateWindow(configuration.title.c_str(), configuration.width, configuration.height, NONE);
        renderer = SDL_CreateRenderer(window, nullptr);

        // Initialize SDL mixer
        if (!Mix_OpenAudio(NONE, nullptr)) SDL_Log("[ERROR]: %s\n", SDL_GetError());

        // Initialize SDL TTF
        if (!TTF_Init()) SDL_Log("[ERROR]: %s\n", SDL_GetError());

        // Set the fixed frame rate
        frameRate = configuration.frameRate;

        // Start running the application
        isRunning = true;
    }

    Application::~Application() {
        // Quit SDL mixer and TTF for audio and fonts
        Mix_Quit();
        TTF_Quit();

        // Destroy the renderer and the window before closing the application
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void Application::run() {
        using namespace std::chrono;
        
        // Get the duration of one frame in nanosecond for the given frame rate
        const nanoseconds frameDuration = nanoseconds(NANOSECONDS_PER_SECOND / frameRate);

        // Record the time point before the first update to compute delta time
        time_point<steady_clock> tickBeforeUpdate = steady_clock::now();

        // Polling input events to handle any user input
        SDL_Event event;

        while (isRunning) {
            // Poll all SDL events to handel user input
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_EVENT_QUIT) isRunning = false;
                onEvent(event);
            }

            // Record the time point right before this frame's update logic and compute delta time for updating
            time_point<steady_clock> tickDidUpdate = steady_clock::now();
            const float interval = duration_cast<duration<float>>(tickDidUpdate - tickBeforeUpdate).count();

            // Update game logic, render the current frame and present it to the screen
            onUpdate(interval);
            onRender(renderer);
            SDL_RenderPresent(renderer);

            // Calculate how much time remains before the next frame
            nanoseconds tickWillUpdate = frameDuration - (steady_clock::now() - tickDidUpdate);

            // Sleep the thread for the remaining time to cap the frame rate
            if (tickWillUpdate > nanoseconds(0)) std::this_thread::sleep_for(tickWillUpdate);
            tickBeforeUpdate = steady_clock::now();
        }
    }
}
