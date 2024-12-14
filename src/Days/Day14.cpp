#include <iostream>

#include "Day.hpp"
#include "../Libraries/utils.hpp"
#include "../Libraries/definitions.hpp"


using namespace std;

struct Robot {
    int x;
    int y;
    int vx;
    int vy;
};

#define Y 103
#define X 101


namespace AOC2024 {


int64_t solveDay14Part1() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day14.txt");

    std::vector<Robot> robots;
    std::regex re("[-]?\\d+");
    for (std::string& line : lines) {
        std::vector<int> nums;
        for (string& s: utils::applyRegex(line, re)) {
            nums.push_back(stoi(s));
        }

        robots.push_back({nums[0], nums[1], nums[2], nums[3]});
    }

    for (int sec = 0; sec < 100; ++sec) {
        for (Robot& robot : robots) {
            robot.x += robot.vx;
            if (robot.x < 0) {
                robot.x = X + robot.x;
            }
            if (robot.x >= X) {
                robot.x = robot.x % X;
            }

            robot.y += robot.vy;
            if (robot.y < 0) {
                robot.y = Y + robot.y;
            }
            if (robot.y >= Y) {
                robot.y = robot.y % Y;
            }
        }
    }

    std::vector<s64> quadrants = {0, 0 ,0 ,0};
    for (Robot& robot : robots) {
        if (robot.x < X / 2) {
            if (robot.y < Y / 2) {
                quadrants[0] += 1;
            } else if (robot.y != Y / 2) {
                quadrants[3] += 1;
            }
        } else if (robot.x != X / 2) {
            if (robot.y < Y / 2) {
                quadrants[1] += 1;
            } else if (robot.y != Y / 2) {
                quadrants[2] += 1;
            }
        }
    }

    s64 result = 1;
    for (s64 amount : quadrants) {
        result *= amount;
    }

    return result;
}

int64_t solveDay14Part2() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day14.txt");

    std::vector<Robot> robots;
    std::regex re("[-]?\\d+");
    for (std::string& line : lines) {
        std::vector<int> nums;
        for (string& s: utils::applyRegex(line, re)) {
            nums.push_back(stoi(s));
        }

        robots.push_back({nums[0], nums[1], nums[2], nums[3]});
    }

    s64 result = 1;
    while (true) {
        std::vector<std::string> grid = std::vector(Y, std::string(X, ' '));
        bool unique = true;
        for (Robot& robot : robots) {
            robot.x += robot.vx;
            if (robot.x < 0) {
                robot.x = X + robot.x;
            }
            if (robot.x >= X) {
                robot.x = robot.x % X;
            }

            robot.y += robot.vy;
            if (robot.y < 0) {
                robot.y = Y + robot.y;
            }
            if (robot.y >= Y) {
                robot.y = robot.y % Y;
            }

            if (grid[robot.y][robot.x] == ' ') {
                grid[robot.y][robot.x] = '#';
            } else {
                unique = false;
            }
        }
        if (unique) {
            return result;
        }
        ++result;
    }
}


}
