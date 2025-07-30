//
// Created by fanboyan on 2025/6/7.
//

#include "font.h"

namespace DreamEngine {
    FontRepresentable::FontRepresentable(std::string filepath) : filepath(std::move(filepath)) { omitted }

    FontRepresentable::~FontRepresentable() {
        for (const std::pair<const float, TTF_Font*>& pair : fontSizePool) {
            TTF_CloseFont(pair.second);
        }
        fontSizePool.clear();
    }

    TTF_Font *FontRepresentable::getSizedFont(const float fontSize) {
        using ConstIterator = const std::unordered_map<float, TTF_Font*>::iterator;

        // Check if the font is already loaded in the pool
        ConstIterator iterator = fontSizePool.find(fontSize);
        if (iterator != fontSizePool.end()) return iterator->second;

        // If not found, load it and insert into the pool
        TTF_Font* font = TTF_OpenFont(filepath.c_str(), fontSize);
        fontSizePool[fontSize] = font;
        return font;
    }
}
