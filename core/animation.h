//
// Created by fanboyan on 2025/6/30.
//

#ifndef DREAM_ENGINE_ANIMATION_H
#define DREAM_ENGINE_ANIMATION_H

#include "symbols.h"
#include "renderable.h"
#include "updatable.h"
#include "timer.h"
#include "texture.h"
#include "transform.h"

#include <functional>

namespace DreamEngine {
    /// Represents a texture-sequence-based animation in the game. It supports time-based frame switching, rendering
    /// with parallax and flipping, and is suitable for animated game objects.
    ///
    class Animation final : public Renderable, public Updatable {
        /// A 2D transformation component used for positioning and orienting entities in the world or local space.
        public: Transform transform = Transform();

        /// Whether the animation should loop once it reaches the end.
        public: bool isRepeating = true;

        /// The number of frames to display per second.
        public: int frameRate;

        /// Whether the animation should be rendered with horizontal flipping.
        public: bool isFlippedRendering = false;

        /// The parallax effect strength applied during rendering.
        public: float parallexEffect = NO_PARALLEX;

        /// A flag determines whether the animation has finished.
        public: bool hasFinished = false;

        /// The offset for flipping when the texture content is not centered.
        private: float flipOffset = NONE;

        /// The internal timer that drives frame updates.
        private: Timer timer = Timer();

        /// The current index of the frame being displayed.
        private: size_t frameIndex = 0;

        /// Optional callback function invoked when the animation finishes
        private: std::function<void()> onTimeout;

        /// The sequence of texture regions (source rectangles) to be rendered.
        private: TextureSequence textureSequence;

        /// Constructs an Animation object using a texture sheet and frame layout.
        ///
        /// @param textureSheet The SDL texture containing all animation frames.
        /// @param textureWidth The width of a single frame.
        /// @param textureHeight The height of a single frame.
        /// @param frameRate The number of frames to play per second.
        /// @param flipOffset The offset for flipping when the texture content is not centered.
        ///
        public: Animation(SDL_Texture* textureSheet, float textureWidth, float textureHeight, int frameRate, float flipOffset = NONE);

        /// Default virtual destructor for proper cleanup.
        public: ~Animation() override = default;

        /// Updates the animation timer and advances the frame if needed.
        /// @param interval Time elapsed since the last update, in seconds.
        ///
        public: void onUpdate(float interval) override;

        /// Renders the current frame of the animation using the provided camera.
        /// @param camera The camera to apply for rendering in world space.
        ///
        public: void onRender(const Camera &camera) const override;

        /// Sets the callback function to be executed when the animation finishes.
        /// @param callback A function with no parameters and no return value to be called upon timeout.
        ///
        public: void setOnFinished(const std::function<void()>& callback);

        /// Resets the animation back to its initial state.
        public: void reset();
    };
}

#endif //DREAM_ENGINE_ANIMATION_H
