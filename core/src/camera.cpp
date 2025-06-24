//
// Created by fanboyan on 2025/6/20.
//

#include "camera.h"

namespace DreamEngine {
    Camera::Camera(SDL_Renderer *renderer) : position(Vector2()), renderer(renderer) {  }

    void Camera::renderTexture(SDL_Texture *texture, const SDL_FRect *source, const SDL_FRect *destination, const float distance) const {
        // Convert the coordinates from world space to the screen space
        SDL_FRect screenSpace = *destination;
        screenSpace.x -= position.x * distance, screenSpace.y -= position.y * distance;

        // Render the texture
        SDL_RenderTexture(renderer, texture, source, &screenSpace);
    }

    SDL_Renderer* Camera::getRenderer() const { return renderer; }

    void Camera::moveBy(const Vector2 &movement) { position += movement; }
}