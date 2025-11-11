//
// Created by fanboyan on 2025/6/30.
//

#ifndef REVENANTS_SWORD_H
#define REVENANTS_SWORD_H

#include "engine/core.h"

#include "index.h"
#include "character.h"
#include "input.h"
#include "damage.h"

namespace Revenants {
    class SwordMaster final : public Character, public DreamEngine::Observable<DreamEngine::Transform> {
        // Track attack combo with scoped properties
        private: struct AttackComboController {
            public: int currentComboIndex = NONE;
            public: float timeSinceLastAttackFinished = NONE;
            public: bool isNextAttackTriggered = false;

            // Reset to be ready for the next combo
            public: void reset() { currentComboIndex = NONE; timeSinceLastAttackFinished = NONE; isNextAttackTriggered = false; }
        };

        private: AttackComboController attackComboController = AttackComboController();

        // Hit box
        public: DreamEngine::CollisionBox* hitBox = nullptr;

        // Boolean tags for states transitions
        private: bool isWalking = false, isRunning = false, isRolling = false;
        private: bool isAttacking = false;

        // Timers for cooling down
        private: DreamEngine::Timer rollingCoolingDownTimer = DreamEngine::Timer();
        private: bool isRollingCoolingDown = false;

        // Set idle animation
        private: SDL_Texture* idleAnimationSequence = resourceManager->getTexture(SWORD_MASTER_IDLE_ANIMATION_ID);
        private: DreamEngine::Animation* idleAnimation = new DreamEngine::Animation(
            idleAnimationSequence, SWORD_MASTER_TEXTURE_WIDTH, SWORD_MASTER_TEXTURE_HEIGHT, SWORD_MASTER_ANIMATION_BASIC_FRAME_RATE, SWORD_MASTER_ANIMATION_OFFSET
        );

        // Set walking animation
        private: SDL_Texture* walkAnimationSequence = resourceManager->getTexture(SWORD_MASTER_WALK_ANIMATION_ID);
        private: DreamEngine::Animation* walkingAnimation = new DreamEngine::Animation(
            walkAnimationSequence, SWORD_MASTER_TEXTURE_WIDTH, SWORD_MASTER_TEXTURE_HEIGHT, SWORD_MASTER_ANIMATION_BASIC_FRAME_RATE, SWORD_MASTER_ANIMATION_OFFSET
        );

        // Set running animation
        private: SDL_Texture* runAnimationSequence = resourceManager->getTexture(SWORD_MASTER_RUN_ANIMATION_ID);
        private: DreamEngine::Animation* runningAnimation = new DreamEngine::Animation(
            runAnimationSequence, SWORD_MASTER_TEXTURE_WIDTH, SWORD_MASTER_TEXTURE_HEIGHT, SWORD_MASTER_ANIMATION_FAST_FRAME_RATE, SWORD_MASTER_ANIMATION_OFFSET
        );

        // Set rolling animation
        private: SDL_Texture* rollAnimationSequence = resourceManager->getTexture(SWORD_MASTER_ROLL_ANIMATION_ID);
        private: DreamEngine::Animation* rollingAnimation = new DreamEngine::Animation(
            rollAnimationSequence, SWORD_MASTER_TEXTURE_WIDTH, SWORD_MASTER_TEXTURE_HEIGHT, SWORD_MASTER_ANIMATION_FAST_FRAME_RATE, SWORD_MASTER_ANIMATION_OFFSET
        );

        // Set the first strike attack animation
        private: SDL_Texture* firstStrikeAttackSequence = resourceManager->getTexture(SWORD_MASTER_FIRST_STRIKE_ATTACK_ID);
        private: DreamEngine::Animation* firstStrikeAttackingAnimation = new DreamEngine::Animation(
            firstStrikeAttackSequence, SWORD_MASTER_TEXTURE_WIDTH, SWORD_MASTER_TEXTURE_HEIGHT, SWORD_MASTER_ANIMATION_FAST_FRAME_RATE, SWORD_MASTER_ANIMATION_OFFSET
        );

        // Set the second strike attack animation
        private: SDL_Texture* secondStrikeAttackSequence = resourceManager->getTexture(SWORD_MASTER_SECOND_STRIKE_ATTACK_ID);
        private: DreamEngine::Animation* secondStrikeAttackingAnimation = new DreamEngine::Animation(
            secondStrikeAttackSequence, SWORD_MASTER_TEXTURE_WIDTH, SWORD_MASTER_TEXTURE_HEIGHT, SWORD_MASTER_ANIMATION_FAST_FRAME_RATE, SWORD_MASTER_ANIMATION_OFFSET
        );

