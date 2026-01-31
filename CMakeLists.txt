cmake_minimum_required(VERSION 4.1)
project(transition_table C)

set(CMAKE_C_STANDARD 23)

add_executable(
        01_transition_table
        01_transition_table/main.c
        01_transition_table/transition_table.h
        01_transition_table/transition_table.c
)

add_executable(
        02_transition_table
        02_transition_table/main.c
        02_transition_table/includes/transition_table.h
        02_transition_table/src/transition_table.c
)