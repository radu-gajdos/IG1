cmake_minimum_required(VERSION 3.24)
project(SortedSet__1_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SortedSet__1_
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SortedSet.cpp
        SortedSet.h
        SortedSetIterator.cpp
        SortedSetIterator.h)
