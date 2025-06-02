//
// Created by fanboyan on 2025/6/2.
//

#include "resource.h"

namespace DreamEngine {
    ResourceManager* ResourceManager::resourceManager = nullptr;

    ResourceManager::ResourceManager() = default;

    ResourceManager::~ResourceManager() = default;

    ResourceManager* ResourceManager::getInstance() {
        if (!resourceManager) resourceManager = new ResourceManager();
        return resourceManager;
    }

    SDL_Texture *ResourceManager::getTexture(const std::string &textureName) { return texturePool[textureName]; }

    Mix_Chunk *ResourceManager::getAudio(const std::string &audioName) { return audioPool[audioName]; }

    void ResourceManager::loadFromDirectory(SDL_Renderer *renderer, const std::string &directory) {
        // Iterate over each regular file in the given directory
        for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(directory)) {
            if (entry.is_regular_file()) {
                const std::filesystem::path& path = entry.path();

                // Load image files (with '.png' extension) as SDL_Textures
                if (path.extension() == ".png") {
                    SDL_Texture* texture = IMG_LoadTexture(renderer, path.u8string().c_str());
                    texturePool[path.stem().u8string()] = texture;
                }

                    // Load audio files as (with '.mp3' extension) Mix_Chunk audio
                else if (path.extension() == ".mp3") {
                    Mix_Chunk* audio = Mix_LoadWAV(path.u8string().c_str());
                    audioPool[path.stem().u8string()] = audio;
                }
            }
        }
    }
}
