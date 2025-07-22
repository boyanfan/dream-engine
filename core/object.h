//
// Created by fanboyan on 2025/6/29.
//

#ifndef DREAM_ENGINE_OBJECT_H
#define DREAM_ENGINE_OBJECT_H

#include "symbols.h"
#include "interactable.h"
#include "updatable.h"
#include "renderable.h"
#include "transform.h"

namespace DreamEngine {
    /// The standard interface for all entities that exist in the game world with a position can respond to input,
    /// be updated every frame, and be rendered on screen.
    ///
    interface GameObject : public Interactable, public Updatable, public Renderable {
        /// A 2D transformation component used for positioning and orienting entities in the world or local space.
        public: Transform transform = Transform();

        /// Destructor override to ensure proper cleanup of the derived objects.
        public: ~GameObject() override = default;
    };
}

#endif //DREAM_ENGINE_OBJECT_H
