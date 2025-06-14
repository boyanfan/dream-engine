//
// Created by fanboyan on 2025/6/2.
//

#include "resource.h"

namespace DreamEngine {
    ResourceManager::ResourceManager() {
        // Register the loader for image files (with '.png' extension)
        registerLoader(".png", [&](SDL_Renderer* renderer, const std::filesystem::path& path) -> void {
            SDL_Texture* texture = IMG_LoadTexture(renderer, path.u8string().c_str());
            if (texture) texturePool[path.stem().u8string()] = texture;
        });

        // Register the loader for audio files (with '.mp3' extension)
        registerLoader(".mp3", [&](SDL_Renderer*, const std::filesystem::path& path) -> void {
            Mix_Chunk* audio = Mix_LoadWAV(path.u8string().c_str());
            if (audio) audioPool[path.stem().u8string()] = audio;
        });

        // Register the loader for font files (with '.mp3' extension)
        registerLoader(".ttf", [&](SDL_Renderer*, const std::filesystem::path& path) -> void {
            Font* font = new Font(path.u8string());
            fontPool[path.stem().u8string()] = font;
        });
    }

    ResourceManager::~ResourceManager() {
        // Destroy textures
        for (const std::pair<const std::string, SDL_Texture*>& pair : texturePool) { SDL_DestroyTexture(pair.second); }
        texturePool.clear();

        // Free audio chunks
        for (const std::pair<const std::string, Mix_Chunk*>& pair : audioPool) { Mix_FreeChunk(pair.second); }
        audioPool.clear();

        // Close fonts
        for (const std::pair<const std::string, Font*>& pair : fontPool) { delete pair.second; }
        fontPool.clear();

        // Clear registered loader mappings and generic resources
        resourceLoaders.clear();
    }

    void ResourceManager::registerLoader(const std::string &extension, const ResourceLoader& resourceLoader) {
        // Register the specific `ResourceLoader` for the given extension
        resourceLoaders[extension] = resourceLoader;
    }

    void ResourceManager::loadFromDirectory(SDL_Renderer* renderer, const std::string& directory) {
        // Iterate over each regular file in the given directory
        for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(directory)) {
            if (entry.is_regular_file()) {
                using ConstIterator = std::unordered_map<std::string, ResourceLoader>::const_iterator;

                // Try to find the `ResourceLoader` registered for the current iterating file
                const std::filesystem::path& path = entry.path();
                ConstIterator iterator = resourceLoaders.find(path.extension().u8string());

                // Load the resource if its `ResourceLoader` is found
                if (iterator != resourceLoaders.end()) iterator->second(renderer, path);
            }
        }
    }

    SDL_Texture* ResourceManager::getTexture(const std::string &textureName) const {
        using ConstIterator = std::unordered_map<std::string, SDL_Texture*>::const_iterator;

        // Try to use const methods to find the texture
        const ConstIterator iterator = texturePool.find(textureName);

        // Return texture or a nullptr if nothing is found
        if (iterator != texturePool.end()) return iterator->second;
        return nullptr;
    }

    Mix_Chunk* ResourceManager::getAudio(const std::string &audioName) const {
        using ConstIterator = std::unordered_map<std::string, Mix_Chunk*>::const_iterator;

        // Try to use const methods to find the audio
        const ConstIterator iterator = audioPool.find(audioName);

        // Return audio or a nullptr if nothing is found
        if (iterator != audioPool.end()) return iterator->second;
        return nullptr;
    }

    Font* ResourceManager::getFont(const std::string &fontName) const {
        using ConstIterator = std::unordered_map<std::string, Font*>::const_iterator;

        // Try to use const methods to find the font
        const ConstIterator iterator = fontPool.find(fontName);

        // Return font or a nullptr if nothing is found
        if (iterator != fontPool.end()) return iterator->second;
        return nullptr;
    }
}
