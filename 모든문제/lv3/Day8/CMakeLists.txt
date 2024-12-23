cmake_minimum_required(VERSION 3.30)
project(Day8 C)

set(CMAKE_C_STANDARD 11)

add_library(Day8 STATIC "Number of ramps.c"
        "Drop 1,2,3.c"
        "Twin Towers Forest.c"
        Anti-cell.c
        "Maze Escape.c")
