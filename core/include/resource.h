//
// Created by fanboyan on 2025/6/2.
//

#ifndef DREAM_ENGINE_RESOURCE_H
#define DREAM_ENGINE_RESOURCE_H

#include "singleton.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <unordered_map>
#include <string>
#include <filesystem>
#include <functional>

namespace DreamEngine {
    /// ResourceManager is a singleton class responsible for loading image and audio files from a given directory
    /// and storing them for efficient reuse during runtime. It supports `.png` images and `.mp3` audio files.
    ///
    class ResourceManager final : public Singleton<ResourceManager> { friend class Singleton<ResourceManager>;
        using AnyRenderable = std::shared_ptr<void>;
        using Loader = std::function<void(SDL_Renderer* renderer, const std::filesystem::path& path)>;

        /// Private constructor to enforce singleton pattern.
        private: ResourceManager();

        /// Private destructor.
        private: ~ResourceManager() override;

        /// Pool of loaded textures, keyed by base filename.
        private: std::unordered_map<std::string, SDL_Texture*> texturePool;

        /// Pool of loaded audio chunks, keyed by base filename.
        private: std::unordered_map<std::string, Mix_Chunk*> audioPool;

        /// Pool of generic user-defined resources, keyed by base filename to support arbitrary types.
        public: std::unordered_map<std::string, AnyRenderable> genericPool;

        /// The collection of loaders specified for different types of resources.
        private: std::unordered_map<std::string, Loader> resourceLoaders;

        /// Registers a resource loading function for a specific file extension. This allows developers to extend
        /// the ResourceManager with support for additional resource types.
        ///
        /// @param extension File extension to register the loader for (including the dot, e.g., ".png").
        /// @param loader A function that takes an SDL_Renderer pointer and a file path, and performs custom
        ///               loading logic for that file type. It should insert loaded resources
        ///               into the appropriate internal pool.
        ///
        public: void registerLoader(const std::string& extension, const Loader& loader);

        /// Loads all files in the specified directory using the registered loaders.
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
        public: SDL_Texture* getTexture(const std::string& textureName) const;

        /// Retrieves a loaded audio chunk by name.
        ///
        /// @param audioName Base filename (without extension) of the audio.
        /// @return Mix_Chunk* pointer if found, nullptr otherwise.
        ///
        public: Mix_Chunk* getAudio(const std::string& audioName) const;

        /// Retrieves a generic resource by name and type.
        ///
        /// @tparam T Expected type of the resource.
        /// @param name Resource name, the base filename without extension.
        /// @return `std::shared_ptr<T>` to the resource, or `nullptr` if not found or type mismatch.
        ///
        public: template<typename T> std::shared_ptr<T> getGeneric(const std::string& name) const;
    };
}

#endif //DREAM_ENGINE_RESOURCE_H
