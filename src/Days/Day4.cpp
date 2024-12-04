#include <iostream>

#include "Day.hpp"
#include "../Libraries/utils.hpp"

namespace AOC2024 {

int64_t solveDay4Part1() {
    const std::vector<std::string> grid = utils::readFileLines("..\\src\\Resources\\day4.txt");
    int64_t result = 0;

    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[y].size(); ++x) {
            if (x < grid[y].size() - 3) {
                if (grid[y][x] == 'X' && grid[y][x + 1] == 'M' && grid[y][x + 2] == 'A' && grid[y][x + 3] == 'S') {
                    ++result;
                } else if (grid[y][x] == 'S' && grid[y][x + 1] == 'A' && grid[y][x + 2] == 'M' && grid[y][x + 3] == 'X') {
                    ++result;
                }
            }
            if (y < grid.size() - 3) {
                if (grid[y][x] == 'X' && grid[y + 1][x] == 'M' && grid[y + 2][x] == 'A' && grid[y + 3][x] == 'S') {
                    ++result;
                } else if (grid[y][x] == 'S' && grid[y + 1][x] == 'A' && grid[y + 2][x] == 'M' && grid[y + 3][x] == 'X') {
                    ++result;
                }
            }
            if (x < grid[y].size() - 3 && y < grid[y].size() - 3) {
                if (grid[y][x] == 'X' && grid[y + 1][x + 1] == 'M' && grid[y + 2][x + 2] == 'A' && grid[y + 3][x + 3] == 'S') {
                    ++result;
                } else if (grid[y][x] == 'S' && grid[y + 1][x + 1] == 'A' && grid[y + 2][x + 2] == 'M' && grid[y + 3][x + 3] == 'X') {
                    ++result;
                }
            }

            if (x < grid[y].size() - 3 && y > 2) {
                if (grid[y][x] == 'X' && grid[y - 1][x + 1] == 'M' && grid[y - 2][x + 2] == 'A' && grid[y - 3][x + 3] == 'S') {
                    ++result;
                } else if (grid[y][x] == 'S' && grid[y - 1][x + 1] == 'A' && grid[y - 2][x + 2] == 'M' && grid[y - 3][x + 3] == 'X') {
                    ++result;
                }
            }
        }
    }

    return result;
}

int64_t solveDay4Part2() {
    const std::vector<std::string> grid = utils::readFileLines("..\\src\\Resources\\day4.txt");
    int64_t result = 0;

    for (int y = 1; y < grid.size() - 1; ++y) {
        for (int x = 1; x < grid[y].size() - 1; ++x) {
            if (grid[y][x] == 'A') {
                if (((grid[y - 1][x - 1] == 'M' && grid[y + 1][x + 1] == 'S') ||
                    (grid[y - 1][x - 1] == 'S' && grid[y + 1][x + 1] == 'M')) &&
                    ((grid[y - 1][x + 1] == 'M' && grid[y + 1][x - 1] == 'S') ||
                    (grid[y - 1][x + 1] == 'S' && grid[y + 1][x - 1] == 'M'))) {
                    ++result;
                }
            }
        }
    }

    return result;
}

}