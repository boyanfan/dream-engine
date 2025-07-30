//
// Created by fanboyan on 2025/6/11.
//

#ifndef DREAM_ENGINE_APPLICATION_H
#define DREAM_ENGINE_APPLICATION_H

#include "symbols.h"
#include "logger.h"
#include "geometry.h"
#include "resource.h"
#include "vector2.h"
#include "logo.h"
#include "collision.h"

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

        /// The width and the height of the application window in pixels.
        public: Vector2 size = Vector2(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);

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

    /// The Application class serves as the core entry point for any game or interactive program built with
    /// DreamEngine. It handles game initialization, creates the main window and renderer, and manages the main loop,
    /// including event polling, update logic, rendering, and frame rate control.
    ///
    class Application {
        /// Class Name for reflection implementation.
        public: static inline std::string self = APPLICATION_TYPE;

        /// Pointer to the SDL window created by the application.
        private: SDL_Window* window = nullptr;

        /// Pointer to the SDL renderer used for rendering.
        public: SDL_Renderer* renderer = nullptr;

        /// Pointer to the main camera used for rendering the current view.
        public: Camera* camera = nullptr;

        /// Target frame rate per second for the main loop.
        private: int frameRate;

        /// Controls whether the main loop is currently running.
        private: bool isRunning = true;

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
    };
}

#endif //DREAM_ENGINE_APPLICATION_H
