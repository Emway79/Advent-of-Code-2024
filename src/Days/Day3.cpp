#include <regex>

#include "Day.hpp"
#include "../Libraries/utils.hpp"


namespace AOC2024 {


int64_t solveDay3Part1() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day3.txt");
    int64_t result = 0;
    std::regex re("mul\\([1-9][0-9]{0,2},[1-9][0-9]{0,2}\\)");
    for (std::string& line: lines) {
        auto words_begin =
        std::sregex_iterator(line.begin(), line.end(), re);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        {
            std::smatch match = *i;
            std::regex reg ("\\d+");
            std::string match_str = match.str();
            auto words_b =
            std::sregex_iterator(match_str.begin(), match_str.end(), reg);
            auto words_e = std::sregex_iterator();
            std::vector<int64_t> nums;
            for (std::sregex_iterator j = words_b; j != words_e; ++j) {
                std::smatch num_m = *j;
                std::string num = num_m.str();
                nums.push_back(std::stoll(num));
            }
            result += nums[0] * nums[1];
        }

    }

    return result;
}

int64_t solveDay3Part2() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day3.txt");
    int64_t result = 0;
    std::regex re("mul\\([1-9][0-9]{0,2},[1-9][0-9]{0,2}\\)|do\\(\\)|don't\\(\\)");
    bool enabled = true;
    for (std::string& line: lines) {
        auto words_begin =
        std::sregex_iterator(line.begin(), line.end(), re);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        {
            std::smatch match = *i;
            std::string match_str = match.str();
            if (match_str == "do()") {
                enabled = true;
                continue;
            }
            if (match_str == "don't()") {
                enabled = false;
            }
            if (!enabled) {
                continue;
            }

            std::regex reg ("\\d+");
            auto words_b =
            std::sregex_iterator(match_str.begin(), match_str.end(), reg);
            auto words_e = std::sregex_iterator();
            std::vector<int64_t> nums;
            for (std::sregex_iterator j = words_b; j != words_e; ++j) {
                std::smatch num_m = *j;
                std::string num = num_m.str();
                nums.push_back(std::stoll(num));
            }
            result += nums[0] * nums[1];
        }

    }

    return result;
}


}
