cmake_minimum_required(VERSION 3.30)
project(Day7 C)

set(CMAKE_C_STANDARD 11)

add_library(Day7 STATIC library.c
        "Make all zeros.c"
        "Pop the balloon.c"
        "The longest palindrome.c")
