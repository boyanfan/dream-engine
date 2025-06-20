//
// Created by fanboyan on 2025/6/20.
//

#include "camera.h"

namespace DreamEngine {
    Camera::Camera(SDL_Renderer *renderer) : position(Vector2()), renderer(renderer) {  }

    void Camera::renderTexture(SDL_Texture *texture, const SDL_FRect *source, const SDL_FRect *destination) const {
        SDL_FRect screenSpace = *destination;
        screenSpace.x -= position.x, screenSpace.y -= position.y;
        SDL_RenderTexture(renderer, texture, source, &screenSpace);
    }

    SDL_Renderer* Camera::getRenderer() const { return renderer; }

}