#include <unordered_map>

#include "Day.hpp"
#include "../Libraries/utils.hpp"


namespace AOC2024 {


int64_t solveDay11Part1() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day11.txt");
    std::vector<std::string> splits = utils::stringSplit(lines[0], " ");
    std::unordered_map<int64_t, int64_t> nums;
    for (std::string& s : splits) {
        int64_t num = stoll(s);
        if (!nums.contains(num)) {
            nums[num] = 1;
        } else {
            ++nums[num];
        }
    }

    for (int i = 0; i < 25; ++i) {
        std::unordered_map<int64_t, int64_t> newNums;
        for (const auto &[key, amount]: nums) {
            std::string digits = std::to_string(key);
            if (key == 0) {
                if (!newNums.contains(1)) {
                    newNums[1] = amount;
                } else {
                    newNums[1] += amount;
                }
            } else if (digits.size() % 2 == 0) {
                int64_t n1 = stoll(digits.substr(0, digits.size() / 2));
                int64_t n2 = stoll(digits.substr(digits.size() / 2));
                if (!newNums.contains(n1)) {
                    newNums[n1] = amount;
                } else {
                    newNums[n1] += amount;
                }

                if (!newNums.contains(n2)) {
                    newNums[n2] = amount;
                } else {
                    newNums[n2] += amount;
                }
            } else {
                int64_t newNum = key * 2024;
                if (!newNums.contains(newNum)) {
                    newNums[newNum] = amount;
                } else {
                    newNums[newNum] += amount;
                }
            }
        }
        nums = newNums;
    }

    int64_t result = 0;
    for (const auto &[key, value]: nums) {
        result += value;
    }

    return result;
}

int64_t solveDay11Part2() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day11.txt");
    std::vector<std::string> splits = utils::stringSplit(lines[0], " ");
    std::unordered_map<int64_t, int64_t> nums;
    for (std::string& s : splits) {
        int64_t num = stoll(s);
        if (!nums.contains(num)) {
            nums[num] = 1;
        } else {
            ++nums[num];
        }
    }

    for (int i = 0; i < 75; ++i) {
        std::unordered_map<int64_t, int64_t> newNums;
        for (const auto &[key, amount]: nums) {
            std::string digits = std::to_string(key);
            if (key == 0) {
                if (!newNums.contains(1)) {
                    newNums[1] = amount;
                } else {
                    newNums[1] += amount;
                }
            } else if (digits.size() % 2 == 0) {
                int64_t n1 = stoll(digits.substr(0, digits.size() / 2));
                int64_t n2 = stoll(digits.substr(digits.size() / 2));
                if (!newNums.contains(n1)) {
                    newNums[n1] = amount;
                } else {
                    newNums[n1] += amount;
                }

                if (!newNums.contains(n2)) {
                    newNums[n2] = amount;
                } else {
                    newNums[n2] += amount;
                }
            } else {
                int64_t newNum = key * 2024;
                if (!newNums.contains(newNum)) {
                    newNums[newNum] = amount;
                } else {
                    newNums[newNum] += amount;
                }
            }
        }
        nums = newNums;
    }

    int64_t result = 0;
    for (const auto &[key, value]: nums) {
        result += value;
    }

    return result;
}


}
