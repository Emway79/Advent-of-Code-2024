#include <unordered_map>

#include "Day.hpp"
#include "../Libraries/utils.hpp"


namespace AOC2024 {


int64_t solveDay1Part1() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day1.txt");
    long long result = 0;
    std::vector<int> left;
    std::vector<int> right;
    for (std::string& line : lines) {
        std::vector<std::string> nums = utils::stringSplit(line, "   ");
        left.push_back(std::stoi(nums[0]));
        right.push_back(std::stoi(nums[1]));
    }
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    for (int i = 0; i < left.size(); ++i) {
        result += std::abs(left[i] - right[i]);
    }

    return result;
}

int64_t solveDay1Part2() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day1.txt");
    long long result = 0;
    std::vector<int> left;
    std::unordered_map<int, int> map;
    for (std::string& line : lines) {
        std::vector<std::string> nums = utils::stringSplit(line, "   ");
        int r = std::stoi(nums[1]);
        left.push_back(std::stoi(nums[0]));
        if (map.contains(r)) {
            map[r] += 1;
        } else {
            map[r] = 1;
        }
    }
    for (int i : left) {
        if (map.contains(i)) {
            result += i * map[i];
        }
    }

    return result;
}


}
