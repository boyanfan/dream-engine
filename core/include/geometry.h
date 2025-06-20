//
// Created by fanboyan on 2025/6/20.
//

#ifndef DREAM_ENGINE_GEOMETRY_H
#define DREAM_ENGINE_GEOMETRY_H

#include "vector2.h"
#include "symbols.h"
#include "logger.h"
#include <SDL3/SDL.h>
#include <string>

namespace DreamEngine {
    /// A utility class that holds the geometry, the position and the size, of an SDL_Window.
    /// This class acts as a proxy to access the window's geometry after creation.
    ///
    struct GeometryProxy {
        /// Class Name for reflection implementation.
        public: static inline std::string self = GEOMETRY_PROXY_TYPE;

        /// Pointer to the SDL window this proxy tracks
        public: SDL_Window* window = nullptr;

        /// Construct an empty proxy with no associated window.
        public: GeometryProxy() = default;

        /// Construct a proxy and immediately captures its geometry.
        /// @param window The window to capture its geometry.
        ///
        public: explicit GeometryProxy(SDL_Window* window);

        /// Default destructor
        public: ~GeometryProxy() = default;

        /// Binds the proxy to an existing SDL window and updates geometry.
        /// @param window The window to capture its geometry.
        ///
        public: void bind(SDL_Window* window);

        /// Returns the current position of the window on the screen.
        /// @return A Vector2 containing the X and Y coordinates of the top-left corner of the window.
        ///
        public: Vector2 getWindowPosition() const;

        /// Returns the current size of the window.
        /// @return A Vector2 containing the width and height of the window in pixels.
        ///
        public: Vector2 getWindowSize() const;

        /// Returns the center point of the window.
        /// @return A Vector2 representing the center coordinates of the window,
        ///
        public: Vector2 getWindowCenter() const;
    };
}

#endif //DREAM_ENGINE_GEOMETRY_H
