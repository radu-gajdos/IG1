cmake_minimum_required(VERSION 3.24)
project(lab5_v2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab5_v2
        Elektroscooter.cpp
        Elektroscooter.h
        main.cpp
        ScooterController.cpp
        ScooterController.h
        ScooterRepo.cpp
        ScooterRepo.h
        ScooterUI.cpp
        ScooterUI.h
        )

add_executable(test
        Elektroscooter.cpp
        Elektroscooter.h
        ScooterController.cpp
        ScooterController.h
        ScooterRepo.cpp
        ScooterRepo.h
        ScooterUI.cpp
        ScooterUI.h
        )
