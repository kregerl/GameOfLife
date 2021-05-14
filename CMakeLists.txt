cmake_minimum_required(VERSION 3.14)
project(SDLLife C)

set(CMAKE_C_STANDARD 99)

add_executable(SDLLife main.c rendering.c rendering.h game.h game.c)
target_link_libraries(SDLLife SDL2)