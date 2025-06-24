//
// Created by fanboyan on 2025/6/23.
//

#ifndef DREAM_ENGINE_TEXTURE_H
#define DREAM_ENGINE_TEXTURE_H

#include "symbols.h"
#include "logger.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <vector>

namespace DreamEngine {
    /// A lightweight struct representing a texture region that can be rendered. It contains a pointer to the SDL texture
    /// sheet and a source rectangle specifying the portion of the texture to be used.
    ///
    struct TextureRepresentable {
        /// Pointer to the shared original SDL texture resource.
        public: SDL_Texture* texture = nullptr;

        /// The source rectangle within the texture sheet to render.
        public: SDL_FRect source;

        /// Constructs a `TextureRepresentable` using the given texture and source rectangle.
        /// @param texture A pointer to the SDL texture sheet.
        /// @param source The portion of the texture to represent.
        ///
        public: TextureRepresentable(SDL_Texture* texture, SDL_FRect source);

        /// Default destructor.
        public: ~TextureRepresentable() = default;
    };

    /**
     *
     */
    struct TextureSequence {
        /// Class Name for reflection implementation.
        public: static inline std::string self = TEXTURE_SEQUENCE_TYPE;

        /// Pointer to the shared SDL texture sheet containing all regions.
        private: SDL_Texture* textureSheet = nullptr;

        /// A collection of source rectangles defining individual regions within the texture.
        private: std::vector<SDL_FRect> sourceCollection;

        /// Width and height of a single region within the texture sheet.
        private: float textureWidth = NONE, textureHeight = NONE;

        /// Constructs a `TextureSequence` from a texture sheet and dimensions of each region.
        /// @param textureSheet The shared SDL texture containing multiple regions.
        /// @param textureWidth The width of each region in the texture.
        /// @param textureHeight The height of each region in the texture.
        ///
        public: TextureSequence(SDL_Texture* textureSheet, float textureWidth, float textureHeight);

        /// Destruct the TextureSequence by clearing the sourceCollection.
        public: ~TextureSequence();

        /// Retrieves a `TextureRepresentable` for the specified region index.
        /// @param index The index of the region to retrieve.
        /// @return A `TextureRepresentable` containing the shared texture and its region.
        ///
        public: TextureRepresentable getTexture(int index) const;

        /// Returns the number of available regions in the sequence.
        /// @return The size of the source collection.
        ///
        public: size_t getSize() const;
    };
}

#endif //DREAM_ENGINE_TEXTURE_H
