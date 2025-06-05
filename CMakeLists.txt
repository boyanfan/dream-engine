cmake_minimum_required(VERSION 3.15)
project(dream-engine VERSION 0.9 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} STATIC
    core/src/texture.cpp
    core/src/resource.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/core/include>
    $<INSTALL_INTERFACE:include>
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED IMPORTED_TARGET sdl3)
pkg_check_modules(SDL3_IMAGE REQUIRED IMPORTED_TARGET sdl3-image)
pkg_check_modules(SDL3_MIXER REQUIRED IMPORTED_TARGET sdl3-mixer)

target_link_libraries(${PROJECT_NAME} PUBLIC
    PkgConfig::SDL3
    PkgConfig::SDL3_IMAGE
    PkgConfig::SDL3_MIXER
)
