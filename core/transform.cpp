//
// Created by fanboyan on 2025/7/5.
//

#include "transform.h"

namespace DreamEngine {
    Transform::Transform(const Vector2& position, const Vector2& size, const Vector2& scale, const float rotation, const Vector2& anchor)
        :position(position), size(size), scale(scale), rotation(rotation), anchor(anchor) { omitted }

    Transform Transform::operator +(const Transform &other) const {
        return Transform(position + other.position, size + other.size, scale + other.scale, rotation + other.rotation, anchor + other.anchor);
    }

    Transform Transform::operator -(const Transform &other) const {
        return Transform(position - other.position, size - other.size, scale - other.scale, rotation - other.rotation, anchor - other.anchor);
    }

    Transform Transform::operator *(const float value) const {
        return Transform(position * value, size * value, scale * value, rotation * value, anchor * value);
    }

    void Transform::operator +=(const Transform &other) {
        position += other.position;
        size += other.size;
        scale += other.scale;
        rotation += other.rotation;
        anchor += other.anchor;
    }

    void Transform::operator -=(const Transform &other) {
        position -= other.position;
        size -= other.size;
        scale -= other.scale;
        rotation -= other.rotation;
        anchor -= other.anchor;
    }

    void Transform::operator *=(const float value) {
        position *= value;
        size *= value;
        scale *= value;
        rotation *= value;
        anchor = anchor * value;
    }
}