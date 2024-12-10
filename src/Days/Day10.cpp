#include <queue>

#include "Day.hpp"
#include "../Libraries/utils.hpp"


namespace AOC2024 {


static std::vector<int> DIRS = {-1, 0, 0, 1, 1, 0, 0, -1};

struct Coord {
    int y;
    int x;

    friend bool operator==(const Coord &lhs, const Coord &rhs) {
        return lhs.y == rhs.y
               && lhs.x == rhs.x;
    }
};


int64_t solveDay10Part1() {
    std::vector<std::string> grid = utils::readFileLines("..\\src\\Resources\\day10.txt");
    int64_t result = 0;
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[0].size(); ++x) {
            if (grid[y][x] == '0') {
                std::queue<int> q;
                q.push(x);
                q.push(y);
                std::vector<Coord> found;

                while (!q.empty()) {
                    int nx = q.front();
                    q.pop();
                    int ny = q.front();
                    q.pop();
                    char val = grid[ny][nx];

                    for (int dir = 0; dir < DIRS.size(); dir += 2) {
                        int ye = ny + DIRS[dir];
                        int xe = nx + DIRS[dir + 1];
                        if (ye < 0 || ye >= grid.size() || xe < 0 || xe >= grid[0].size()) {
                            continue;
                        }
                        if (grid[ye][xe] == val + 1) {
                            if (grid[ye][xe] == '9') {
                                Coord c = {ye, xe};
                                bool newCoord = true;
                                for (Coord f : found) {
                                    if (f == c) {
                                        newCoord = false;
                                        break;
                                    }
                                }
                                if (newCoord) {
                                    found.push_back(c);
                                }
                            } else {
                                q.push(xe);
                                q.push(ye);
                            }
                        }
                    }
                }

                result += found.size();
            }
        }
    }

    return result;
}

int64_t solveDay10Part2() {
    std::vector<std::string> grid = utils::readFileLines("..\\src\\Resources\\day10.txt");
    int64_t result = 0;
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[0].size(); ++x) {
            if (grid[y][x] == '0') {
                std::queue<int> q;
                q.push(x);
                q.push(y);

                while (!q.empty()) {
                    int nx = q.front();
                    q.pop();
                    int ny = q.front();
                    q.pop();
                    char val = grid[ny][nx];

                    for (int dir = 0; dir < DIRS.size(); dir += 2) {
                        int ye = ny + DIRS[dir];
                        int xe = nx + DIRS[dir + 1];
                        if (ye < 0 || ye >= grid.size() || xe < 0 || xe >= grid[0].size()) {
                            continue;
                        }
                        if (grid[ye][xe] == val + 1) {
                            if (grid[ye][xe] == '9') {
                                ++result;
                            } else {
                                q.push(xe);
                                q.push(ye);
                            }
                        }
                    }
                }
            }
        }
    }

    return result;
}


}
