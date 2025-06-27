//
// Created by fanboyan on 2025/6/18.
//

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "symbols.h"
#include "camera.h"
#include <SDL3/SDL.h>

namespace DreamEngine {
    /// The standard interface for objects that can be rendered with a Dream Engine Camera.
    /// Classes that confirm to it must implement the `onRender()` method to define how they should be drawn on screen.
    ///
    interface Renderable {
        /// Virtual destructor to ensure proper cleanup of derived classes.
        public: virtual ~Renderable() = default;

        /// Defines how the object should be rendered using the given SDL renderer.
        /// @param camera Which of the Dream Engine Camera to render on.
        ///
        public: virtual void onRender(const Camera& camera) const = delegated;
    };
}

#endif //RENDERABLE_H
