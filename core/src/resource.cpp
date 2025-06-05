//
// Created by fanboyan on 2025/6/2.
//

#include "resource.h"

namespace DreamEngine {
    ResourceManager::ResourceManager() = default;

    ResourceManager::~ResourceManager() {
        // Destroy textures
        for (std::pair<const std::string, SDL_Texture*>& pair : texturePool) { SDL_DestroyTexture(pair.second); }
        texturePool.clear();

        // Free audio chunks
        for (std::pair<const std::string, Mix_Chunk*>& pair : audioPool) { Mix_FreeChunk(pair.second); }
        audioPool.clear();
    }

    void ResourceManager::loadFromDirectory(SDL_Renderer *renderer, const std::string &directory) {
        // Iterate over each regular file in the given directory
        for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(directory)) {
            if (entry.is_regular_file()) {
                const std::filesystem::path& path = entry.path();

                // Load image files (with '.png' extension) as SDL_Textures
                if (path.extension() == DREAM_ENGINE_IMAGE_EXTENSION) {
                    SDL_Texture* texture = IMG_LoadTexture(renderer, path.u8string().c_str());
                    texturePool[path.stem().u8string()] = texture;
                }

                    // Load audio files as (with '.mp3' extension) Mix_Chunk audio
                else if (path.extension() == DREAM_ENGINE_AUDIO_EXTENSION) {
                    Mix_Chunk* audio = Mix_LoadWAV(path.u8string().c_str());
                    audioPool[path.stem().u8string()] = audio;
                }
            }
        }
    }

    SDL_Texture *ResourceManager::getTexture(const std::string &textureName) const {
        using ConstTextureIterator = std::unordered_map<std::string, SDL_Texture*>::const_iterator;

        // Try to use const methods to find the texture
        ConstTextureIterator iterator = texturePool.find(textureName);

        // Return texture or a nullptr if nothing is found
        if (iterator != texturePool.end()) return iterator->second;
        return nullptr;
    }

    Mix_Chunk *ResourceManager::getAudio(const std::string &audioName) const {
        using ConstAudioIterator = std::unordered_map<std::string, Mix_Chunk*>::const_iterator;

        // Try to use const methods to find the audio
        ConstAudioIterator iterator = audioPool.find(audioName);

        // Return audio or a nullptr if nothing is found
        if (iterator != audioPool.end()) return iterator->second;
        return nullptr;
    }
}
