//
// Created by fanboyan on 2025/6/20.
//

#include "geometry.h"

namespace DreamEngine {
    GeometryProxy::GeometryProxy(SDL_Window *window) {
        if (window) bind(window);
        else LOG_ERROR("Cannot bind a null window to GeometryProxy.");
    }

    void GeometryProxy::bind(SDL_Window *window) { this->window = window; }

    Vector2 GeometryProxy::getWindowPosition() const {
        int x, y;
        if (SDL_GetWindowPosition(window, &x, &y)) return Vector2(static_cast<float>(x), static_cast<float>(y));

        LOG_ERROR(Logger::onDataAccess(self, "SDL::WindowPosition", LOG_FAILURE));
        return Vector2();
    }

    Vector2 GeometryProxy::getWindowSize() const {
        int width, height;
        if (SDL_GetWindowSize(window, &width, &height)) return Vector2(static_cast<float>(width), static_cast<float>(height));

        LOG_ERROR(Logger::onDataAccess(self, "SDL::WindowSize", LOG_FAILURE));
        return Vector2();
    }

    Vector2 GeometryProxy::getWindowCenter() const { return getWindowPosition() + getWindowSize() / 2; }
}
