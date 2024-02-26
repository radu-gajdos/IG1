cmake_minimum_required(VERSION 3.24)
project(IteratedList_nou)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(IteratedList_nou
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        IteratedList.cpp
        IteratedList.h
        ListIterator.cpp
        ListIterator.h
        ShortTest.cpp
        ShortTest.h)
