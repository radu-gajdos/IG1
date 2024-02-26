cmake_minimum_required(VERSION 3.24)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab2
        app.cpp
        GraphKantListe.cpp
        data.in
        GraphKantListe.h)
