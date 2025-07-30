//
// Created by fanboyan on 2025/6/20.
//

#include "camera.h"

namespace DreamEngine {
    Camera::Camera(SDL_Renderer* renderer) : renderer(renderer) { omitted }

    SDL_Renderer* Camera::getRenderer() const { return renderer; }

    void Camera::renderTexture(SDL_Texture* texture, const SDL_FRect* source, const SDL_FRect* destination, const float parallex) const {
        const SDL_FRect screenSpace = convertCoordinateFromWorldToScreen(destination, parallex);
        SDL_RenderTexture(renderer, texture, source, &screenSpace);
    }

    SDL_FRect Camera::convertCoordinateFromWorldToScreen(const SDL_FRect *destination, const float parallex) const {
        SDL_FRect screenSpace = *destination;
        screenSpace.x -= transform.position.x * parallex, screenSpace.y -= transform.position.y * parallex;
        return screenSpace;
    }

    void Camera::enableVirtualResolution(const Vector2& resolution) { isVirtualResolution = true, virtualResolution = resolution; }

    void Camera::disableVirtualResolution() { isVirtualResolution = false; virtualResolution = Vector2(); }

    void Camera::enableTargetFollowing(const Transform& target, const float inertia) {
        isTargetFollowingEnabled = true;
        targetDifference = transform - target, targetTransform = target;
        this->inertia = inertia;
        onNotified(target);
    }

    void Camera::disableTargetFollowing() {
        isTargetFollowingEnabled = false;
        targetTransform = Transform(), targetDifference = Transform();
    }

    void Camera::onNotified(const Transform& newValue) { if (isTargetFollowingEnabled) targetTransform = newValue + targetDifference; }

    void Camera::onUpdate(const float interval) {
        if (!isTargetFollowingEnabled) return;
        transform = Mathematics<Transform>::lerp(transform, targetTransform, interval * inertia, Mathematics<Transform>::linear);
    }
}
