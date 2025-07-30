//
// Created by fanboyan on 2025/7/22.
//

#include "bar.h"

namespace DreamEngine {
    BarView::BarView(const float maxProgress)
    : maxProgress(maxProgress), currentProgress(maxProgress), trailingSpeed(maxProgress * DEFAULT_TRAILING_SPEED), trailingProgress(currentProgress) { omitted }

    void BarView::onUpdate(const float interval) {
        // Current progress cannot be less than zero or greater than the maximum value
        if (currentProgress < 0) currentProgress = NONE;
        if (currentProgress > maxProgress) currentProgress = maxProgress;

        if (isTrailingEnabled) {
            // Wait for the delay
            if (trailingDelayTimer > NONE) { trailingDelayTimer -= interval; return; }

            // Set the trailing progress closer to the current progress
            if (trailingProgress > currentProgress) trailingProgress = std::max(currentProgress, trailingProgress - trailingSpeed * interval);

            // Reset the delay timer when there is no trailing, be ready for the next trailing
            else trailingDelayTimer = trailingDelay;
        }
    }

    void BarView::onRender(const Camera& camera) const {
        // Only render visible UI components
        if (!isVisible) return;

        // Get renderer
        SDL_Renderer* renderer = camera.getRenderer();

        // Outline
        SDL_SetRenderDrawColor(renderer, COLOR_TO_ARGS(outlineColor));
        SDL_RenderFillRect(renderer, &frame);

        // Background
        SDL_FRect background = frame;
        background.x += outlineWidth, background.y += outlineWidth;
        background.w -= outlineWidth * 2, background.h -= outlineWidth * 2;
        SDL_SetRenderDrawColor(renderer, COLOR_TO_ARGS(backgroundColor));
        SDL_RenderFillRect(renderer, &background);

        // Trailing
        if (isTrailingEnabled) {
            SDL_FRect trailingRect = background;
            trailingRect.w *= trailingProgress / maxProgress;
            SDL_SetRenderDrawColor(renderer, COLOR_TO_ARGS(trailingColor));
            SDL_RenderFillRect(renderer, &trailingRect);
        }

        // Foreground
        SDL_FRect foreground = background;
        foreground.w *= currentProgress / maxProgress;
        SDL_SetRenderDrawColor(renderer, COLOR_TO_ARGS(foregroundColor));
        SDL_RenderFillRect(renderer, &foreground);

        // Title
        if (!titleContent.empty() && !titleFont.empty()) {
            FontRepresentable* fontRepresentable = ResourceManager::getInstance()->getFont(titleFont);

            // Convert from ttf to texture
            TTF_Font* font = fontRepresentable->getSizedFont(titleFontSize);
            SDL_Surface* surface = TTF_RenderText_Blended(font, titleContent.c_str(), NONE, { COLOR_TO_ARGS(titleColor) });
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

            // Scale texture
            float textureWidth = NONE, textureHeight = NONE;
            SDL_GetTextureSize(texture, &textureWidth, &textureHeight);
            textureHeight *= titleScaleFactor, textureWidth *= titleScaleFactor;

            // Place texture
            SDL_FRect title = {
                NONE, frame.y - textureHeight - titlePaddings.bottom, textureWidth, textureHeight
            };

            // Calculate positions after the alignment
            if (titleAlignment == Alignment::Leading) title.x = frame.x + titlePaddings.leading;
            else if (titleAlignment == Alignment::Trailing) title.x = frame.x + frame.w - textureWidth - titlePaddings.trailing;
            else title.x = frame.x + (frame.w - textureWidth) / 2;

            // Render and destroy texture
            SDL_RenderTexture(renderer, texture, nullptr, &title);
            SDL_DestroyTexture(texture);
            SDL_DestroySurface(surface);
        }
    }
}