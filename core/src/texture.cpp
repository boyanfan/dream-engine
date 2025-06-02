//
// Created by fanboyan on 2025/5/24.
//

#include "texture.h"

namespace DreamEngine {
    TextureSequence::TextureSequence() = default;

    TextureSequence::TextureSequence(size_t size)  { textureSequence.reserve(size); }

    TextureSequence::~TextureSequence() {
        for (SDL_Texture* texture : textureSequence) SDL_DestroyTexture(texture);
    }

    void TextureSequence::loadSequenceFromPath(SDL_Renderer* renderer, const char* pathTemplate, size_t size) {
        // Avoids repeated reallocation for textureSequence
        textureSequence.reserve(size);

        for (int index = 0; index < size; index++) {
            // Construct the templated file path for each of the texture source
            char filePath[128];
            snprintf(filePath, sizeof(filePath), pathTemplate, index + 1);

            // Load and add the specified texture
            SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);
            if (texture) textureSequence.push_back(texture);

            // Throw an error if unable to load the specified texture
            else SDL_Log("[ERROR]: Failed to load texture: %s, SDL Error: %s", filePath, SDL_GetError());
        }
    }

    void TextureSequence::loadSequenceFromPool(const char* nameTemplate, size_t size) {
        // Avoids repeated reallocation for textureSequence
        textureSequence.reserve(size);

        // Get ResourceManager to load textures from it
        ResourceManager* manager = ResourceManager::getInstance();

        for (int index = 0; index < size; index++) {
            // Construct the templated texture name for each of the texture source
            char textureName[128];
            snprintf(textureName, sizeof(textureName), nameTemplate, index + 1);

            // Get from the texture pool and add the specified texture
            SDL_Texture* texture = manager->getTexture(textureName);
            if (texture) textureSequence.push_back(texture);

            // Throw an error if unable to find the specified texture
            else SDL_Log("[ERROR]: Texture key not found in pool: %s", textureName);
        }
    }

    void TextureSequence::clearSequence() { textureSequence.clear(); }

    size_t TextureSequence::getSequenceSize() { return textureSequence.size(); }

    SDL_Texture* TextureSequence::getTextureByIndex(int index) {
        if (index < 0 || index >= TextureSequence::getSequenceSize()) return nullptr;
        return textureSequence[index];
    }

    void TextureSequence::addTexture(SDL_Texture *texture) { textureSequence.push_back(texture); }

    SDL_Texture*& TextureSequence::operator [](size_t index) { return textureSequence[index]; }

    const SDL_Texture* TextureSequence::operator [](size_t index) const { return textureSequence[index]; }
}
