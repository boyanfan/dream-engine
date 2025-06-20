//
// Created by fanboyan on 2025/6/10.
//

#ifndef DREAM_ENGINE_VECTOR2_H
#define DREAM_ENGINE_VECTOR2_H

#include <cmath>

namespace DreamEngine {
    /// A simple 2D vector class for representing and manipulating 2D vectors, supports mathematical operations for
    /// 2D vectors, such as addition, subtraction, scalar division, dot product, normalization, and more.
    /// It is useful for applications like graphics and physics simulations.
    ///
    struct Vector2 {
        /// Horizontal components of the 2D vector.
        public: float x = 0;

        /// Vertical components of the 2D vector.
        public: float y = 0;

        /// Default constructor. Initializes the vector to (0, 0).
        public: Vector2() = default;

        /// Constructs a 2D vector with the given components.
        ///
        /// @param x The horizontal component.
        /// @param y The vertical component.
        ///
        public: Vector2(float x, float y);

        /// Default destructor.
        public: ~Vector2() = default;

        /// Adds two vectors.
        ///
        /// @param other The vector to add.
        /// @return A new vector that is the sum of this and `other`.
        ///
        public: Vector2 operator +(const Vector2& other) const;

        /// Subtracts one vector from another.
        ///
        /// @param other The vector to subtract.
        /// @return A new vector that is the difference between this and `other`.
        ///
        public: Vector2 operator -(const Vector2& other) const;

        /// Computes the dot product of this vector and another.
        ///
        /// @param other The other vector to dot with.
        /// @return The dot product as a float.
        ///
        public: float operator *(const Vector2& other) const;

        /// Multiplies the vector by a scalar.
        ///
        /// @param value The scalar to multiply with.
        /// @return A new vector scaled by `value`.
        ///
        public: Vector2 operator *(float value) const;

        /// Divides the vector by a scalar.
        ///
        /// @param value The scalar to divide by.
        /// @return A new vector scaled by the reciprocal of `value`.
        ///
        public: Vector2 operator /(float value) const;

        /// Adds another vector to this one in-place.
        /// @param other The vector to add.
        ///
        public: void operator +=(const Vector2& other);

        /// Subtracts another vector from this one in-place.
        /// @param other The vector to subtract.
        ///
        public: void operator -=(const Vector2& other);

        /// Performs component-wise multiplication with another vector in-place.
        /// @param other The vector to multiply with.
        ///
        public: void operator *=(const Vector2& other);

        /// Divides this vector by a scalar in-place.
        /// @param value The scalar to divide by.
        ///
        public: void operator /=(float value);

        /// Computes the magnitude (length) of the vector.
        /// @return The magnitude as a float.
        ///
        public: float magnitude() const;

        /// Returns a normalized (unit length) version of this vector.
        /// @return A new vector with the same direction but a magnitude of 1.
        ///
        public: Vector2 normalize() const;
    };
}

#endif //DREAM_ENGINE_VECTOR2_H
