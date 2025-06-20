// video.h
// Created by fanboyan on 2025/6/18.

#ifndef DREAM_ENGINE_VIDEO_H
#define DREAM_ENGINE_VIDEO_H

#include "logger.h"
#include "renderable.h"
#include "geometry.h"
#include <string>
#include <SDL3/SDL.h>

extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavcodec/packet.h>
#include <libavutil/frame.h>
#include <libavutil/imgutils.h>
#include <libswscale/swscale.h>
}

namespace DreamEngine {
    /// A video decoder that plays a video file frame-by-frame using FFmpeg and SDL.
    ///
    /// It loads and decodes a video file and renders it to an SDL renderer, handles the necessary initialization of
    /// FFmpeg components, manages scaling to the game window resolution, and converts each frame to an SDL texture
    /// for real-time playback. The class is intended to be rendered once per frame in the main game loop.
    ///
    class VideoDecoder final : public Renderable {
        /// Class Name for reflection implementation.
        public: static inline std::string self = VIDEO_DECODER_TYPE;

        /// SDL texture used to render the current video frame.
        private: mutable SDL_Texture* texture = nullptr;

        /// Width of the rendering window.
        private: int windowWidth;

        /// Height of the rendering window.
        private: int windowHeight;

        /// File path of the video file to play.
        private: std::string filepath;

        /// FFmpeg format context for managing media file information.
        private: AVFormatContext* formatContext = nullptr;

        /// FFmpeg codec context for decoding video streams.
        private: AVCodecContext* videoContext = nullptr;

        /// FFmpeg software scaling context for converting pixel formats and sizes.
        private: SwsContext* scalingContext = nullptr;

        /// Frame for holding raw video data directly from the decoder.
        private: AVFrame* rawFrame = nullptr;

        /// Frame for holding converted video data in a pixel format SDL can render.
        private: AVFrame* mappedFrame = nullptr;

        /// Encapsulates encoded video data from the file stream.
        private: AVPacket* packet = nullptr;

        /// Index of the video stream inside the media file.
        private: int videoStreamIndex = -1;

        /// Time base of the video stream, used to calculate presentation timestamps.
        private: AVRational videoTimeBase{};

        /// Timestamp marking the beginning of video playback.
        private: mutable Uint64 startTicks = 0;

        /// Internal buffer for the converted color space frame data.
        private: uint8_t* colorSpaceBuffer = nullptr;

        /// Indicates whether the video has finished playing.
        public: mutable bool hasFinished  = false;

        /// Constructs a new `VideoDecoder`.
        ///
        /// @param filepath The path to the video file.
        /// @param windowWidth The width of the target rendering window.
        /// @param windowHeight The height of the target rendering window.
        ///
        public: VideoDecoder(const std::string& filepath, int windowWidth, int windowHeight);

        /// Destructor. Cleans up all FFmpeg and SDL resources used during decoding.
        public: ~VideoDecoder() override;

        /// Renders the next video frame using the provided camera.
        /// This function decodes and displays a single frame from the video stream, automatically synchronizing
        /// playback based on presentation timestamps (PTS).
        ///
        /// @param camera A reference to the Dream Engine camera used for rendering.
        ///
        void onRender(const Camera& camera) const override;

        /// Initializes all FFmpeg contexts and prepares for decoding. This method opens the video file, locates the
        /// video stream, and sets up the codec, scaling context, and frame buffers.
        ///
        /// @param filepath The path to the video file.
        /// @return `true` if initialization was successful; `false` otherwise.
        ///
        private: bool initialize(const std::string& filepath);
    };

    /// A lightweight wrapper that defers the construction of a VideoDecoder until rendering.
    /// It stores the path to a video file but does not immediately decode it. Instead, it creates the `VideoDecoder`
    /// only when rendering is about to begin, allowing the rendering window size to be provided dynamically at runtime.
    ///
    struct VideoWrapper {
        /// Path to the video file, with an extension of ".mp4".
        private: std::string filepath;

        /// Pointer to the lazily initialized `VideoDecoder`.
        private: VideoDecoder* videoDecoder = nullptr;

        /// Constructs a `VideoWrapper` with the given video file path.
        /// @param filepath The path to the video file.
        ///
        public: explicit VideoWrapper(std::string filepath);

        /// Destructor. Frees the internally managed `VideoDecoder` if created.
        public: ~VideoWrapper();

        /// Returns the internal `VideoDecoder`, initializing it if not already done.
        /// The method takes the current window geometry to create a properly scaled decoder.
        ///
        /// @param geometry The dimensions of the rendering window.
        /// @return A pointer to the lazily constructed `VideoDecoder`.
        ///
        public: VideoDecoder* getVideoDecoder(GeometryProxy geometry);
    };
}

#endif // DREAM_ENGINE_VIDEO_H
