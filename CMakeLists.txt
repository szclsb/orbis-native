cmake_minimum_required(VERSION 3.23)
project(orbis)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "../bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "../bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")

add_subdirectory(GLFW)
add_subdirectory(GLAD)
add_subdirectory(orbis)
add_subdirectory(orbis-app)
