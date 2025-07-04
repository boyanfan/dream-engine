//
// Created by fanboyan on 2025/6/20.
//

#include "camera.h"
#include "logger.h"
#include "symbols.h"

namespace DreamEngine {
    Camera::Camera(SDL_Renderer* renderer) : renderer(renderer) { omitted }

    SDL_Renderer* Camera::getRenderer() const { return renderer; }

    void Camera::renderTexture(SDL_Texture *texture, const SDL_FRect *source, const SDL_FRect *destination, const float parallex) const {
        // Convert the coordinates from world space to the screen space
        SDL_FRect screenSpace = *destination;
        screenSpace.x -= transform.position.x * parallex, screenSpace.y -= transform.position.y * parallex;

        // Render the texture
        SDL_RenderTexture(renderer, texture, source, &screenSpace);
    }

    void Camera::enableVirtualResolution(const int width, const int height) {
        isVirtualResolution = true;
        virtualWidth = width, virtualHeight = height;
    }

    void Camera::disableVirtualResolution() { isVirtualResolution = false; }

    void Camera::onNotified(const Transform& newValue) {
        transform.position.x = newValue.position.x + (-12 - 576 / 2);
    }
}
