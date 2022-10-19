cmake_minimum_required(VERSION 3.23)
project(orbis)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(GLFW)
add_subdirectory(GLAD)
add_subdirectory(src)
