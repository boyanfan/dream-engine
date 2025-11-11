//
// Created by fanboyan on 2025/7/21.
//

#ifndef REVENANTS_LORD_H
#define REVENANTS_LORD_H

#include "index.h"
#include "input.h"
#include "character.h"
#include "damage.h"

namespace Revenants {
    class EmberLord final : public Character, public DreamEngine::Observable<float> {
        // Set idle animation
        private: SDL_Texture* idleAnimationSequence = resourceManager->getTexture(EMBER_LORD_IDLE_ANIMATION_ID);
        private: DreamEngine::Animation* idleAnimation = new DreamEngine::Animation(
            idleAnimationSequence, EMBER_LORD_TEXTURE_WIDTH, EMBER_LORD_TEXTURE_HEIGHT, EMBER_LORD_ANIMATION_BASIC_FRAME_RATE, EMBER_LORD_ANIMATION_OFFSET
        );

        // Set death animation
        private: SDL_Texture* deathAnimationSequence = resourceManager->getTexture(EMBER_LORD_DEATH_ANIMATION_ID);
        private: DreamEngine::Animation* deathAnimation = new DreamEngine::Animation(
            deathAnimationSequence, EMBER_LORD_TEXTURE_WIDTH, EMBER_LORD_TEXTURE_HEIGHT, EMBER_LORD_ANIMATION_SLOW_FRAME_RATE, EMBER_LORD_ANIMATION_OFFSET
        );

        // Should display health bar
        public: bool shouldDisplayHealthBar = true;

        public: EmberLord();
        public: ~EmberLord() override;

        public: void onEntry() override;
        public: void onEvent(const SDL_Event &event) override;
        public: void onUpdate(float interval) override;
        public: void onRender(const DreamEngine::Camera &camera) const override;
    };
}

#endif //REVENANTS_LORD_H
