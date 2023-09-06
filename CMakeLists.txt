cmake_minimum_required(VERSION 3.26)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(tic_tac_toe
        src/Field.cpp
        src/Field.h
        src/tic_tac_toe.cpp
        src/VectorExtensions.cpp
        src/VectorExtensions.h)
