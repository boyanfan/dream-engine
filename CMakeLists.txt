cmake_minimum_required(VERSION 3.15)
project(dream-engine VERSION 0.9 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} STATIC
    # Core Library
    core/application.cpp
    core/resource.cpp
    core/font.cpp
    core/vector2.cpp
    core/logger.cpp
    core/timer.cpp
    core/video.cpp
    core/geometry.cpp
    core/camera.cpp
    core/texture.cpp
    core/scene.cpp
    core/logo.cpp
    core/animation.cpp
    core/state.cpp
    core/transform.cpp
    core/collision.cpp

    # UI Library
    ui/color.cpp
    ui/bar.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/api>
    $<INSTALL_INTERFACE:include>
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED IMPORTED_TARGET sdl3)
pkg_check_modules(SDL3_IMAGE REQUIRED IMPORTED_TARGET sdl3-image)
pkg_check_modules(SDL3_MIXER REQUIRED IMPORTED_TARGET sdl3-mixer)
pkg_check_modules(SDL3_TTF REQUIRED IMPORTED_TARGET sdl3-ttf)

pkg_check_modules(AVFORMAT REQUIRED IMPORTED_TARGET libavformat)
pkg_check_modules(AVCODEC REQUIRED IMPORTED_TARGET libavcodec)
pkg_check_modules(AVUTIL REQUIRED IMPORTED_TARGET libavutil)
pkg_check_modules(SWSCALE REQUIRED IMPORTED_TARGET libswscale)
pkg_check_modules(SWRESAMPLE REQUIRED IMPORTED_TARGET libswresample)

target_link_libraries(${PROJECT_NAME} PUBLIC
    PkgConfig::SDL3
    PkgConfig::SDL3_IMAGE
    PkgConfig::SDL3_MIXER
    PkgConfig::SDL3_TTF
    PkgConfig::AVFORMAT
    PkgConfig::AVCODEC
    PkgConfig::AVUTIL
    PkgConfig::SWSCALE
    PkgConfig::SWRESAMPLE
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()