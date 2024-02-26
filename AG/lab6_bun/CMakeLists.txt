cmake_minimum_required(VERSION 3.24)
project(lab6_bun)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab6_bun
        AdjListe.cpp
        AdjListe.h
        main.cpp)
