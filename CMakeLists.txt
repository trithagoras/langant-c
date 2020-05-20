cmake_minimum_required(VERSION 3.15)
project(langant C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-lncurses")

add_executable(langant main.c game.c game.h view.c view.h)