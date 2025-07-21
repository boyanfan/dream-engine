//
// Created by fanboyan on 2025/7/11.
//

#ifndef DREAM_ENGINE_COLLISION_H
#define DREAM_ENGINE_COLLISION_H

#include "transform.h"
#include "singleton.h"
#include "renderable.h"

#include <SDL3/SDL.h>
#include <vector>
#include <functional>

namespace DreamEngine {
    /// Represents an axis-aligned rectangular collision box attached to a game object. Each CollisionBox is defined
    /// relative to a Transform and an optional offset. It participates in collision detection via the CollisionManager.
    ///
    struct CollisionBox { friend class CollisionManager;
        /// Dream Engine uses `std::string` for identifiers. This type alias makes the collision layers identifiable.
        using CollisionLayer = Identifier;

        /// The transform representing the object's position and size.
        private: Transform transform;

        /// The local offset from the transform position.
        private: Vector2 offset;

        /// Callback function triggered when a collision occurs.
        private: std::function<void()> onCollision;

        /// Flag indicating whether the collision box is active and should be processed.
        public: bool isEnabled = false;

        /// Logical source and destination layer used for selective collision filtering when processing collisions.
        public: CollisionLayer sourceLayer = LAYER_NONE, destinationLayer = LAYER_NONE;

        /// Constructs a `CollisionBox` with an optional local offset.
        /// @param offset A local offset relative to the transform's position.
        ///
        private: explicit CollisionBox(const Vector2& offset = Vector2());

        /// Destroys the collision box.
        private: ~CollisionBox() = default;

        /// Sets the world-space transform for the collision box.
        /// @param transform The new transform to associate with this collision box.
        ///
        public: void setTransform(const Transform& transform);

        /// Sets the local offset from the transform position.
        /// @param offset The new offset value.
        ///
        public: void setOffset(const Vector2& offset);

        /// Assigns a callback function to be executed when a collision occurs.
        /// @param callback The collision response callback.
        ///
        public: void setOnCollision(const std::function<void()>& callback);
    };

    /// Manages all active CollisionBox instances and handles collision detection logic using ABBA axis-aligned
    /// collision detection algorithm. It is implemented as a singleton and supports debug rendering.
    ///
    class CollisionManager final : public Singleton<CollisionManager>, public Renderable { friend class Singleton<CollisionManager>;
        /// All registered collision boxes being tracked.
        private: std::vector<CollisionBox*> collisionBoxes;

        /// Private constructor to enforce the singleton pattern.
        private: CollisionManager() = default;

        /// Destructor for the manager.
        private: ~CollisionManager() override = default;

        /// Creates a new `CollisionBox` with an optional offset and registers it.
        /// @param offset The local offset for the collision box.
        /// @return A pointer to the newly created `CollisionBox`.
        ///
        public: CollisionBox* createCollisionBox(const Vector2& offset = Vector2());

        /// Destroys and deregisters a collision box.
        /// @param collisionBox The pointer to the collision box to be destroyed.
        ///
        public: void destroyCollisionBox(CollisionBox* collisionBox);

        /// Processes collision detection for all active collision boxes using ABBA axis-aligned collision detection
        /// algorithm. It invokes the assigned `onCollision` callbacks when collisions occur.
        ///
        public: void processCollision() const;

        /// Renders all active collision boxes for debugging purposes.
        /// @param camera The camera used to project collision boxes on screen.
        ///
        public: void onRender(const Camera& camera) const override;
    };
}

#endif //DREAM_ENGINE_COLLISION_H
