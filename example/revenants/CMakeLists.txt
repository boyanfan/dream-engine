cmake_minimum_required(VERSION 3.15)
project(revenants VERSION 0.9 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../dream-engine build-engine)

add_executable(${PROJECT_NAME} main.cpp
    src/executable.cpp
    src/ember.cpp
    src/character.cpp
    src/sword.cpp
    src/lord.cpp
    src/damage.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE dream-engine)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()