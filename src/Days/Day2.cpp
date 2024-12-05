#include "Day.hpp"
#include "../Libraries/utils.hpp"


namespace AOC2024 {


int64_t solveDay2Part1() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day2.txt");
    int64_t result = 0;
    for (std::string& line: lines) {
        std::vector<std::string> nums = utils::stringSplit(line, " ");
        int prev = std::stoi(nums[0]);
        bool up = true;
        bool down = true;
        for (int i = 1; i < nums.size(); ++i) {
            int num = std::stoi(nums[i]);
            int diff = std::abs(prev - num);
            if (up && num > prev && diff < 4) {
                down = false;
                prev = num;
            } else if (down && num < prev && diff < 4) {
                up = false;
                prev = num;
            } else {
                up = false;
                down = false;
            }
        }
        if (up || down) {
            result++;
        }
    }

    return result;
}

int64_t solveDay2Part2() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day2.txt");
    int64_t result = 0;
    for (std::string& line: lines) {
        std::vector<std::string> read = utils::stringSplit(line, " ");
        bool found = false;
        for (int r = 0; r < read.size(); ++r) {
            std::vector<std::string> nums;
            for (int i = 0; i < read.size(); ++ i) {
                if (i != r) {
                    nums.push_back(read[i]);
                }
            }

            int prev = std::stoi(nums[0]);
            bool up = true;
            bool down = true;
            for (int i = 1; i < nums.size(); ++i) {
                int num = std::stoi(nums[i]);
                int diff = std::abs(prev - num);
                if (up && num > prev && diff < 4) {
                    down = false;
                    prev = num;
                } else if (down && num < prev && diff < 4) {
                    up = false;
                    prev = num;
                } else {
                    up = false;
                    down = false;
                }
            }
            if (up || down) {
                result++;
                found = true;
                break;
            }
        }
        if (found) {
            continue;
        }
    }

    return result;
}


}
