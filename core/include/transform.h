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

        /// The size of the object in the world or local space.
        public: Vector2 size = Vector2();

        /// The scale factors along the X and Y axes.
        public: Vector2 scale = Vector2(NO_SCALE, NO_SCALE);

        /// The rotation of the object in degrees or radians.
        public: float rotation = NONE;

        /// The anchor point for transformations such as scaling or rotation.
        public: Vector2 anchor = Vector2();

        /// Constructs a default Transform with identity values.
        public: Transform() = default;

        /// Default destructor.
        public: ~Transform() = default;

        /// Constructs a Transform with the specified position, scale, rotation, and anchor.
        ///
        /// @param position The initial position of the transform.
        /// @param size The initial size of the transform.
        /// @param scale The initial scale factors for X and Y.
        /// @param rotation The initial rotation angle.
        /// @param anchor The anchor point for transformations.
        ///
        public: Transform(const Vector2& position, const Vector2& size, const Vector2& scale, float rotation, const Vector2& anchor);

        /// The facing or moving direction of the object.
        public: Direction direction = Direction::None;

        /// Adds two transforms component-wise.
        ///
        /// @param other The Transform to add.
        /// @return A new Transform that is the sum of this and `other`.
        ///
        public: Transform operator +(const Transform& other) const;

        /// Subtracts another transform from this one component-wise.
        ///
        /// @param other The Transform to subtract.
        /// @return A new Transform that is the difference between this and `other`.
        ///
        public: Transform operator -(const Transform& other) const;

        /// Multiplies all numerical components by a scalar.
        ///
        /// @param value The scalar to multiply with.
        /// @return A new Transform scaled by `value`.
        ///
        public: Transform operator *(float value) const;

        /// Adds another transform to this one in-place, component-wise.
        /// @param other The Transform to add.
        ///
        public: void operator +=(const Transform& other);

        /// Subtracts another transform from this one in-place, component-wise.
        /// @param other The Transform to subtract.
        ///
        public: void operator -=(const Transform& other);

        /// Scales this transform's numerical components in-place by a scalar.
        /// @param value The scalar to multiply with.
        ///
        public: void operator *=(float value);
    };
}

#endif //DREAM_ENGINE_TRANSFORM_H
