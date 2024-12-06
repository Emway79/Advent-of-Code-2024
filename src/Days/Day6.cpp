#include <unordered_set>

#include "Day.hpp"
#include "../Libraries/utils.hpp"


namespace AOC2024 {


static const std::vector DIRS = {0, -1, 1, 0, 0, 1, -1, 0};

int hashPosition(int y, int x, int dir) {
    int hash = y << 10;
    hash += x;
    hash <<= 10;
    return hash + dir;
}

int64_t solveDay6Part1() {
    std::vector<std::string> grid = utils::readFileLines("..\\src\\Resources\\day6.txt");
    int64_t result = 0;
    int guard_x = 0;
    int guard_y = 0;
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[0].size(); ++x) {
            if (grid[y][x] == '^') {
                guard_x = x;
                guard_y = y;
            }
        }
    }
    int dir = 0;
    while (guard_y >= 0 && guard_y < grid.size() && guard_x >= 0 && guard_x < grid[0].size()) {
        grid[guard_y][guard_x] = 'X';
        int next_y = guard_y + DIRS[dir * 2 + 1];
        int next_x = guard_x + DIRS[dir * 2];
        if (next_x < 0 || next_y < 0 || next_x >= grid[0].size() || next_y >= grid.size()) {
            break;
        }
        if (grid[next_y][next_x] == '#') {
            ++dir;
            dir %= 4;
        } else {
            guard_x = next_x;
            guard_y = next_y;
        }
    }

    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[0].size(); ++x) {
            if (grid[y][x] == 'X') {
                ++result;
            }
        }
    }

    return result;
}

int64_t solveDay6Part2() {
    std::vector<std::string> grid = utils::readFileLines("..\\src\\Resources\\day6.txt");
    int64_t result = 0;
    int guard_x_reset = 0;
    int guard_y_reset = 0;
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[0].size(); ++x) {
            if (grid[y][x] == '^') {
                guard_x_reset = x;
                guard_y_reset = y;
            }
        }
    }

    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[0].size(); ++x) {
            if (grid[y][x] == '#' || grid[y][x] == '^') {
                continue;
            }
            grid[y][x] = '#';
            int guard_x = guard_x_reset;
            int guard_y = guard_y_reset;
            int dir = 0;
            std::unordered_set<int> positions;

            while (guard_y >= 0 && guard_y < grid.size() && guard_x >= 0 && guard_x < grid[0].size()) {
                int hash = hashPosition(guard_y, guard_x, dir);
                if (positions.contains(hash)) {
                    ++result;
                    break;
                }
                positions.emplace(hash);

                int next_y = guard_y + DIRS[dir * 2 + 1];
                int next_x = guard_x + DIRS[dir * 2];
                if (next_x < 0 || next_y < 0 || next_x >= grid[0].size() || next_y >= grid.size()) {
                    break;
                }
                if (grid[next_y][next_x] == '#') {
                    ++dir;
                    dir %= 4;
                    continue;
                }
                guard_x = next_x;
                guard_y = next_y;
            }

            grid[y][x] = '.';
        }
    }


    return result;
}


}
