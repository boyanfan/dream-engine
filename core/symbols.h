//
// Created by fanboyan on 2025/6/11.
//

#ifndef DREAM_ENGINE_SYMBOLS_H
#define DREAM_ENGINE_SYMBOLS_H

// Dream Engine Type System
#define APPLICATION_TYPE "DreamEngine::Application"
#define WINDOW_CONFIGURATION_TYPE "DreamEngine::WindowConfiguration"
#define RESOURCE_MANAGER_TYPE "DreamEngine::ResourceManager"
#define VIDEO_DECODER_TYPE "DreamEngine::VideoDecoder"
#define GEOMETRY_PROXY_TYPE "DreamEngine::GeometryProxy"
#define TEXTURE_SEQUENCE_TYPE "DreamEngine::TextureSequence"
#define SCENE_MANAGER_TYPE "DreamEngine::SceneManager"
#define SDL_TYPE "SDL"
#define SDL_WINDOW_TYPE "SDL::Window"
#define SDL_RENDERER_TYPE "SDL::Renderer"
#define SDL_MIXER_TYPE "SDL::Mixer"
#define SDL_TTF_TYPE "SDL::TTF"
#define Identifier std::string

// Window Utility
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
#define LOG_STYLE_BOLD_RED "\033[31m\033[1m"
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
#define LOG_INFO(message) ((void)0)
#define LOG_WARNING(message) ((void)0)
#define LOG_ERROR(message) ((void)0)
#endif

// Dream Engine Keywords
#define interface class
#define delegated 0
#define omitted

// Dream Engine Utilities
#define NONE 0
#define FIRST_FREE_CHANNEL (-1)
#define ONE_SECOND 1.0f
#define MILLISECONDS_PER_SECOND 1000
#define SOLID_COLOR 255
#define HEX_REPRESENTATION_PREFIX '#'
#define DREAM_ENGINE_OPENING_RESOURCES "resources"
#define DREAM_ENGINE_OPENING_LOGO "engine-logo-video"
#define DREAM_ENGINE_OPENING_SOUND "engine-logo-audio"
#define DREAM_ENGINE_OPENING_IDENTIFIER "id-scene-opening-presentation"

// DreamEngine::ResourceManager Utility
#define DREAM_ENGINE_PNG_EXTENSION ".png"
#define DREAM_ENGINE_MP3_EXTENSION ".mp3"
#define DREAM_ENGINE_MP4_EXTENSION ".mp4"
#define DREAM_ENGINE_TTF_EXTENSION ".ttf"

// DreamEngine::Camera Utility
#define NO_SCALE 1.0f
#define NO_PARALLEX 1.0f
#define CAMERA_DEFAULT_INERTIA 1.5f

// DreamEngine::CollisionManager Utility
#define LAYER_NONE "layer-none"

#ifdef DEBUG
#define COLLISION_MANAGER_ON_RENDER(camera) CollisionManager::getInstance()->onRender(camera)
#else
#define COLLISION_MANAGER_ON_RENDER(camera) ((void)0)
#endif

// Dream Engine Color Utilities
#define COLOR_TO_ARGS(color) (color).red, (color).green, (color).blue, (color).alpha

#endif //DREAM_ENGINE_SYMBOLS_H
