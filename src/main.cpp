#include <iostream>
#include <chrono>
#include <sstream>

#include "Days/Day.hpp"


#define TERMINAL_PADDING 30


int main() {

    auto startPart1 = std::chrono::high_resolution_clock::now();
    auto answerPart1 = AOC2024::solveDay14Part1();
    auto endPart1 = std::chrono::high_resolution_clock::now();
    double elapsedTimeMicPart1 = std::chrono::duration<double, std::micro>(endPart1 - startPart1).count();

    auto startPart2 = std::chrono::high_resolution_clock::now();
    auto answerPart2 = AOC2024::solveDay14Part2();
    auto endPart2 = std::chrono::high_resolution_clock::now();
    double elapsedTimeMicPart2 = std::chrono::duration<double, std::micro>(endPart2 - startPart2).count();

    std::stringstream stream1;
    stream1 << answerPart1;
    std::string paddingPart1(TERMINAL_PADDING - stream1.str().size(), ' ');
    std::cout << "Part1: " << answerPart1 << paddingPart1 <<
            "Time: " << static_cast<int64_t>(elapsedTimeMicPart1) / 1000000 <<
            "s " << static_cast<int64_t>(elapsedTimeMicPart1 / 1000) % 1000 <<
            "ms " << static_cast<int64_t>(elapsedTimeMicPart1) % 1000 <<
            "micros" << std::endl;

    std::stringstream stream2;
    stream2 << answerPart2;
    std::string paddingPart2(TERMINAL_PADDING - stream2.str().size(), ' ');
    std::cout << "Part2: " << answerPart2 << paddingPart2 <<
              "Time: " << static_cast<int64_t>(elapsedTimeMicPart2) / 1000000 <<
              "s " << static_cast<int64_t>(elapsedTimeMicPart2 / 1000) % 1000 <<
              "ms " << static_cast<int64_t>(elapsedTimeMicPart2) % 1000 <<
              "micros" << std::endl;
}
