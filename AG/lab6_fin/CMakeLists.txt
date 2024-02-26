cmake_minimum_required(VERSION 3.24)
project(lab6_fin)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab6_fin
        GraphAdjListe.cpp
        GraphAdjListe.h
        main.cpp)
