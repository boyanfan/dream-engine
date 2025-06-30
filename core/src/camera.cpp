//
// Created by fanboyan on 2025/6/20.
//

#include "camera.h"

namespace DreamEngine {
    Camera::Camera(SDL_Renderer *renderer) : position(Vector2()), renderer(renderer) { omitted }

    void Camera::renderTexture(SDL_Texture *texture, const SDL_FRect *source, const SDL_FRect *destination, const float parallex, const bool isFlippedRendering) const {
        // Convert the coordinates from world space to the screen space
        SDL_FRect screenSpace = *destination;
        screenSpace.x -= position.x * parallex, screenSpace.y -= position.y * parallex;
        screenSpace.w *= globalScreenScale, screenSpace.h *= globalScreenScale;

        const SDL_FlipMode flipMode = isFlippedRendering ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        const SDL_FPoint flipAnchor = {screenSpace.w / 2, screenSpace.h / 2};

        // Render the texture
        SDL_RenderTextureRotated(renderer, texture, source, &screenSpace, NONE, &flipAnchor, flipMode);
    }

    SDL_Renderer* Camera::getRenderer() const { return renderer; }

    void Camera::moveBy(const Vector2& movement) { position += movement; }
}