//
// Created by fanboyan on 2025/6/2.
//

#include "resource.h"

namespace DreamEngine {
    ResourceManager::ResourceManager() {
        // Register the loader for image files (with '.png' extension)
        registerLoader(DREAM_ENGINE_PNG_EXTENSION, [&](SDL_Renderer* renderer, const std::filesystem::path& path) -> void {
            SDL_Texture* texture = IMG_LoadTexture(renderer, path.u8string().c_str());
            SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
            if (texture) texturePool[path.stem().u8string()] = texture;
        });

        // Register the loader for audio files (with '.mp3' extension)
        registerLoader(DREAM_ENGINE_MP3_EXTENSION, [&](SDL_Renderer*, const std::filesystem::path& path) -> void {
            Mix_Chunk* audio = Mix_LoadWAV(path.u8string().c_str());
            if (audio) audioPool[path.stem().u8string()] = audio;
        });

        // Register the loader for font files (with '.ttf' extension)
        registerLoader(DREAM_ENGINE_TTF_EXTENSION, [&](SDL_Renderer*, const std::filesystem::path& path) -> void {
            FontRepresentable* font = new FontRepresentable(path.u8string());
            fontPool[path.stem().u8string()] = font;
        });

        // Register the loader for video files (with '.mp4' extension)
        registerLoader(DREAM_ENGINE_MP4_EXTENSION, [&](SDL_Renderer*, const std::filesystem::path& path) -> void {
            VideoRepresentable* video = new VideoRepresentable(path.u8string());
            videoPool[path.stem().u8string()] = video;
        });
    }

    ResourceManager::~ResourceManager() {
        // Destroy textures
        for (const std::pair<const std::string, SDL_Texture*>& pair : texturePool) {
            LOG_INFO(Logger::onFileUnload(self, pair.first));
            SDL_DestroyTexture(pair.second);
        }
        texturePool.clear();

        // Free audio chunks
        for (const std::pair<const std::string, Mix_Chunk*>& pair : audioPool) {
            LOG_INFO(Logger::onFileUnload(self, pair.first));
            Mix_FreeChunk(pair.second);
        }
        audioPool.clear();

        // Close fonts
        for (const std::pair<const std::string, FontRepresentable*>& pair : fontPool) {
            LOG_INFO(Logger::onFileUnload(self, pair.first));
            delete pair.second;
        }
        fontPool.clear();

        // Close videos
        for (const std::pair<const std::string, VideoRepresentable*>& pair : videoPool) {
            LOG_INFO(Logger::onFileUnload(self, pair.first));
            delete pair.second;
        }
        videoPool.clear();

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
                using ConstIterator = const std::unordered_map<std::string, ResourceLoader>::const_iterator;

                // Try to find the `ResourceLoader` registered for the current iterating file
                const std::filesystem::path& path = entry.path();
                ConstIterator iterator = resourceLoaders.find(path.extension().u8string());

                // Load the resource if its `ResourceLoader` is found
                if (iterator != resourceLoaders.end()) iterator->second(renderer, path);
            }

