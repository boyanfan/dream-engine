//
// Created by fanboyan on 2025/7/21.
//

#include "lord.h"

namespace Revenants {
    EmberLord::EmberLord() {
        // Set up health
        healthPoints = EMBER_LORD_HEALTH_POINTS * WORLD_LEVEL;

        // Set up sizes
        transform.size = DreamEngine::Vector2(EMBER_LORD_WIDTH, EMBER_LORD_HEIGHT);

        // Set up animations
        deathAnimation->isRepeating = false;
        deathAnimation->setOnFinished([this] { shouldDisplayHealthBar = false; });

        // Set up the initial states
        transform.direction = DreamEngine::Direction::Left;
        currentAnimation = idleAnimation;

        // Set up hurt box
        hurtBox = collisionManager->createCollisionBox(DreamEngine::Vector2(EMBER_LORD_HURT_BOX_OFFSET_X, EMBER_LORD_HURT_BOX_OFFSET_Y));
        hurtBox->destinationLayer = COLLISION_LAYER_ENEMY_HURT;
        hurtBox->setOnCollision([this] { healthPoints -= DamageManager::getInstance()->getDamage(ANY_PLAYER_ID); notify(healthPoints); });
    }

    EmberLord::~EmberLord() { delete idleAnimation; }

    void EmberLord::onRender(const DreamEngine::Camera &camera) const { Character::onRender(camera); }

    void EmberLord::onUpdate(const float interval) {
        hurtBox->setTransform(transform);
        Character::onUpdate(interval);

        if (healthPoints <= 0) { currentAnimation = deathAnimation; }
    }

    void EmberLord::onEvent(const SDL_Event& event) { omitted }

    void EmberLord::onEntry() { if (hurtBox) hurtBox->isEnabled = true; }
}