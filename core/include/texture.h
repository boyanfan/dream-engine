//
// Created by fanboyan on 2025/5/24.
//

#ifndef DREAM_ENGINE_TEXTURE_H
#define DREAM_ENGINE_TEXTURE_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <vector>
#include <string>

namespace DreamEngine {
    /// Manages a sequence of SDL_Textures for rendering animations or image sequences.
    class TextureSequence {
        /// Constructs an empty TextureSequence.
        public: TextureSequence();

        /// Constructs a TextureSequence with pre-allocated capacity.
        /// @param size The number of textures to pre-allocate space for.
        ///
        public: explicit TextureSequence(size_t size);

        /// Destroys the TextureSequence and deallocates all textures.
        public: ~TextureSequence();

        /// Stores the sequence of SDL_Texture pointers.
        private: std::vector<SDL_Texture*> textureSequence;

        /// Loads a sequence of textures using a formatted path template.
        ///
        /// @param renderer The SDL_Renderer used to create textures.
        /// @param pathTemplate A C-style formatted string with a printf-style format.
        /// @param size The number of textures to load.
        ///
        public: void loadSequence(SDL_Renderer* renderer, const char* pathTemplate, size_t size);

        /// Clears the texture sequence. Does not destroy textures.
        public: void clearSequence();

        /// Get the number of textures currently in the sequence.
        /// @return The size of the texture sequence.
        ///
        public: size_t getSequenceSize();

        /// Retrieves a texture by its index.
        ///
        /// @param index The index of the texture in the sequence.
        /// @return The SDL_Texture* at the given index, or nullptr if the index is out of bounds.
        ///
        public: SDL_Texture* getTextureByIndex(int index);

        /// Adds a texture to the sequence.
        /// @param texture A pointer to the SDL_Texture to be added.
        ///
        public: void addTexture(SDL_Texture *texture);

        /// Access texture by index (non-const).
        ///
        /// @param index Index into the texture sequence.
        /// @return Reference to SDL_Texture* at index.
        ///
        SDL_Texture*& operator [](size_t index);

        /// Access texture by index (const).
        ///
        /// @param index Index into the texture sequence.
        /// @return Const reference to SDL_Texture* at index.
        ///
        const SDL_Texture* operator [](size_t index) const;
    };
}

#endif //DREAM_ENGINE_TEXTURE_H
