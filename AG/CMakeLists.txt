cmake_minimum_required(VERSION 3.24)
project(AG)

set(CMAKE_CXX_STANDARD 14)

include_directories(lab1)

add_executable(AG
        lab1/app.cpp
        lab1/GraphAdjListe.cpp
        lab1/GraphAdjListe.h lab2/GraphKantListe.h lab2/GraphKantListe.cpp lab2/app.cpp)
