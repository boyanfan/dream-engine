//
// Created by fanboyan on 2025/6/20.
//

#ifndef DREAM_ENGINE_CAMERA_H
#define DREAM_ENGINE_CAMERA_H

#include "symbols.h"
#include "vector2.h"
#include "observable.h"
#include "transform.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

namespace DreamEngine {
    class Camera final : public Observer<Transform> {
        public: Transform transform = Transform();
        private: SDL_Renderer* renderer;
        public: bool isVirtualResolution = false;
        public: int virtualWidth = NONE, virtualHeight = NONE;

        public: explicit Camera(SDL_Renderer* renderer);
        public: ~Camera() override = default;

        public: SDL_Renderer* getRenderer() const;
        public: void renderTexture(SDL_Texture *texture, const SDL_FRect *source, const SDL_FRect *destination, float parallex) const;

        public: void enableVirtualResolution(int width, int height);
        public: void disableVirtualResolution();

        public: void onNotified(const Transform& newValue) override;
    };
}

#endif //DREAM_ENGINE_CAMERA_H
