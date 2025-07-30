//
// Created by fanboyan on 2025/6/7.
//

#ifndef DREAM_ENGINE_FONT_H
#define DREAM_ENGINE_FONT_H

#include "symbols.h"

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
#include <unordered_map>

namespace DreamEngine {
    /// Represents a font resource loaded from a file, supporting multiple font sizes.
    /// It ensures each font size is only loaded once and handles proper cleanup on destruction.
    ///
    struct FontRepresentable {
        /// Path to the font file, with an extension of ".ttf".
        private: std::string filepath;

        /// A pool that caches TTF_Font* objects for different font sizes, keyed by a float font size.
        private: std::unordered_map<float, TTF_Font*> fontSizePool;

        // Constructs a Font object with the given font file path.
        /// @param filepath Path to the font file, with an extension of ".ttf".
        ///
        public: explicit FontRepresentable(std::string filepath);

        /// Destructor. Frees all loaded TTF_Font resources.
        public: ~FontRepresentable();

        /// Retrieves a font of the specified size. If the font size has already been loaded, return the cached font.
        /// Otherwise, loads the font and caches it for future use.
        ///
        /// @param fontSize The desired font size in points.
        /// @return A pointer to the loaded TTF_Font, or nullptr if loading failed.
        ///
        TTF_Font* getSizedFont(float fontSize);
    };
}

#endif //DREAM_ENGINE_FONT_H
