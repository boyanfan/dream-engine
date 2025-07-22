//
// Created by fanboyan on 2025/6/30.
//

#include "../core/include/animation.h"

namespace DreamEngine {
    Animation::Animation(SDL_Texture *textureSheet, const float textureWidth, const float textureHeight, const int frameRate, const float flipOffset)
        : frameRate(frameRate), flipOffset(flipOffset), textureSequence(TextureSequence(textureSheet, textureWidth, textureHeight)) {

        timer.isRepeating = isRepeating;
        timer.duration = ONE_SECOND / static_cast<float>(frameRate);

        timer.setOnTimeout([this] {
            frameIndex++;
            if (frameIndex >= textureSequence.getSize()) {
                hasFinished = !isRepeating;
                frameIndex = isRepeating ? 0 : textureSequence.getSize() - 1;
                if (!isRepeating && onTimeout) { onTimeout(); }
            }
        });
    }

    void Animation::reset() { timer.restart(); frameIndex = 0; hasFinished = false; }

    void Animation::setOnFinished(const std::function<void()>& callback) { onTimeout = callback; }

    void Animation::onUpdate(const float interval) { timer.onUpdate(interval); }

    void Animation::onRender(const Camera& camera) const {
        // Get the texture of the current frame and set the anchor point to the bottom center
        const TextureRepresentable currentFrame = textureSequence.getTexture(frameIndex);

        SDL_FRect destination = {
            transform.position.x - currentFrame.source.w / 2, transform.position.y - currentFrame.source.h,
            currentFrame.source.w, currentFrame.source.h
        };

        if (isFlippedRendering) {
            destination.x += destination.w / 2 + flipOffset; destination.w *= -1;
        }

        // Submit the texture and the destination to the camera to render
        camera.renderTexture(currentFrame.texture, &currentFrame.source, &destination, parallexEffect);
    }
}
