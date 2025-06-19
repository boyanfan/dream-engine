// video.h
// Created by fanboyan on 2025/6/18.

#ifndef DREAM_ENGINE_VIDEO_H
#define DREAM_ENGINE_VIDEO_H

#include "logger.h"
#include <string>
#include <SDL3/SDL.h>

#include "renderable.h"

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
        private: SDL_Texture* texture = nullptr;

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

        /// Frame for holding raw video data directly from decoder.
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
        private: Uint64 startTicks = 0;

        /// Internal buffer for the converted color space frame data.
        private: uint8_t* colorSpaceBuffer = nullptr;

        /// Indicates whether the video has finished playing.
        public: bool hasFinished  = false;

        /// Constructs a new `VideoDecoder`.
        ///
        /// @param filepath The path to the video file.
        /// @param windowWidth The width of the target rendering window.
        /// @param windowHeight The height of the target rendering window.
        ///
        public: VideoDecoder(const std::string& filepath, int windowWidth, int windowHeight);

        /// Destructor. Cleans up all FFmpeg and SDL resources used during decoding.
        public: ~VideoDecoder() override;

        /// Renders the next frame of the video to the given SDL renderer. This method decodes the next frame if the
        /// time has come, performs scaling and pixel format conversion, and then copies it to the SDL renderer.
        ///
        /// @param renderer Pointer to the SDL renderer to draw onto.
        ///
        void onRender(SDL_Renderer* renderer) override;

        /// Initializes all FFmpeg contexts and prepares for decoding. This method opens the video file, locates the
        /// video stream, and sets up the codec, scaling context, and frame buffers.
        ///
        /// @param filepath The path to the video file.
        /// @return `true` if initialization was successful; `false` otherwise.
        ///
        private: bool initialize(const std::string& filepath);
    };
}

#endif // DREAM_ENGINE_VIDEO_H
