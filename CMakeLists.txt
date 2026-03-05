cmake_minimum_required(VERSION 3.5)

project(idk_platform VERSION 0.0.1)
find_package(SDL3 REQUIRED)
find_package(OpenGL REQUIRED)

add_library(
    ${PROJECT_NAME} STATIC
)
target_compile_features(
    ${PROJECT_NAME} PUBLIC cxx_std_23
)
target_include_directories(
    ${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/h"
)
target_link_libraries(
    ${PROJECT_NAME} PUBLIC SDL3::SDL3 libidk idk_core
)
target_sources(
    ${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/platform_sdl3.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/window_gl.cpp"
)
