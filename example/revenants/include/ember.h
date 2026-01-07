//
// Created by fanboyan on 2025/6/29.
//

#ifndef REVENANTS_EMBER_H
#define REVENANTS_EMBER_H

#include "engine/core.h"
#include "engine/ui.h"

#include "index.h"
#include "sword.h"
#include "lord.h"
#include "boundary.h"

namespace Revenants {
    class EmberScene final : public DreamEngine::Scene {
        // Scene Components
        private: const DreamEngine::TextureSequence backgroundSequence;
        private: DreamEngine::Camera& camera;

        // Scene Characters
        private: SwordMaster* playableCharacter = nullptr;
        private: EmberLord* bossCharacter = nullptr;
        private: std::vector<Character*> characters;

        // Scene UI
        private: DreamEngine::BarView* bossHealthBar = nullptr;
        private: std::vector<DreamEngine::View*> views;

        // Scene Boundaries
        private: Boundary characterBoundary = Boundary(
            EMBER_SCENE_BACKGROUND_HEIGHT - EMBER_SCENE_FLOOR_BOUNDARY, NONE, EMBER_SCENE_PLAYABLE_LEFT_BOUNDARY, EMBER_SCENE_PLAYABLE_RIGHT_BOUNDARY
        );
        private: Boundary cameraBoundary = Boundary(
            NONE, NONE, EMBER_SCENE_CAMERA_LEFT_BOUNDARY, EMBER_SCENE_CAMERA_RIGHT_BOUNDARY
        );

        // Floating Fog
        private: float foregroundOffset = NONE;
        private: float foregroundOffsetComplementary = EMBER_SCENE_BACKGROUND_WIDTH;

        public: explicit EmberScene(DreamEngine::Camera& camera);
        public: ~EmberScene() override;

        public: void onEntry() override;
        public: void onEvent(const SDL_Event &event) override;
        public: void onUpdate(float interval) override;
        public: void onRender(const DreamEngine::Camera &camera) const override;
        public: void onExit() override;
        public: Identifier getIdentifier() const override;

        private: static DreamEngine::TextureSequence loadBackgroundSequence();
        private: void renderBackground() const;
        private: void renderForeground() const;
    };
}

#endif //REVENANTS_EMBER_H
