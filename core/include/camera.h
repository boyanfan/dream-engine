//
// Created by fanboyan on 2025/6/20.
//

#ifndef DREAM_ENGINE_CAMERA_H
#define DREAM_ENGINE_CAMERA_H

#include "symbols.h"
#include "vector2.h"
#include "observable.h"
#include "transform.h"
#include "updatable.h"
#include "mathematics.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

namespace DreamEngine {
    /// A 2D camera that supports virtual resolution rendering, parallax effects, and optional target following
    /// with inertia smoothing.
    ///
    class Camera final : public Observer<Transform>, Updatable {
        /// SDL renderer used for drawing textures.
        private: SDL_Renderer* renderer;

        /// The current transform of the camera.
        public: Transform transform = Transform();

        /// Whether the camera is currently following a target.
        private: bool isTargetFollowingEnabled = false;

        /// The transform of the object being followed.
        private: Transform targetTransform = Transform();

        /// Offset applied to the target transform.
        private: Transform targetOffest = Transform();

        /// Smoothing inertia used when following the target.
        private: float inertia = NONE;

        /// Whether virtual resolution rendering is enabled.
        public: bool isVirtualResolution = false;

        /// The resolution to use when virtual rendering is enabled.
        public: Vector2 virtualResolution = Vector2();

        /// Constructs a Camera using the given SDL renderer.
        /// @param renderer The SDL_Renderer to use for rendering.
        ///
        public: explicit Camera(SDL_Renderer* renderer);

        /// Default destructor.
        public: ~Camera() override = default;

        /// Gets the underlying SDL renderer.
        /// @return A pointer to the SDL_Renderer used by the camera.
        ///
        public: SDL_Renderer* getRenderer() const;

        /// Renders a texture using camera's position and optional parallax effect.
        ///
        /// @param texture The SDL_Texture to render.
        /// @param source The source rectangle from the texture.
        /// @param destination The destination rectangle on screen.
        /// @param parallex The parallax scrolling factor. Larger than 1.0f if the object moves faster than the camera.
        ///
        public: void renderTexture(SDL_Texture* texture, const SDL_FRect* source, const SDL_FRect* destination, float parallex) const;

        /// Enables virtual resolution rendering for pixel-perfect rendering or scaling.
        /// @param resolution The virtual resolution to render within.
        ///
        public: void enableVirtualResolution(const Vector2& resolution);

        /// Disables virtual resolution rendering and restores native resolution.
        public: void disableVirtualResolution();

        /// Enables following a target with optional inertia smoothing.
        ///
        /// @param target The transform to follow.
        /// @param inertia The smoothing inertia for movement.
        ///
        public: void enableTargetFollowing(const Transform& target, float inertia = CAMERA_DEFAULT_INERTIA);

        /// Disables the target following behavior.
        public: void disableTargetFollowing();

        /// Called when the followed transform changes.
        /// @param newValue The new value of the observed transform.
        ///
        public: void onNotified(const Transform& newValue) override;

        /// Updates the camera logic, including following movement if enabled.
        /// @param interval The time passed since the last update in seconds.
        ///
        public: void onUpdate(float interval) override;
    };
}

#endif //DREAM_ENGINE_CAMERA_H
