cmake_minimum_required(VERSION 3.28.1)
project(AOC2024)

set(CMAKE_CXX_STANDARD 23)

add_executable(AOC2024

        #MAIN
        src/main.cpp

        #Days
        src/Days/Day.hpp
        src/Days/Day1.cpp
        src/Days/Day2.cpp
        src/Days/Day3.cpp
        src/Days/Day4.cpp
        src/Days/Day5.cpp

        #Utilities
        src/Libraries/utils.tpp
        src/Libraries/utils.cpp
        src/Libraries/utils.hpp
        )