cmake_minimum_required(VERSION 3.24)
project(lab5_fin)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab5_fin
        Graph.cpp
        Graph.h
        main.cpp)
