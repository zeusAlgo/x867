cmake_minimum_required(VERSION 3.20)
project(c867)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(c867
        main.cpp
        degree.h
        roster.h
        roster.cpp
        student.h
        student.cpp)
