//
// Created by fanboyan on 2025/6/30.
//

#include "sword.h"

namespace Revenants {
    SwordMaster::SwordMaster() {
        // Set up health
        healthPoints = SWORD_MASTER_HEALTH_POINTS;

        // Set up sizes
        transform.size = DreamEngine::Vector2(SWORD_MASTER_WIDTH, SWORD_MASTER_HEIGHT);

        // Set up the hurt box
        hurtBox = collisionManager->createCollisionBox(DreamEngine::Vector2(SWORD_MASTER_HURT_BOX_OFFSET_X, SWORD_MASTER_HURT_BOX_OFFSET_Y));

        // Set up the hit box
        hitBox = collisionManager->createCollisionBox(DreamEngine::Vector2(NONE, NONE));
        hitBox->sourceLayer = COLLISION_LAYER_ENEMY_HURT;
        hitBox->setOnCollision([this] { hitBox->isEnabled = false; });

        // Set up the initial state
        finiteStateMachine.switchCurrentState(&idleSate);

        // Set up rolling cooling down
        rollingCoolingDownTimer.isRepeating = false;
        rollingCoolingDownTimer.duration = SWORD_MASTER_ROLLING_COOL_DOWN;
        rollingCoolingDownTimer.setOnTimeout([this] { isRollingCoolingDown = false; });

        // Set up rolling animation
        rollingAnimation->isRepeating = false;
        rollingAnimation->setOnFinished([this] { isRolling = false; });

        // Set up attacking animation
        firstStrikeAttackingAnimation->isRepeating = false, secondStrikeAttackingAnimation->isRepeating = false;
        thirdStrikeAttackingAnimation->isRepeating = false, forthStrikeAttackingAnimation->isRepeating = false;
    }

    SwordMaster::~SwordMaster() {
        delete idleAnimation; delete walkingAnimation; delete runningAnimation; delete rollingAnimation;
        delete firstStrikeAttackingAnimation; delete secondStrikeAttackingAnimation;
        delete thirdStrikeAttackingAnimation; delete forthStrikeAttackingAnimation;
    }

    void SwordMaster::onEntry() { if (hurtBox) hurtBox->isEnabled = true; }

    void SwordMaster::onEvent(const SDL_Event &event) {
        const InputDeviceAction action = InputDeviceProxy::getDeviceAction(event);

        // Basic Moving
        if (action == InputDeviceAction::OnWalking) { isWalking = true; }
        if (action == InputDeviceAction::OnTurningAround) { transform.direction = transform.direction == DreamEngine::Direction::Left ? DreamEngine::Direction::Right : DreamEngine::Direction::Left; }
        if (action == InputDeviceAction::OnRunningLeft) { transform.direction = DreamEngine::Direction::Left; isRunning = true; }
        if (action == InputDeviceAction::OnRunningRight) { transform.direction = DreamEngine::Direction::Right; isRunning = true; }

        // Rolling
        if (action == InputDeviceAction::OnShiftTriggered) { if (!isRollingCoolingDown && !isAttacking) isRolling = true; }

        // Attack
        if (action == InputDeviceAction::OnPrimaryAttackTriggered) {
            if (isRolling) return;
            if (finiteStateMachine.getCurrentStateID() != SWORD_MASTER_ATTACKING_STATE_ID) isAttacking = true;
            else attackComboController.isNextAttackTriggered = true;
        }

        // Basic Moving Stopped
        if (action == InputDeviceAction::OnWalkingStopped) { isWalking = false; }
        if (action == InputDeviceAction::OnRunningStopped) { isRunning = false; }
    }

    void SwordMaster::onUpdate(const float interval) {
        if (isAttacking) finiteStateMachine.switchCurrentState(&attackState);
        else if (isRolling) finiteStateMachine.switchCurrentState(&rollingState);
        else if (isRunning) finiteStateMachine.switchCurrentState(&runningState);
        else if (isWalking) finiteStateMachine.switchCurrentState(&walkingState);
        else finiteStateMachine.switchCurrentState(&idleSate);

        // Update timers
        rollingCoolingDownTimer.onUpdate(interval);

        // Update states
        finiteStateMachine.onUpdate(interval);

        // Update collision boxes
        hurtBox->setTransform(transform);

        // Update behavior from a general character
        Character::onUpdate(interval);
    }

    void SwordMaster::onRender(const DreamEngine::Camera &camera) const { Character::onRender(camera); }

    DreamEngine::Transform SwordMaster::lookAhead() const {
        DreamEngine::Transform lookAhead = transform;
        lookAhead.position.x += transform.direction == DreamEngine::Direction::Left ? -SWORD_MASTER_LOOK_AHEAD_DISTANCE : SWORD_MASTER_LOOK_AHEAD_DISTANCE;
        return lookAhead;
    }
}