            else LOG_ERROR(Logger::onFileLoad(self, entry.path().u8string(), LOG_FAILURE));
        }
    }

    SDL_Texture* ResourceManager::getTexture(const std::string &textureName) const {
        using ConstIterator = const std::unordered_map<std::string, SDL_Texture*>::const_iterator;

        // Try to use const methods to find the texture
        ConstIterator iterator = texturePool.find(textureName);

        // Return texture or a nullptr if nothing is found
        if (iterator != texturePool.end()) return iterator->second;

        LOG_ERROR(Logger::onFileLoad(self, textureName, LOG_FAILURE));
        return nullptr;
    }

    Mix_Chunk* ResourceManager::getAudio(const std::string &audioName) const {
        using ConstIterator = std::unordered_map<std::string, Mix_Chunk*>::const_iterator;

        // Try to use const methods to find the audio
        const ConstIterator iterator = audioPool.find(audioName);

        // Return audio or a nullptr if nothing is found
        if (iterator != audioPool.end()) return iterator->second;

        LOG_ERROR(Logger::onFileLoad(self, audioName, LOG_FAILURE));
        return nullptr;
    }

    FontRepresentable* ResourceManager::getFont(const std::string &fontName) const {
        using ConstIterator = const std::unordered_map<std::string, FontRepresentable*>::const_iterator;

        // Try to use const methods to find the font
        ConstIterator iterator = fontPool.find(fontName);

        // Return font or a nullptr if nothing is found
        if (iterator != fontPool.end()) return iterator->second;

        LOG_ERROR(Logger::onFileLoad(self, fontName, LOG_FAILURE));
        return nullptr;
    }

    VideoRepresentable* ResourceManager::getVideo(const std::string &videoName) const {
        using ConstIterator = const std::unordered_map<std::string, VideoRepresentable*>::const_iterator;

        // Try to use const methods to find the video
        ConstIterator iterator = videoPool.find(videoName);

        // Return video or a nullptr if nothing is found
        if (iterator != videoPool.end()) return iterator->second;

        LOG_ERROR(Logger::onFileLoad(self, videoName, LOG_FAILURE));
        return nullptr;
    }

    bool ResourceManager::generateResourceManifest(const std::filesystem::path &directory, const std::filesystem::path &path) {
        std::error_code errorCode;
        if (!std::filesystem::exists(directory, errorCode) || errorCode) return false;

        std::ofstream stream(path, std::ios::trunc);
        if (!stream.is_open()) return false;

        for (const auto& entry : std::filesystem::recursive_directory_iterator(directory, errorCode)) {
            if (errorCode) return false;
            if (!entry.is_regular_file(errorCode) || errorCode) continue;

            const std::filesystem::path& absolutePath = entry.path();
            if (std::filesystem::equivalent(absolutePath, path, errorCode) && !errorCode) continue;

            const uintmax_t sizeBytes = entry.file_size(errorCode);
            if (errorCode) return false;

            const std::string relativeKey = toRelativeKey(absolutePath, directory);
            const std::string hashing = computeSHA256(absolutePath);
            if (hashing.empty()) return false;

            stream << hashing << " " << sizeBytes << " " << relativeKey << "\n";
        }

        return true;
    }

    std::string ResourceManager::toRelativeKey(const std::filesystem::path &absolutePath, const std::filesystem::path &rootDirectory) {
        return std::filesystem::relative(absolutePath, rootDirectory).generic_string();
    }

    std::string ResourceManager::computeSHA256(const std::filesystem::path &filePath) {
        std::ifstream in(filePath, std::ios::binary);
        if (!in.is_open()) return std::string();

        EVP_MD_CTX* context = EVP_MD_CTX_new();
        if (!context) return std::string();

        const EVP_MD* hasher = EVP_sha256();
        if (!hasher) {
            EVP_MD_CTX_free(context);
            return std::string();
        }

        if (EVP_DigestInit_ex(context, hasher, nullptr) != 1) {
            EVP_MD_CTX_free(context);
            return std::string();
        }

        std::vector<unsigned char> buffer(1024 * 1024);

        while (in.good()) {
            in.read(reinterpret_cast<char*>(buffer.data()), static_cast<std::streamsize>(buffer.size()));
            std::streamsize count = in.gcount();

            if (count > 0) {
                if (EVP_DigestUpdate(context, buffer.data(), static_cast<size_t>(count)) != 1) {
                    EVP_MD_CTX_free(context);
                    return std::string();
                }
            }
        }

        unsigned char digest[EVP_MAX_MD_SIZE];
        unsigned int digestLength = 0;

        if (EVP_DigestFinal_ex(context, digest, &digestLength) != 1) {
            EVP_MD_CTX_free(context);
            return std::string();
        }

        EVP_MD_CTX_free(context);

        std::ostringstream stream;
        stream << std::hex << std::setfill('0');
        for (unsigned int i = 0; i < digestLength; ++i) stream << std::setw(2) << static_cast<int>(digest[i]);

        return stream.str();
    }
}
