//
// Created by fanboyan on 2025/6/30.
//

#include "animation.h"

namespace DreamEngine {
    Animation::Animation(SDL_Texture *textureSheet, const float textureWidth, const float textureHeight, const int frameRate)
        : frameRate(frameRate), textureSequence(TextureSequence(textureSheet, textureWidth, textureHeight)) {

        timer.isRepeating = true;
        timer.duration = ONE_SECOND / static_cast<float>(frameRate);

        timer.setOnTimeout([this] {
            frameIndex++;
            if (frameIndex >= textureSequence.getSize()) {
                frameIndex = isRepeating ? 0 : textureSequence.getSize() - 1;
                if (!isRepeating && onTimeout) onTimeout();
            }
        });
    }

    void Animation::reset() { timer.restart(); frameIndex = 0; }

    void Animation::onUpdate(const float interval) { timer.onUpdate(interval); }

    void Animation::onRender(const Camera &camera) const {
        const TextureRepresentable currentFrame = textureSequence.getTexture(frameIndex);

        // Set the anchor point to the bottom center
        SDL_FRect const destination = {
            position.x - currentFrame.source.w / 2, position.y - currentFrame.source.h,
            currentFrame.source.w, currentFrame.source.h
        };

        camera.renderTexture(currentFrame.texture, &currentFrame.source, &destination, parallexEffect, isFlippedRendering);
    }
}
