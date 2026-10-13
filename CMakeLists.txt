cmake_minimum_required(VERSION 3.20)

project(MinimalPBR LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(Stb REQUIRED)
find_package( imgui CONFIG REQUIRED )
find_package( assimp CONFIG REQUIRED )

include(${CMAKE_SOURCE_DIR}/cmake/MPBRApplication.cmake)

add_subdirectory(src)
add_subdirectory(apps)
