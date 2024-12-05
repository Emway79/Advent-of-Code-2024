#include <iostream>
#include <unordered_map>

#include "Day.hpp"
#include "../Libraries/utils.hpp"

namespace AOC2024 {

int64_t solveDay5Part1() {
    std::vector<std::string> list = utils::readFileLines("..\\src\\Resources\\day5.txt");
    int64_t result = 0;
    std::unordered_map<int64_t, std::vector<int64_t>> pages;
    bool ordering = true;

    for (std::string &s : list) {
        if (s.empty()) {
            ordering = false;
            continue;
        }
        if (ordering) {
            std::vector<std::string> nums = utils::stringSplit(s, "|");
            int64_t page = std::stoll(nums[0]);
            if (!pages.contains(page)) {
                std::vector<int64_t> after;
                pages[page] = after;
            }
            pages[page].push_back(std::stoll(nums[1]));
        } else {
            std::vector<std::string> nums = utils::stringSplit(s, ",");
            std::vector<int64_t> order;
            for (std::string& n : nums) {
                order.push_back(std::stoll(n));
            }

            bool correct = true;
            for (int i = 1; i < order.size(); ++i) {
                int64_t print = order[i];
                for (int j = 0; j < i; ++j) {
                    for (const int64_t p : pages[print]) {
                        if (order[j] == p) {
                            correct = false;
                            break;
                        }
                    }
                }
            }

            if (correct) {
                result += order[order.size() / 2];
            }
        }
    }

    return result;
}

int64_t solveDay5Part2() {
    std::vector<std::string> list = utils::readFileLines("..\\src\\Resources\\day5.txt");
    int64_t result = 0;
    std::unordered_map<int64_t, std::vector<int64_t>> pages;
    bool ordering = true;

    for (std::string &s : list) {
        if (s.empty()) {
            ordering = false;
            continue;
        }
        if (ordering) {
            std::vector<std::string> nums = utils::stringSplit(s, "|");
            int64_t page = std::stoll(nums[0]);
            if (!pages.contains(page)) {
                std::vector<int64_t> after;
                pages[page] = after;
            }
            pages[page].push_back(std::stoll(nums[1]));
        } else {
            std::vector<std::string> nums = utils::stringSplit(s, ",");
            std::vector<int64_t> order;
            for (std::string& n : nums) {
                order.push_back(std::stoll(n));
            }

            bool incorrect = false;
            for (int i = 0; i < order.size(); ++i) {
                int64_t print = order[i];
                int index = i;
                for (int j = 0; j < i; ++j) {
                    for (const int64_t p : pages[print]) {
                        if (order[j] == p) {
                            index = j;
                            goto end;
                        }
                    }
                }
                end:
                if (index != i) {
                    order[i] = order[index];
                    i = index;
                    order[index] = print;
                    incorrect = true;
                }
            }

            if (incorrect) {
                result += order[order.size() / 2];
            }
        }
    }

    return result;
}

}