cmake_minimum_required(VERSION 4.1)
project(transition_table C)

set(CMAKE_C_STANDARD 23)

add_executable(
        transition_table
        main.c
        transition_table.h
        transition_table.c
)
