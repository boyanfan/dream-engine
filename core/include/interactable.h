//
// Created by fanboyan on 2025/6/29.
//

#ifndef DREAM_ENGINE_INTERACTABLE_H
#define DREAM_ENGINE_INTERACTABLE_H

#include "symbols.h"
#include <SDL3/SDL.h>

namespace DreamEngine {
    /// The standard interface for all objects that can respond to SDL events, such as user input
    /// from keyboard, mouse, or controller.
    ///
    interface Interactable {
        /// Virtual destructor to ensure proper cleanup of derived classes.
        public: virtual ~Interactable() = default;

        /// Handles SDL events such as keyboard, mouse, and controller input.
        /// @param event The SDL_Event to respond to.
        ///
        public: virtual void onEvent(const SDL_Event& event) = delegated;
    };
}

#endif //DREAM_ENGINE_INTERACTABLE_H
