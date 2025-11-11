//
// Created by fanboyan on 2025/6/30.
//

#include "character.h"

namespace Revenants {
    Character::~Character() { collisionManager->destroyCollisionBox(hurtBox); }

    void Character::onUpdate(const float interval) {
        // Update transform on gravity
        velocity += gravity * interval;
        transform.position += velocity * interval;

        // Check for the boundaries
        if (transform.position.y >= boundary.floorBoundary) { transform.position.y = boundary.floorBoundary; velocity.y = 0; }
        if (transform.position.y <= boundary.ceilingBoundary) { transform.position.y = boundary.ceilingBoundary; velocity.y = 0; }
        if (transform.position.x <= boundary.leftBoundary) { transform.position.x = boundary.leftBoundary; velocity.x = 0; }
        if (transform.position.x >= boundary.rightBoundary) { transform.position.x = boundary.rightBoundary; velocity.x = 0; }

        // Update animation
        if (currentAnimation) {
            currentAnimation->isFlippedRendering = transform.direction == DreamEngine::Direction::Left;
            currentAnimation->onUpdate(interval);
            currentAnimation->transform.position = transform.position;
        }
    }

    void Character::onRender(const DreamEngine::Camera& camera) const { if (currentAnimation) currentAnimation->onRender(camera); }

    void Character::setBoundary(const Boundary& boundary) { this->boundary = boundary; }
}