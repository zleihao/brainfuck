cmake_minimum_required(VERSION 3.29)
project(code_conversion C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall)

add_executable(brainfuck ./main.c ./brainfuck.c)