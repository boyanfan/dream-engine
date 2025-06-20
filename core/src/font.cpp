//
// Created by fanboyan on 2025/6/7.
//

#include "font.h"

namespace DreamEngine {
    FontWrapper::FontWrapper(std::string filepath) : filepath(std::move(filepath)) {  }

    FontWrapper::~FontWrapper() {
        for (const std::pair<const int, TTF_Font*>& pair : fontSizePool) { TTF_CloseFont(pair.second); }
    }

    TTF_Font *FontWrapper::getSizedFont(const int fontSize) {
        // Check if the font is already loaded in the pool
        const std::unordered_map<int, TTF_Font*>::iterator iterator = fontSizePool.find(fontSize);
        if (iterator != fontSizePool.end()) return iterator->second;

        // If not found, load it and insert into the pool
        TTF_Font* font = TTF_OpenFont(filepath.c_str(), static_cast<float>(fontSize));
        fontSizePool[fontSize] = font;
        return font;
    }
}
