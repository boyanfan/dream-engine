//
// Created by fanboyan on 2025/6/11.
//

#ifndef DREAM_ENGINE_APPLICATION_H
#define DREAM_ENGINE_APPLICATION_H

#include "symbols.h"
#include "logger.h"
#include "video.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
#include <thread>
#include <fstream>
#include <sstream>

namespace DreamEngine {
    /// Holds window properties and desired frame rate for the application, it is used to configure
    /// the SDL window when creating an Application instance.
    ///
    struct WindowConfiguration {
        /// Class Name for reflection implementation.
        public: static inline std::string self = WINDOW_CONFIGURATION_TYPE;

        /// The title of the application window.
        public: std::string title = DEFAULT_WINDOW_TITLE;

        /// The width of the application window in pixels.
        public: int width = DEFAULT_WINDOW_WIDTH;

        /// The height of the application window in pixels.
        public: int height = DEFAULT_WINDOW_HEIGHT;

        /// The target frame rate per second of the application.
        public: int frameRate = DEFAULT_WINDOW_FRAME_RATE;

        /// Default constructor.
        public: WindowConfiguration() = default;

        /// Default destructor.
        public: ~WindowConfiguration() = default;

        /// Loads configuration values from a file. The config file should contain key-value pairs:
        ///
        /// @param filepath Path to the configuration file.
        /// @return True if the file was successfully loaded and parsed.
        ///
        public: bool configurateFromFile(const std::string& filepath);
    };

    /// A basic application class which initializes SDL, creates a window and renderer, and handles the main loop.
    /// Games should inherit from it and implement run(), onUpdate() and onRender() methods to specify game logic.
    ///
    class Application {
        /// Class Name for reflection implementation.
        public: static inline std::string self = APPLICATION_TYPE;

        /// Pointer to the SDL window created by the application.
        private: SDL_Window* window = nullptr;

        /// Pointer to the SDL renderer used for rendering.
        private: SDL_Renderer* renderer = nullptr;

        /// Target frame rate per second for the main loop.
        private: int frameRate;

        /// Controls whether the main loop is currently running.
        protected: bool isRunning = true;

        /// Constructs the application using the specified window configuration.
        /// @param configuration The window settings and frame rate for the application.
        ///
        public: explicit Application(const WindowConfiguration& configuration);

        /// Destroys the application and cleans up SDL resources.
        public: virtual ~Application();

        /// Starts the application main loop.
        /// This function runs until the application receives a quit event or is explicitly stopped.
        ///
        public: void execute();

        /// Called whenever an SDL event is polled from the event queue. Override this to handle input events.
        /// @param event The SDL_Event to handle, including input, window, and system events.
        ///
        protected: virtual void onEvent(const SDL_Event& event) = NONE;

        /// Called once per frame to update the game state. Override this to handle game-specific update logic.
        /// @param interval The time has elapsed since the last frame in seconds.
        ///
        protected: virtual void onUpdate(float interval) = NONE;

        /// Called once per frame to render the game visuals. Override this to handle game-specific rendering logic.
        /// @param renderer The SDL_Renderer instance to draw with.
        ///
        protected: virtual void onRender(SDL_Renderer* renderer) = NONE;
    };
}

#endif //DREAM_ENGINE_APPLICATION_H
