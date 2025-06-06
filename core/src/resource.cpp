//
// Created by fanboyan on 2025/6/2.
//

#include "resource.h"

namespace DreamEngine {
    ResourceManager::ResourceManager() {
        // Register loading method for image files (with '.png' extension)
        registerLoader(".png", [&](SDL_Renderer* renderer, const std::filesystem::path& path) -> void {
            SDL_Texture* texture = IMG_LoadTexture(renderer, path.u8string().c_str());
            if (texture) texturePool[path.stem().u8string()] = texture;
        });

        // Register loading method for audio files (with '.mp3' extension)
        registerLoader(".mp3", [&](SDL_Renderer* renderer, const std::filesystem::path& path) -> void {
            Mix_Chunk* audio = Mix_LoadWAV(path.u8string().c_str());
            if (audio) audioPool[path.stem().u8string()] = audio;
        });
    }

    ResourceManager::~ResourceManager() {
        // Destroy textures
        for (std::pair<const std::string, SDL_Texture*>& pair : texturePool) { SDL_DestroyTexture(pair.second); }
        texturePool.clear();

        // Free audio chunks
        for (std::pair<const std::string, Mix_Chunk*>& pair : audioPool) { Mix_FreeChunk(pair.second); }
        audioPool.clear();

        // Clear registered loader mappings and generic resources
        resourceLoaders.clear();
    }

    void ResourceManager::registerLoader(const std::string &extension, const ResourceManager::Loader& loader) {
        // Register the specific `Loader` for the given extension
        resourceLoaders[extension] = loader;
    }

    void ResourceManager::loadFromDirectory(SDL_Renderer* renderer, const std::string &directory) {
        // Iterate over each regular file in the given directory
        for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(directory)) {
            if (entry.is_regular_file()) {
                using ConstIterator = std::unordered_map<std::string, ResourceManager::Loader>::const_iterator;

                // Try to find the `Loader` registered for the current iterating file
                const std::filesystem::path& path = entry.path();
                ConstIterator iterator = resourceLoaders.find(path.extension().u8string());

                // Load resource if its `Loader` is found
                if (iterator != resourceLoaders.end()) iterator->second(renderer, path);
            }
        }
    }

    SDL_Texture* ResourceManager::getTexture(const std::string &textureName) const {
        using ConstIterator = std::unordered_map<std::string, SDL_Texture*>::const_iterator;

        // Try to use const methods to find the texture
        ConstIterator iterator = texturePool.find(textureName);

        // Return texture or a nullptr if nothing is found
        if (iterator != texturePool.end()) return iterator->second;
        return nullptr;
    }

    Mix_Chunk* ResourceManager::getAudio(const std::string &audioName) const {
        using ConstIterator = std::unordered_map<std::string, Mix_Chunk*>::const_iterator;

        // Try to use const methods to find the audio
        ConstIterator iterator = audioPool.find(audioName);

        // Return audio or a nullptr if nothing is found
        if (iterator != audioPool.end()) return iterator->second;
        return nullptr;
    }
}
