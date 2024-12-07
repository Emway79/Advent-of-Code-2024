#include "Day.hpp"
#include "../Libraries/utils.hpp"


namespace AOC2024 {


int64_t solveDay7Part1() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day7.txt");
    int64_t result = 0;

    for (std::string& line : lines) {
        std::vector<std::string> split = utils::stringSplit(line, ": ");
        int64_t equation = std::stoll(split[0]);
        std::vector<std::string> nums_string = utils::stringSplit(split[1], " ");
        std::vector<int64_t> nums;
        for (std::string& s : nums_string) {
            nums.push_back(std::stoll(s));
        }

        std::vector<int64_t> perms;
        perms.push_back(nums[0]);
        for (int op = 1; op < nums.size(); ++op) {
            std::vector<int64_t> new_perms;
            for (int64_t perm : perms) {
                int64_t plus = perm + nums[op];
                int64_t times = perm * nums[op];
                if (plus <= equation) {
                    new_perms.push_back(plus);
                }
                if (times <= equation) {
                    new_perms.push_back(times);
                }
            }
            perms = new_perms;
        }
        for (int64_t res : perms) {
            if (res == equation) {
                result += equation;
                break;
            }
        }
    }

    return result;
}

int64_t solveDay7Part2() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day7.txt");
    int64_t result = 0;

    for (std::string& line : lines) {
        std::vector<std::string> split = utils::stringSplit(line, ": ");
        int64_t equation = std::stoll(split[0]);
        std::vector<std::string> nums_string = utils::stringSplit(split[1], " ");
        std::vector<int64_t> nums;
        for (std::string& s : nums_string) {
            nums.push_back(std::stoll(s));
        }

        std::vector<int64_t> perms;
        perms.push_back(nums[0]);
        for (int op = 1; op < nums.size(); ++op) {
            std::vector<int64_t> new_perms;
            for (int64_t perm : perms) {
                int64_t plus = perm + nums[op];
                int64_t times = perm * nums[op];
                int64_t concat = std::stoll(std::to_string(perm) + std::to_string(nums[op]));
                if (plus <= equation) {
                    new_perms.push_back(plus);
                }
                if (concat <= equation) {
                    new_perms.push_back(concat);
                }
                if (times <= equation) {
                    new_perms.push_back(times);
                }
            }
            perms = new_perms;
        }
        for (int64_t res : perms) {
            if (res == equation) {
                result += equation;
                break;
            }
        }
    }

    return result;
}


}
