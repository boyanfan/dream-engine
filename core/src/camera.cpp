//
// Created by fanboyan on 2025/6/20.
//

#include "camera.h"

namespace DreamEngine {
    Camera::Camera(SDL_Renderer *renderer) : position(Vector2()), renderer(renderer) { omitted }

    SDL_Renderer* Camera::getRenderer() const { return renderer; }

    void Camera::renderTexture(SDL_Texture *texture, const SDL_FRect *source, const SDL_FRect *destination, const float parallex) const {
        // Convert the coordinates from world space to the screen space
        SDL_FRect screenSpace = *destination;
        screenSpace.x -= position.x * parallex, screenSpace.y -= position.y * parallex;

        // Render the texture
        if (isVirtualResolution) SDL_SetRenderLogicalPresentation(renderer, virtualWidth, virtualHeight, SDL_LOGICAL_PRESENTATION_OVERSCAN);
        SDL_RenderTexture(renderer, texture, source, &screenSpace);
    }

    void Camera::enableVirtualResolution(const int width, const int height) {
        isVirtualResolution = true;
        virtualWidth = width, virtualHeight = height;
    }

    void Camera::disableVirtualResolution() { isVirtualResolution = false; }

    void Camera::moveBy(const Vector2& movement) { position += movement; }
}