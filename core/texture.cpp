//
// Created by fanboyan on 2025/6/23.
//

#include "texture.h"

namespace DreamEngine {
    TextureRepresentable::TextureRepresentable(SDL_Texture* texture, const SDL_FRect source) : texture(texture), source(source) { omitted }

    TextureSequence::TextureSequence(SDL_Texture* textureSheet, const float textureWidth, const float textureHeight) : textureSheet(textureSheet) {

        float sheetWidth = NONE, sheetHeight = NONE;
        if (!SDL_GetTextureSize(textureSheet, &sheetWidth, &sheetHeight)) {
            std::ostringstream buffer;
            buffer << Logger::getMessageModule(self) << "failed to get texture size for texture.";
            LOG_ERROR(buffer.str());
        }

        const int numberOfColumns = static_cast<int>(sheetWidth / textureWidth);
        const int numberOfRows = static_cast<int>(sheetHeight / textureHeight);

        for (int row = 0; row < numberOfRows; row++) {
            for (int column = 0; column < numberOfColumns; column++) {
                sourceCollection.emplace_back<SDL_FRect>({
                    static_cast<float>(column) * textureWidth, static_cast<float>(row) * textureHeight, textureWidth, textureHeight
                });
            }
        }
    }

    TextureSequence::~TextureSequence() { sourceCollection.clear(); }

    TextureRepresentable TextureSequence::getTexture(const size_t index) const {
        if (index < sourceCollection.size()) return TextureRepresentable(textureSheet, sourceCollection[index]);
        LOG_ERROR(Logger::onOutOfBounds(self, index));
        return TextureRepresentable(nullptr, SDL_FRect{});
    }

    size_t TextureSequence::getSize() const { return sourceCollection.size(); }
}