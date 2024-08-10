cmake_minimum_required(VERSION 3.10)
project(veclite)

set(CMAKE_C_STANDARD 17)

include_directories(.)

add_executable(veclite
        main.cpp
        veclite.cpp)
