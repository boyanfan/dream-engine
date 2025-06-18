//
// Created by fanboyan on 2025/6/7.
//

#include "font.h"

namespace DreamEngine {
    Font::Font(std::string path) : path(std::move(path)) {  }

    Font::~Font() {
        for (const std::pair<const int, TTF_Font*>& pair : fontSizePool) { TTF_CloseFont(pair.second); }
    }

    TTF_Font *Font::getSizedFont(const int fontSize) {
        // Check if the font is already loaded in the pool
        const std::unordered_map<int, TTF_Font*>::iterator iterator = fontSizePool.find(fontSize);
        if (iterator != fontSizePool.end()) return iterator->second;

        // If not found, load it and insert into the pool
        TTF_Font* font = TTF_OpenFont(path.c_str(), static_cast<float>(fontSize));
        fontSizePool[fontSize] = font;
        return font;
    }
}