        // Set the third strike attack animation
        private: SDL_Texture* thirdStrikeAttackSequence = resourceManager->getTexture(SWORD_MASTER_THIRD_STRIKE_ATTACK_ID);
        private: DreamEngine::Animation* thirdStrikeAttackingAnimation = new DreamEngine::Animation(
            thirdStrikeAttackSequence, SWORD_MASTER_TEXTURE_WIDTH, SWORD_MASTER_TEXTURE_HEIGHT, SWORD_MASTER_ANIMATION_FAST_FRAME_RATE, SWORD_MASTER_ANIMATION_OFFSET
        );

        // Set the forth strike attack animation
        private: SDL_Texture* forthStrikeAttackSequence = resourceManager->getTexture(SWORD_MASTER_FORTH_STRIKE_ATTACK_ID);
        private: DreamEngine::Animation* forthStrikeAttackingAnimation = new DreamEngine::Animation(
            forthStrikeAttackSequence, SWORD_MASTER_TEXTURE_WIDTH, SWORD_MASTER_TEXTURE_HEIGHT, SWORD_MASTER_ANIMATION_FAST_FRAME_RATE, SWORD_MASTER_ANIMATION_OFFSET
        );

        public: explicit SwordMaster();
        public: ~SwordMaster() override;

        public: void onEntry() override;
        public: void onEvent(const SDL_Event &event) override;
        public: void onUpdate(float interval) override;
        public: void onRender(const DreamEngine::Camera &camera) const override;

        // Finite State Machine
        private: class IdleState; friend class IdleState;
        private: class WalkingState; friend class WalkingState;
        private: class RunningState; friend class RunningState;
        private: class RollingState; friend class RollingState;
        private: class AttackState; friend class AttackState;

        // Idle behavior definition
        class IdleState final : public DreamEngine::State {
            private: SwordMaster& swordMaster;
            public: explicit IdleState(SwordMaster& swordMaster) : swordMaster(swordMaster) { omitted }

            public: void onEntry() override { swordMaster.currentAnimation = swordMaster.idleAnimation; }
            public: void onExit() override { swordMaster.currentAnimation->reset(); }
            public: void onUpdate(float interval) override { swordMaster.notify(swordMaster.lookAhead()); }

            public: Identifier getIdentifier() const override { return SWORD_MASTER_IDLE_STATE_ID; }
        };

        // Walking behavior definition
        class WalkingState final : public DreamEngine::State {
            private: SwordMaster& swordMaster;
            public: explicit WalkingState(SwordMaster& swordMaster) : swordMaster(swordMaster) { omitted }

            public: void onEntry() override { swordMaster.currentAnimation = swordMaster.walkingAnimation; }
            public: void onExit() override { swordMaster.velocity.x = NONE; swordMaster.currentAnimation->reset(); }
            public: void onUpdate(float interval) override {
                swordMaster.velocity.x = swordMaster.transform.direction == DreamEngine::Direction::Left ? -SWORD_MASTER_WALKING_VELOCITY : SWORD_MASTER_WALKING_VELOCITY;
                swordMaster.notify(swordMaster.lookAhead());
            }

            public: Identifier getIdentifier() const override { return SWORD_MASTER_WALKING_STATE_ID; }
        };

        // Running behavior definition
        class RunningState final : public DreamEngine::State {
            private: SwordMaster& swordMaster;
            public: explicit RunningState(SwordMaster& swordMaster) : swordMaster(swordMaster) { omitted }

            public: void onEntry() override { swordMaster.currentAnimation = swordMaster.runningAnimation; }
            public: void onExit() override { swordMaster.velocity.x = NONE; swordMaster.currentAnimation->reset(); }
            public: void onUpdate(float interval) override {
                swordMaster.velocity.x = swordMaster.transform.direction == DreamEngine::Direction::Left ? -SWORD_MASTER_RUNNING_VELOCITY : SWORD_MASTER_RUNNING_VELOCITY;
                swordMaster.notify(swordMaster.lookAhead());
            }

            public: Identifier getIdentifier() const override { return SWORD_MASTER_RUNNING_STATE_ID; }
        };

        // Rolling behavior definition
        class RollingState final : public DreamEngine::State {
            private: SwordMaster& swordMaster;
            private: float rollingVelocity = NONE;
            public: explicit RollingState(SwordMaster& swordMaster) : swordMaster(swordMaster) { omitted }

            public: void onEntry() override {
                swordMaster.currentAnimation = swordMaster.rollingAnimation;
                swordMaster.isRollingCoolingDown = true;
                swordMaster.rollingCoolingDownTimer.restart();
                rollingVelocity = swordMaster.transform.direction == DreamEngine::Direction::Left ? -SWORD_MASTER_ROLLING_VELOCITY : SWORD_MASTER_ROLLING_VELOCITY;
            }

