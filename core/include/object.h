//
// Created by fanboyan on 2025/6/29.
//

#ifndef DREAM_ENGINE_OBJECT_H
#define DREAM_ENGINE_OBJECT_H

#include "symbols.h"
#include "interactable.h"
#include "updatable.h"
#include "renderable.h"

namespace DreamEngine {
    /// The standard interface for all entities that exist in the game world with a position can respond to input,
    /// be updated every frame, and be rendered on screen.
    ///
    interface GameObject : public Interactable, public Updatable, public Renderable {
        /// Destructor override to ensure proper cleanup of the derived objects.
        public: Vector2 position = Vector2();

        /// The position of the game object in world space coordinate.
        public: ~GameObject() override = default;
    };
}

#endif //DREAM_ENGINE_OBJECT_H
