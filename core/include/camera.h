//
// Created by fanboyan on 2025/6/20.
//

#ifndef DREAM_ENGINE_CAMERA_H
#define DREAM_ENGINE_CAMERA_H

#include "symbols.h"
#include "vector2.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

namespace DreamEngine {
    class Camera {
        private: Vector2 position;
        private: SDL_Renderer* renderer;

        public: explicit Camera(SDL_Renderer* renderer);
        public: ~Camera() = default;

        public: SDL_Renderer* getRenderer() const;
        public: void renderTexture(SDL_Texture *texture, const SDL_FRect *source, const SDL_FRect *destination, float parallex) const;
        public: void moveBy(const Vector2& movement);
    };
}

#endif //DREAM_ENGINE_CAMERA_H
