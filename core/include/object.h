//
// Created by fanboyan on 2025/6/25.
//

#ifndef DREAM_ENGINE_OBJECT_H
#define DREAM_ENGINE_OBJECT_H

#include "renderable.h"
#include "updatable.h"

namespace DreamEngine {
    /// The standard interface for any interactive entity within the game world that can be updated, rendered, and
    /// respond to events. It inherits from both Updatable and Renderable.
    ///
    interface GameObject : public Updatable, public Renderable {
        /// Virtual destructor to ensure proper cleanup of derived GameObject instances.
        public: ~GameObject() override = default;

        /// Handles SDL events such as keyboard, mouse, or controller input.
        /// @param event The SDL_Event instance representing the input to the process.
        ///
        public: virtual void onEvent(const SDL_Event& event) = delegated;
    };
}

#endif //DREAM_ENGINE_OBJECT_H