            public: void onExit() override { swordMaster.velocity.x = NONE; swordMaster.currentAnimation->reset(); }

            public: void onUpdate(const float interval) override {
                swordMaster.velocity.x = rollingVelocity;
                swordMaster.notify(swordMaster.lookAhead());
            }

            public: Identifier getIdentifier() const override { return SWORD_MASTER_ROLLING_STATE_ID; }
        };

        // Attacking behavior definition
        class AttackState final : public DreamEngine::State {
            private: SwordMaster& swordMaster;
            private: AttackComboController& comboController;

            public: explicit AttackState(SwordMaster& swordMaster) : swordMaster(swordMaster), comboController(swordMaster.attackComboController) { omitted }

            public: void onEntry() override { attackWillBeTriggered(1); }
            public: void onExit() override { comboController.reset(); }

            public: void onUpdate(const float interval) override {
                if (!swordMaster.currentAnimation->hasFinished) return;

                // If the current attack finishes, wait for triggering the combo
                if (!comboController.isNextAttackTriggered) {
                    // Update the combo triggering timer
                    comboController.timeSinceLastAttackFinished += interval;

                    // If no combo triggered
                    if (comboController.timeSinceLastAttackFinished > SWORD_MASTER_CAN_ATTACK_COMBO_WINDOW) {
                        swordMaster.isAttacking = false;
                    }
                }

                // If the next triggered has been queued
                else {
                    comboController.isNextAttackTriggered = false;
                    attackWillBeTriggered(comboController.currentComboIndex + 1);
                }

                swordMaster.notify(swordMaster.lookAhead());
            }

            void attackWillBeTriggered(const int currentComboIndex) const {
                if (currentComboIndex > SWORD_MASTER_ATTACK_COMBO_INDEX_MAX) { swordMaster.isAttacking = false; return; }

                comboController.reset();
                comboController.currentComboIndex = currentComboIndex;

                // Display animation and set damages based on the current strike
                if (currentComboIndex == 1) {
                    swordMaster.currentAnimation = swordMaster.firstStrikeAttackingAnimation;
                    DamageManager::getInstance()->setDamage(ANY_PLAYER_ID, SWORD_MASTER_FIRST_STRIKE_ATTACK_DAMAGE);
                }

                else if (currentComboIndex == 2) {
                    swordMaster.currentAnimation = swordMaster.secondStrikeAttackingAnimation;
                    DamageManager::getInstance()->setDamage(ANY_PLAYER_ID, SWORD_MASTER_SECOND_STRIKE_ATTACK_DAMAGE);
                }

                else if (currentComboIndex == 3) {
                    swordMaster.currentAnimation = swordMaster.thirdStrikeAttackingAnimation;
                    DamageManager::getInstance()->setDamage(ANY_PLAYER_ID, SWORD_MASTER_THIRD_STRIKE_ATTACK_DAMAGE);
                }
                else if (currentComboIndex == 4) {
                    swordMaster.currentAnimation = swordMaster.forthStrikeAttackingAnimation;
                    DamageManager::getInstance()->setDamage(ANY_PLAYER_ID, SWORD_MASTER_FORTH_STRIKE_ATTACK_DAMAGE);
                }

                // Update the hit box
                swordMaster.hitBox->isEnabled = true;

                DreamEngine::Transform hitBoxTransform = swordMaster.transform;
                hitBoxTransform.size.x = SWORD_MASTER_HIT_BOX_WIDTH;

                const DreamEngine::Vector2 hitBoxOffset = DreamEngine::Vector2(
                    swordMaster.transform.direction == DreamEngine::Direction::Left ?
                    SWORD_MASTER_HIT_BOX_LEFT_OFFSET_X : SWORD_MASTER_HIT_BOX_RIGHT_OFFSET_X, SWORD_MASTER_HIT_BOX_OFFSET_Y
                );

                swordMaster.hitBox->setOffset(hitBoxOffset);
                swordMaster.hitBox->setTransform(hitBoxTransform);

                swordMaster.currentAnimation->reset();
            }

            public: Identifier getIdentifier() const override { return SWORD_MASTER_ATTACKING_STATE_ID; }
        };

        IdleState idleSate = IdleState(*this);
        WalkingState walkingState = WalkingState(*this);
        RunningState runningState = RunningState(*this);
        RollingState rollingState = RollingState(*this);
        AttackState attackState = AttackState(*this);

        // Get look-ahead transform
        private: DreamEngine::Transform lookAhead() const;
    };
}

#endif //REVENANTS_SWORD_H
