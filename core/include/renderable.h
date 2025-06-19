//
// Created by fanboyan on 2025/6/18.
//

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "symbols.h"
#include <SDL3/SDL.h>

namespace DreamEngine {
    /// The standard interface for objects that can be rendered with an SDL renderer.
    /// Classes that confirm to it must implement the `onRender()` method to define how they should be drawn on screen.
    ///
    class Renderable {
        /// Virtual destructor to ensure proper cleanup of derived classes.
        public: virtual ~Renderable() = default;

        /// Defines how the object should be rendered using the given SDL renderer.
        /// @param renderer The SDL renderer used for drawing.
        ///
        protected: virtual void onRender(SDL_Renderer* renderer) = NONE;
    };
}

#endif //RENDERABLE_H
