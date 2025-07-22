// video.cpp
// Created by fanboyan on 2025/6/18.

#include "../core/include/video.h"

namespace DreamEngine {
    VideoDecoder::VideoDecoder(const std::string& filepath, const int windowWidth, const int windowHeight) :
        windowWidth(windowWidth), windowHeight(windowHeight), filepath(filepath) {
        avformat_network_init();
        hasFinished = !initialize(filepath);
    }

    VideoDecoder::~VideoDecoder() {
        if (texture) SDL_DestroyTexture(texture);
        sws_freeContext(scalingContext);
        av_free(colorSpaceBuffer);
        av_frame_free(&rawFrame);
        av_frame_free(&mappedFrame);
        av_packet_free(&packet);
        avcodec_free_context(&videoContext);
        avformat_close_input(&formatContext);
        avformat_network_deinit();

        LOG_INFO(Logger::onFileUnload(VideoDecoder::self, filepath));
    }

    bool VideoDecoder::initialize(const std::string& filepath) {
        // Open container
        if (avformat_open_input(&formatContext, filepath.c_str(), nullptr, nullptr) != 0) {
            LOG_ERROR(Logger::onFileLoad(VideoDecoder::self, filepath, LOG_FAILURE));
            return false;
        }

        if (avformat_find_stream_info(formatContext, nullptr) < 0) {
            LOG_ERROR(Logger::onFileLoad(VideoDecoder::self, filepath, LOG_FAILURE));
            return false;
        }

        LOG_INFO(Logger::onFileLoad(VideoDecoder::self, filepath, LOG_SUCCESS));

        // Locate first video stream
        for (unsigned i = 0; i < formatContext->nb_streams && videoStreamIndex == -1; ++i) {
            if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) videoStreamIndex = static_cast<int>(i);
        }

        if (videoStreamIndex == -1) {
            std::ostringstream buffer;
            buffer << Logger::getMessageModule(self) << " unable to find video stream in file " << Logger::getFilepath(filepath);
            LOG_ERROR(buffer.str());
            return false;
        }

        const AVStream* videoStream = formatContext->streams[videoStreamIndex];
        const AVCodec*  videoCoder = avcodec_find_decoder(videoStream->codecpar->codec_id);

        if (!videoCoder) {
            std::ostringstream buffer;
            buffer << Logger::getMessageModule(self) << " unable to find decoder for video stream for file " << Logger::getFilepath(filepath);
            LOG_ERROR(buffer.str());
            return false;
        }

        videoContext = avcodec_alloc_context3(videoCoder);
        avcodec_parameters_to_context(videoContext, videoStream->codecpar);

        if (avcodec_open2(videoContext, videoCoder, nullptr) < 0) {
            std::ostringstream buffer;
            buffer << Logger::getMessageModule(self) << " unable to open video decoder for file " << Logger::getFilepath(filepath) << ".";
            return false;
        }

        std::ostringstream buffer;
        buffer << Logger::getMessageModule(self) << " successfully initialized the decoder for file " << Logger::getFilepath(filepath) << ".";
        LOG_INFO(buffer.str());

        videoTimeBase = videoStream->time_base;

        // Allocate frames & packet
        rawFrame = av_frame_alloc();
        mappedFrame = av_frame_alloc();
        packet = av_packet_alloc();

        // Scale
        scalingContext = sws_getContext(
            videoContext->width, videoContext->height, videoContext->pix_fmt, windowWidth, windowHeight,
            AV_PIX_FMT_RGBA, SWS_BILINEAR, nullptr, nullptr, nullptr
        );

        int bufferSize = av_image_get_buffer_size(AV_PIX_FMT_RGBA, windowWidth, windowHeight, 1);
        colorSpaceBuffer = static_cast<uint8_t*>(av_malloc(bufferSize));

        av_image_fill_arrays(
            mappedFrame->data, mappedFrame->linesize, colorSpaceBuffer, AV_PIX_FMT_RGBA, windowWidth, windowHeight, 1
        );

        return true;
    }

    void VideoDecoder::onRender(const Camera& camera) const {
        if (hasFinished) return;
        SDL_Renderer* renderer = camera.getRenderer();

        // Create texture on the first call
        if (!texture) {
            texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, windowWidth, windowHeight);
            startTicks = SDL_GetTicks();
        }

        // Read packets until we display one frame
        while (av_read_frame(formatContext, packet) >= 0) {
            if (packet->stream_index != videoStreamIndex) {
                av_packet_unref(packet);
                continue;
            }

            if (avcodec_send_packet(videoContext, packet) == 0) {
                while (avcodec_receive_frame(videoContext, rawFrame) == 0) {
                    // Convert
                    sws_scale(
                        scalingContext, rawFrame->data, rawFrame->linesize, 0, videoContext->height,
                        mappedFrame->data, mappedFrame->linesize
                    );

                    SDL_UpdateTexture(texture, nullptr, mappedFrame->data[0], mappedFrame->linesize[0]);

                    // Sync to PTS
                    const int64_t timestamp = rawFrame->best_effort_timestamp != AV_NOPTS_VALUE ? rawFrame->best_effort_timestamp : rawFrame->pts;
                    const double presentationTime = static_cast<double>(timestamp) * av_q2d(videoTimeBase);
                    const double currentTime = (static_cast<double>(SDL_GetTicks()) - static_cast<double>(startTicks)) / MILLISECONDS_PER_SECOND;
                    const double offsetTime = presentationTime - currentTime;

                    // Render
                    if (offsetTime > 0) SDL_Delay(static_cast<Uint32>(offsetTime * MILLISECONDS_PER_SECOND));
                    SDL_RenderTexture(renderer, texture, nullptr, nullptr);

                    av_packet_unref(packet);
                    return;
                }
            }
            av_packet_unref(packet);
        }
        hasFinished = true;
    }


    VideoRepresentable::VideoRepresentable(std::string filepath) : filepath(std::move(filepath)) { omitted }

    VideoRepresentable::~VideoRepresentable() { delete videoDecoder; }

    VideoDecoder *VideoRepresentable::getVideoDecoder(const GeometryProxy geometry) {
        const Vector2 windowSize = geometry.getWindowSize();
        if (!videoDecoder) videoDecoder = new VideoDecoder(filepath, static_cast<int>(windowSize.x), static_cast<int>(windowSize.y));
        return videoDecoder;
    }
}
