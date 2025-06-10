//
// Created by fanboyan on 2025/6/7.
//

#include "font.h"

namespace DreamEngine {
    Font::Font(std::string path) : path(std::move(path)) {  }

    Font::~Font() {
        for (std::pair<const int, TTF_Font*>& pair : fontSizePool) { TTF_CloseFont(pair.second); }
    }

    TTF_Font *Font::getSizedFont(const int fontSize) {
        // Try to find a font with the given size from the pool
        TTF_Font* font = fontSizePool[fontSize];

        // If the font of the given size has not been loaded, load it
        if (!font) {
            font = TTF_OpenFont(path.c_str(), static_cast<float>(fontSize));
            fontSizePool[fontSize] = font;
        }

        return font;
    }
}
