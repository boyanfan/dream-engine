//
// Created by fanboyan on 2025/6/25.
//

#ifndef DREAM_ENGINE_LOGO_H
#define DREAM_ENGINE_LOGO_H

#include "scene.h"
#include "geometry.h"
#include "resource.h"

#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>

namespace DreamEngine {
    /// A scene that presents the opening logo and sound of the game when the application starts.
    /// This scene plays a video and sound effect once and then transitions to the next scene.
    ///
    class OpeningPresentation final : public Scene {
        /// Pointer to the video decoder responsible for rendering the opening logo.
        private: const VideoDecoder* openingLogo = nullptr;

        /// Pointer to the audio chunk for the opening sound.
        private: Mix_Chunk* openingSound = nullptr;

        /// The audio channel used to play the opening sound.
        private: int openingSoundChannel = FIRST_FREE_CHANNEL;

        /// Constructs the opening scene using the given camera and window geometry.
        /// @param camera The camera used to render the video.
        /// @param geometry The window geometry for initializing the video decoder.
        ///
        public: OpeningPresentation(const Camera* camera, const GeometryProxy& geometry);

        /// Destructor override for cleanup.
        public: ~OpeningPresentation() override = default;

        /// Called when the scene is entered. Starts playing the sound.
        public: void onEntry() override;

        /// Handles input events during the opening presentation.
        /// @param event SDL input event.
        ///
        public: void onEvent(const SDL_Event& event) override;

        /// Updates the state of the presentation.
        /// @param interval Time has elapsed since the last frame.
        ///
        public: void onUpdate(float interval) override;

        /// Renders the current frame of the opening video.
        /// @param camera The rendering camera context.
        ///
        public: void onRender(const Camera& camera) const override;

        /// Called when the scene is exited.
        public: void onExit() override;
    };
}

#endif //DREAM_ENGINE_LOGO_H
