cmake_minimum_required(VERSION 3.28.1)
project(AOC2024)

set(CMAKE_CXX_STANDARD 23)

add_executable(AOC2024
        main.cpp
        Days/Day.hpp
        Days/Day1.cpp
        Days/Day2.cpp
        Days/Day3.cpp
        Days/Day4.cpp
        Libraries/utils.tpp
        Libraries/utils.cpp
        Libraries/utils.hpp
        Days/Day5.cpp)