//
// Created by fanboyan on 2025/6/30.
//

#ifndef REVENANTS_CHARACTER_H
#define REVENANTS_CHARACTER_H

#include "engine/core.h"
#include "boundary.h"

namespace Revenants {
    class Character : public DreamEngine::GameObject {
        // Damageable properties
        public: float healthPoints = NONE;
        public: DreamEngine::CollisionBox* hurtBox = nullptr;
        protected: DreamEngine::CollisionManager* collisionManager = DreamEngine::CollisionManager::getInstance();

        // Position and movements
        protected: DreamEngine::Vector2 velocity = DreamEngine::Vector2();
        protected: const DreamEngine::Vector2 gravity = DreamEngine::Vector2(NONE, GRAVITY);
        protected: Boundary boundary = Boundary();

        // FSM and animations
        protected: DreamEngine::FiniteStateMachine finiteStateMachine = DreamEngine::FiniteStateMachine();
        public: DreamEngine::Animation* currentAnimation = nullptr;

        // Get character resources
        const DreamEngine::ResourceManager* resourceManager = DreamEngine::ResourceManager::getInstance();

        public: Character() = default;
        public: ~Character() override;

        public: virtual void onEntry() = delegated;
        public: void onUpdate(float interval) override;
        public: void onRender(const DreamEngine::Camera& camera) const override;

        public: void setBoundary(const Boundary& boundary);
    };
}

#endif //REVENANTS_CHARACTER_H
