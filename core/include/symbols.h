//
// Created by fanboyan on 2025/6/11.
//

#ifndef DREAM_ENGINE_SYMBOLS_H
#define DREAM_ENGINE_SYMBOLS_H

// DreamEngine Type system for Reflection
#define APPLICATION_TYPE "DreamEngine::Application"
#define WINDOW_CONFIGURATION_TYPE "DreamEngine::WindowConfiguration"
#define RESOURCE_MANAGER_TYPE "DreamEngine::ResourceManager"
#define VIDEO_DECODER_TYPE "DreamEngine::VideoDecoder"
#define GEOMETRY_PROXY_TYPE "DreamEngine::GeometryProxy"
#define SDL_TYPE "SDL"
#define SDL_WINDOW_TYPE "SDL::Window"
#define SDL_RENDERER_TYPE "SDL::Renderer"
#define SDL_MIXER_TYPE "SDL::Mixer"
#define SDL_TTF_TYPE "SDL::TTF"

// DreamEngine::Camera Utility
#define CAMERA_DEFAULT_FACTOR 1.0f

// Window Utility
#define NANOSECONDS_PER_SECOND 1000000000
#define DEFAULT_WINDOW_WIDTH 1280
#define DEFAULT_WINDOW_HEIGHT 720
#define DEFAULT_WINDOW_TITLE "Hello DreamEngine!"
#define DEFAULT_WINDOW_FRAME_RATE 60
#define WINDOW_CONFIGURATION_SEPARATOR '='
#define WINDOW_CONFIGURATION_TITLE_KEY "title"
#define WINDOW_CONFIGURATION_WIDTH_KEY "width"
#define WINDOW_CONFIGURATION_HEIGHT_KEY "height"
#define WINDOW_CONFIGURATION_FRAME_RATE_KEY "frameRate"

// DreamEngine::Logger Utility
#define LOG_STYLE_PLAIN "\033[0m"
#define LOG_STYLE_BOLD_RED   "\033[31m\033[1m"
#define LOG_STYLE_BOLD_GREEN "\033[32m\033[1m"
#define LOG_STYLE_BOLD_YELLOW "\033[33m\033[1m"
#define LOG_STYLE_BOLD_GREY "\033[37m\033[1m"
#define LOG_STYLE_MAGENTA "\033[35m"
#define LOG_STYLE_BLUE "\033[34m"
#define LOG_STYLE_CYAN "\033[36m"

#define LOG_SUCCESS true
#define LOG_FAILURE false

#ifdef DEBUG
#define LOG_INFO(message) Logger::getInstance()->log(LogScope::Info, message)
#define LOG_WARNING(message) Logger::getInstance()->log(LogScope::Warning, message)
#define LOG_ERROR(message) Logger::getInstance()->log(LogScope::Error, message)
#else
#define LOG_INFO(message)    ((void)0)
#define LOG_WARNING(message) ((void)0)
#define LOG_ERROR(message)   ((void)0)
#endif

// DreamEngine Utility
#define NONE 0
#define DREAM_ENGINE_OPENING_RESOURCES "resources"
#define DREAM_ENGINE_OPENING_LOGO "engine-logo-video"
#define DREAM_ENGINE_OPENING_SOUND "engine-logo-audio"
#define FIRST_FREE_CHANNEL (-1)

// DreamEngine::ResourceManager Utility
#define DREAM_ENGINE_PNG_EXTENSION ".png"
#define DREAM_ENGINE_MP3_EXTENSION ".mp3"
#define DREAM_ENGINE_MP4_EXTENSION ".mp4"
#define DREAM_ENGINE_TTF_EXTENSION ".ttf"

#endif //DREAM_ENGINE_SYMBOLS_H
