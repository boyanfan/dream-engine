//
// Created by fanboyan on 2025/7/11.
//

#include "collision.h"

namespace DreamEngine {
    CollisionBox::CollisionBox(const Vector2& offset) : transform(Transform()), offset(offset) { omitted }

    CollisionBox* CollisionManager::createCollisionBox(const Vector2& offset) {
        CollisionBox* collisionBox = new CollisionBox(offset);
        collisionBoxes.push_back(collisionBox);
        return collisionBox;
    }

    void CollisionManager::destroyCollisionBox(CollisionBox* collisionBox) {
        collisionBoxes.erase(std::remove(collisionBoxes.begin(), collisionBoxes.end(), collisionBox), collisionBoxes.end());
        delete collisionBox;
    }

    void CollisionManager::processCollision() const {
        // Perform AB collision detection from the ABBA algorithm
        for (const CollisionBox* sourceCollisionBox : collisionBoxes) {
            // Skip disabled or empty collision boxes
            if (!sourceCollisionBox->isEnabled || sourceCollisionBox->destinationLayer == LAYER_NONE) continue;

            // Perform BA collision detection from the ABBA algorithm
            for (const CollisionBox* destinationCollisionBox : collisionBoxes) {
                // Skip disabled or same or different-layered boxes
                if (!destinationCollisionBox->isEnabled || sourceCollisionBox == destinationCollisionBox || sourceCollisionBox->sourceLayer != destinationCollisionBox->destinationLayer) continue;
                    // Calculate the geometry of two boxes
                    const Vector2 sourceHalf = sourceCollisionBox->transform.size * 0.5f;
                    const Vector2 destinationHalf = destinationCollisionBox->transform.size * 0.5f;
                    const Vector2 sourceCentre = sourceCollisionBox->transform.position + sourceHalf;
                    const Vector2 destinationCentre = destinationCollisionBox->transform.position + destinationHalf;

                    // Determine collisions in both horizontal and vertical directions
                    const bool isHorizontalCollision = std::abs(sourceCentre.x - destinationCentre.x) <= sourceHalf.x + destinationHalf.x;
                    const bool isVerticalCollision = std::abs(sourceCentre.y - destinationCentre.y) <= sourceHalf.y + destinationHalf.y;

                    // Collision only if both horizontal and vertical directions are collided
                    if (isHorizontalCollision && isVerticalCollision && destinationCollisionBox->onCollision) {
                        sourceCollisionBox->onCollision();
                        destinationCollisionBox->onCollision();
                    }
            }
        }
    }

    void CollisionManager::onRender(const Camera &camera) const {
        SDL_Renderer* renderer = camera.getRenderer();

        for (const CollisionBox* collisionBox : collisionBoxes) {
            // Skip disabled boxes
            if (!collisionBox->isEnabled) continue;

            // Convert the collision box coordinate from the world space to the screen space
            const SDL_FRect destination = {
                collisionBox->transform.position.x, collisionBox->transform.position.y, collisionBox->transform.size.x, collisionBox->transform.size.y
            };
            const SDL_FRect screenSpace = camera.convertCoordinateFromWorldToScreen(&destination, NO_PARALLEX);

            // Set the color of the rendering box
            SDL_SetRenderDrawColor(renderer, COLOR_TO_ARGS(Color::Black));
            SDL_RenderRect(renderer, &screenSpace);
        }
    }

    void CollisionBox::setTransform(const Transform& transform) {
        this->transform = transform;
        this->transform.position = transform.position + offset;
    }

    void CollisionBox::setOffset(const Vector2& offset) { this->offset = offset; }

    void CollisionBox::setOnCollision(const std::function<void()>& callback) { onCollision = callback; }
}
