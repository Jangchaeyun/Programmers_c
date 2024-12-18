cmake_minimum_required(VERSION 3.30)
project(Day6 C)

set(CMAKE_C_STANDARD 11)

add_library(Day6 STATIC "Ball movement simulation.c"
        "Transporting gold and silver.c"
        "Fill in the puzzle pieces.c"
        "110 move.c"
        "Multi-level toothbrush sales.c")
