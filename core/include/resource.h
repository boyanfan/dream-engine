//
// Created by fanboyan on 2025/6/2.
//

#ifndef DREAM_ENGINE_RESOURCE_H
#define DREAM_ENGINE_RESOURCE_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <unordered_map>
#include <string>
#include <filesystem>

namespace DreamEngine {
    /// ResourceManager is a singleton class responsible for loading image and audio files from a given directory
    /// and storing them for efficient reuse during runtime. It supports `.png` images and `.mp3` audio files.
    ///
    class ResourceManager {
        /// Private constructor to enforce singleton pattern.
        private: ResourceManager();

        /// Private destructor.
        private: ~ResourceManager();

        /// Singleton instance pointer.
        private: static ResourceManager* resourceManager;

        /// Pool of loaded textures, keyed by base filename.
        private: std::unordered_map<std::string, SDL_Texture*> texturePool;

        ///  Pool of loaded audio chunks, keyed by base filename.
        private: std::unordered_map<std::string, Mix_Chunk*> audioPool;

        /// Returns the singleton instance of ResourceManager.
        /// @return Pointer to the shared ResourceManager instance.
        ///
        public: static ResourceManager* getInstance();

        /// Loads all `.png` and `.mp3` files from a directory.
        ///
        /// @param renderer SDL_Renderer used to create textures.
        /// @param directory Path to the directory containing resource files.
        ///
        public: void loadFromDirectory(SDL_Renderer* renderer, const std::string& directory);

        /// Retrieves a loaded texture by name.
        ///
        /// @param textureName Base filename (without extension) of the texture.
        /// @return SDL_Texture* pointer if found, nullptr otherwise.
        ///
        public: SDL_Texture* getTexture(const std::string& textureName);

        /// Retrieves a loaded audio chunk by name.
        ///
        /// @param audioName Base filename (without extension) of the audio.
        /// @return Mix_Chunk* pointer if found, nullptr otherwise.
        ///
        public: Mix_Chunk* getAudio(const std::string& audioName);
    };
}

#endif //DREAM_ENGINE_RESOURCE_H
