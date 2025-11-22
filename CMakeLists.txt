cmake_minimum_required(VERSION 4.0)
project(data_structure C)

set(CMAKE_C_STANDARD 11)

add_executable(new_target pointer/demo.c
        algorithm/binary_search.c
        linked_list/demo.c)
