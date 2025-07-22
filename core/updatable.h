//
// Created by fanboyan on 2025/6/17.
//

#ifndef DREAM_ENGINE_UPDATABLE_H
#define DREAM_ENGINE_UPDATABLE_H

#include "symbols.h"

namespace DreamEngine {
    /// The standard interface for all game objects that require per-frame updates.
    /// Inherit from this class to allow a game object to be updated every frame during the game loop.
    ///
    interface Updatable {
        /// Virtual destructor to ensure proper cleanup of derived classes.
        public: virtual ~Updatable() = default;

        /// Called once per frame to update the game object's logic.
        /// @param interval The time (in seconds) elapsed since the last update.
        ///
        public: virtual void onUpdate(float interval) = delegated;
    };
}

#endif //DREAM_ENGINE_UPDATABLE_H
