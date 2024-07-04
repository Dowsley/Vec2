cmake_minimum_required(VERSION 3.10)
project(vecpp)

set(CMAKE_C_STANDARD 17)

include_directories(.)

add_executable(vecpp
        main.cpp
        vecpp.cpp)
