cmake_minimum_required(VERSION 3.24)
project(problema_lab1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(problema_lab1
        App.cpp
        ShortTest.cpp
        ShortTest.h
        SortedSet.cpp
        SortedSet.h
        SortedSetIterator.cpp
        SortedSetIterator.h)
