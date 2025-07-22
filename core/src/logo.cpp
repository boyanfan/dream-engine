//
// Created by fanboyan on 2025/6/25.
//

#include "../core/include/logo.h"

namespace DreamEngine {
    OpeningPresentation::OpeningPresentation(const Camera* camera, const GeometryProxy& geometry) {
        // Get the renderer
        SDL_Renderer* renderer = camera->getRenderer();

        // Load opening presentation
        ResourceManager* resourceManager = ResourceManager::getInstance();
        resourceManager->loadFromDirectory(renderer, DREAM_ENGINE_OPENING_RESOURCES);

        // Get opening presentation sound
        openingSound = resourceManager->getAudio(DREAM_ENGINE_OPENING_SOUND);

        // Get opening presentation logo
        VideoRepresentable* videoWrapper = resourceManager->getVideo(DREAM_ENGINE_OPENING_LOGO);
        openingLogo = videoWrapper->getVideoDecoder(geometry);
    }

    void OpeningPresentation::onEntry() {
        lockSceneTransition();
        openingSoundChannel = Mix_PlayChannel(FIRST_FREE_CHANNEL, openingSound, NONE);
    }

    void OpeningPresentation::onEvent(const SDL_Event& event) {
        if (event.type == SDL_EVENT_KEY_DOWN) {
            const bool* keyPressed = SDL_GetKeyboardState(nullptr);

            // Check whether the user has pressed any key to skip the opening presentation
            if (keyPressed[SDL_SCANCODE_SPACE] || keyPressed[SDL_SCANCODE_RETURN] || keyPressed[SDL_SCANCODE_ESCAPE]) {
                openingLogo->hasFinished = true;
                Mix_HaltChannel(openingSoundChannel);
            }
        }
    }

    void OpeningPresentation::onRender(const Camera& camera) const { openingLogo->onRender(camera); }

    void OpeningPresentation::onUpdate(float interval) { if (openingLogo->hasFinished) unlockSceneTransition(); }

    void OpeningPresentation::onExit() { omitted }

    std::string OpeningPresentation::getIdentifier() const { return DREAM_ENGINE_OPENING_IDENTIFIER; }
}