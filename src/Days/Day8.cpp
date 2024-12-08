#include "Day.hpp"
#include "../Libraries/utils.hpp"


namespace AOC2024 {


struct Antenna {
    int y;
    int x;
    char c;
};

int64_t solveDay8Part1() {
    std::vector<std::string> grid = utils::readFileLines("..\\src\\Resources\\day8.txt");

    std::vector<Antenna> antennas;
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[0].size(); ++x) {
            if (grid[y][x] != '.') {
                antennas.push_back({y, x, grid[y][x]});
            }
        }
    }

    for (int i = 0; i < antennas.size() - 1; ++i) {
        Antenna a1 = antennas[i];
        for (int j = i + 1; j < antennas.size(); ++j) {
            Antenna a2 = antennas[j];
            if (a1.c != a2.c) {
                continue;
            }

            int dy = a2.y - a1.y;
            int dx = a2.x - a1.x;
            int anti1_y = a1.y - dy;
            int anti1_x = a1.x - dx;
            int anti2_y = a2.y + dy;
            int anti2_x = a2.x + dx;
            if (anti1_y >= 0 && anti1_x >= 0 && anti1_x < grid[0].size()) {
                grid[anti1_y][anti1_x] = '#';
            }
            if (anti2_y < grid.size() && anti2_x >= 0 && anti2_x < grid[0].size()) {
                grid[anti2_y][anti2_x] = '#';
            }
        }
    }

    int64_t result = 0;
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[0].size(); ++x) {
            if (grid[y][x] == '#') {
                ++result;
            }
        }
    }

    return result;
}

int64_t solveDay8Part2() {
    std::vector<std::string> grid = utils::readFileLines("..\\src\\Resources\\day8.txt");

    std::vector<Antenna> antennas;
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[0].size(); ++x) {
            if (grid[y][x] != '.') {
                antennas.push_back({y, x, grid[y][x]});
            }
        }
    }

    for (int i = 0; i < antennas.size() - 1; ++i) {
        Antenna a1 = antennas[i];
        for (int j = i + 1; j < antennas.size(); ++j) {
            Antenna a2 = antennas[j];
            if (a1.c != a2.c) {
                continue;
            }
            grid[a1.y][a1.x] = '#';
            grid[a2.y][a2.x] = '#';

            int dy = a2.y - a1.y;
            int dx = a2.x - a1.x;
            int anti1_y = a1.y - dy;
            int anti1_x = a1.x - dx;
            int anti2_y = a2.y + dy;
            int anti2_x = a2.x + dx;
            while (anti1_y >= 0 && anti1_x >= 0 && anti1_x < grid[0].size()) {
                grid[anti1_y][anti1_x] = '#';
                anti1_y -= dy;
                anti1_x -= dx;
            }
            while (anti2_y < grid.size() && anti2_x >= 0 && anti2_x < grid[0].size()) {
                grid[anti2_y][anti2_x] = '#';
                anti2_y += dy;
                anti2_x += dx;
            }
        }
    }

    int64_t result = 0;
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[0].size(); ++x) {
            if (grid[y][x] == '#') {
                ++result;
            }
        }
    }

    return result;
}


}
