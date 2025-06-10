//
// Created by fanboyan on 2025/6/10.
//

#include "vector2.h"

namespace DreamEngine {
    Vector2::Vector2(const float x, const float y) : x(x), y(y) { }

    Vector2 Vector2::operator +(const Vector2 &other) const { return {x + other.x, y + other.y}; }

    Vector2 Vector2::operator -(const Vector2 &other) const { return {x - other.x, y - other.y}; }

    float Vector2::operator *(const Vector2 &other) const { return x * other.x + y * other.y; }

    Vector2 Vector2::operator *(const float value) const { return {x * value, y * value}; }

    Vector2 Vector2::operator /(const float value) const { return {x / value, y / value}; }

    void Vector2::operator +=(const Vector2 &other) { x += other.x; y += other.y; }

    void Vector2::operator -=(const Vector2 &other) { x -= other.x; y -= other.y; }

    void Vector2::operator *=(const Vector2 &other) { x *= other.x; y *= other.y; }

    void Vector2::operator /=(const float value) { x /= value; y /= value; }

    float Vector2::magnitude() const { return sqrt(x * x + y * y); }

    Vector2 Vector2::normalize() const {
        const float magnitude = Vector2::magnitude();

        if (magnitude == 0) return {0, 0};
        return {x / magnitude, y / magnitude};
    }
}