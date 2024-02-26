cmake_minimum_required(VERSION 3.24)
project(lab4)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab4 Shop.cpp Fruit.cpp FruitRepository.h FruitRepository.cpp UI.h UI.cpp FruitController.h Controller.cpp Tests.cpp)
