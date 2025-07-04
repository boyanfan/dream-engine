//
// Created by fanboyan on 2025/7/4.
//

#ifndef DREAM_ENGINE_TRANSFORM_H
#define DREAM_ENGINE_TRANSFORM_H

#include "symbols.h"
#include "vector2.h"

namespace DreamEngine {
    /// Represents a 2D directional indicator for object orientation or movement.
    enum class Direction { Left, Right, Up, Down, Inward, Outward, None };

    /// Represents a 2D transform component with position, scale, rotation, anchor, and direction.
    struct Transform {
        /// The position of the object in the world or local space.
        public: Vector2 position = Vector2();

        /// The scale factors along the X and Y axes.
        public: Vector2 scale = Vector2(1, 1);

        /// The rotation of the object in degrees or radians.
        public: float rotation = NONE;

        /// The anchor point for transformations such as scaling or rotation.
        public: Vector2 anchor = Vector2();

        /// The facing or moving direction of the object.
        public: Direction direction = Direction::None;
    };
}

#endif //DREAM_ENGINE_TRANSFORM_H
