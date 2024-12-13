#include <regex>

#include "Day.hpp"
#include "../Libraries/utils.hpp"
#include "../Libraries/definitions.hpp"


namespace AOC2024 {


int64_t solveDay13Part1() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day13.txt");
    s64 result = 0;
    std::regex re("\\d+");

    for (int i = 0; i < lines.size(); i += 4) {
        std::string& buttonA = lines[i];
        std::string& buttonB = lines[i + 1];
        std::string& prize = lines[i + 2];

        std::vector<s64> f;
        for (std::string& num : utils::applyRegex(buttonA, re)) {
            f.push_back(std::stoll(num));
        }
        for (std::string& num : utils::applyRegex(buttonB, re)) {
            f.push_back(std::stoll(num));
        }
        for (std::string& num : utils::applyRegex(prize, re)) {
            f.push_back(std::stoll(num));
        }

        s64 pressA = (f[4] * f[3] - f[2] * f[5]) / (f[0] * f[3] - f[2] * f[1]);
        s64 pressB = (f[0] * f[5] - f[4] * f[1]) / (f[0] * f[3] - f[2] * f[1]);
        if (pressA * f[0] + pressB * f[2] == f[4] &&
            pressA * f[1] + pressB * f[3] == f[5]) {
            result += pressA * 3 + pressB;
            }
    }

    return result;
}

int64_t solveDay13Part2() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day13.txt");
    s64 result = 0;
    std::regex re("\\d+");

    for (int i = 0; i < lines.size(); i += 4) {
        std::string& buttonA = lines[i];
        std::string& buttonB = lines[i + 1];
        std::string& prize = lines[i + 2];

        std::vector<s64> f;
        for (std::string& num : utils::applyRegex(buttonA, re)) {
            f.push_back(std::stoll(num));
        }
        for (std::string& num : utils::applyRegex(buttonB, re)) {
            f.push_back(std::stoll(num));
        }
        for (std::string& num : utils::applyRegex(prize, re)) {
            f.push_back(std::stoll(num) + 10000000000000);
        }

        s64 pressA = (f[4] * f[3] - f[2] * f[5]) / (f[0] * f[3] - f[2] * f[1]);
        s64 pressB = (f[0] * f[5] - f[4] * f[1]) / (f[0] * f[3] - f[2] * f[1]);
        if (pressA * f[0] + pressB * f[2] == f[4] &&
            pressA * f[1] + pressB * f[3] == f[5]) {
            result += pressA * 3 + pressB;
        }
    }

    return result;
}


}
