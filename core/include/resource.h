//
// Created by fanboyan on 2025/6/2.
//

#ifndef DREAM_ENGINE_RESOURCE_H
#define DREAM_ENGINE_RESOURCE_H

#include "singleton.h"
#include "font.h"
#include "symbols.h"
#include "video.h"
#include "logger.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <unordered_map>
#include <string>
#include <filesystem>
#include <functional>

namespace DreamEngine {
    /// ResourceManager is a singleton class responsible for loading image and audio files from a given directory
    /// and storing them for efficient reuse during runtime.
    ///
    class ResourceManager final : public Singleton<ResourceManager> { friend class Singleton<ResourceManager>;
        /// Type alias for specific resource loading methods
        using ResourceLoader = std::function<void(SDL_Renderer* renderer, const std::filesystem::path& path)>;

        /// Class Name for reflection implementation.
        public: static inline std::string self = RESOURCE_MANAGER_TYPE;

        /// Pool of loaded textures, keyed by the base filename.
        private: std::unordered_map<std::string, SDL_Texture*> texturePool;

        /// Pool of loaded audio chunks, keyed by base filename.
        private: std::unordered_map<std::string, Mix_Chunk*> audioPool;

        /// Pool of loaded fonts, keyed by the base font name.
        private: std::unordered_map<std::string, FontRepresentable*> fontPool;

        /// Pool of loaded videos, keyed by the base filename.
        private: std::unordered_map<std::string, VideoRepresentable*> videoPool;

        /// The collection of loaders specified for different types of resources.
        private: std::unordered_map<std::string, ResourceLoader> resourceLoaders;

        /// Private constructor to enforce the singleton pattern.
        private: ResourceManager();

        /// Private destructor.
        private: ~ResourceManager() override;

        /// Registers a resource loading function for a specific file extension. This allows developers to extend
        /// the ResourceManager with support for additional resource types.
        ///
        /// @param extension File extension to register the loader for (including the dot, e.g., ".png").
        /// @param resourceLoader A function that takes an SDL_Renderer pointer and a file path and performs custom
        ///               loading logic for that file type. It should insert loaded resources
        ///               into the appropriate internal pool.
        ///
        private: void registerLoader(const std::string& extension, const ResourceLoader& resourceLoader);

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

        /// Retrieves a loaded font by name.
        ///
        /// @param fontName Base font name (without extension) of the font.
        /// @return Font* pointer if found, nullptr otherwise.
        ///
        public: FontRepresentable* getFont(const std::string& fontName) const;

        /// Retrieves a loaded video by name.
        ///
        /// @param videoName Base video name (without extension) of the video.
        /// @return VideoRepresentable* pointer if found, nullptr otherwise.
        ///
        public: VideoRepresentable* getVideo(const std::string& videoName) const;
    };
}

#endif //DREAM_ENGINE_RESOURCE_H
