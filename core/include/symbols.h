//
// Created by fanboyan on 2025/6/11.
//

#ifndef DREAM_ENGINE_SYMBOLS_H
#define DREAM_ENGINE_SYMBOLS_H

// Reflection
#define APPLICATION_TYPE "DreamEngine::Application"
#define WINDOW_CONFIGURATION "DreamEngine::WindowConfiguration"
#define SDL_TYPE "SDL"
#define SDL_WINDOW_TYPE "SDL::Window"
#define SDL_RENDERER_TYPE "SDL::Renderer"
#define SDL_MIXER_TYPE "SDL::Mixer"
#define SDL_TTF_TYPE "SDL::TTF"

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

// Logger Utility
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
#define LOG_INFO(message)    Logger::getInstance()->log(LogScope::Info, message)
#define LOG_WARNING(message) Logger::getInstance()->log(LogScope::Warning, message)
#define LOG_ERROR(message)   Logger::getInstance()->log(LogScope::Error, message)
#else
#define LOG_INFO(message)    ((void)0)
#define LOG_WARNING(message) ((void)0)
#define LOG_ERROR(message)   ((void)0)
#endif

// DreamEngine Utility
#define NONE 0

#endif //DREAM_ENGINE_SYMBOLS_H
