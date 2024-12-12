#include <queue>

#include "Day.hpp"
#include "../Libraries/utils.hpp"
#include "../Libraries/definitions.hpp"


namespace AOC2024 {


std::vector<int> DIRS = {1, 0, -1, 0, 0, 1, 0, -1};

int64_t solveDay12Part1() {
    std::vector<std::string> grid = utils::readFileLines("..\\src\\Resources\\day12.txt");
    i64 result = 0;
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[0].size(); ++x) {
            if (grid[y][x] <= 'Z') {
                i64 size = 0;
                i64 perimiter = 0;
                char type = grid[y][x];
                std::queue<i64> q;
                q.push(y);
                q.push(x);

                while (!q.empty()) {
                    i64 ay = q.front();
                    q.pop();
                    i64 ax = q.front();
                    q.pop();
                    if (grid[ay][ax] == type + 32) {
                        continue;
                    }
                    
                    ++size;
                    grid[ay][ax] = type + 32;
                    for (i64 dir = 0; dir < DIRS.size(); dir += 2) {
                        i64 ny = ay + DIRS[dir];
                        i64 nx = ax + DIRS[dir + 1];
                        if (ny < 0 || ny >= grid.size() || nx < 0 || nx >= grid[0].size()) {
                            ++perimiter;
                            continue;
                        }
                        if (ny >= 0 && ny < grid.size() && nx >= 0 && nx < grid[0].size()) {
                            if (grid[ny][nx] == type) {
                                q.push(ny);
                                q.push(nx);
                            } else if (grid[ny][nx] != type + 32) {
                                ++perimiter;
                            }
                        }
                    }
                }

                result += size * perimiter;
            }
        }
    }

    return result;
}

int64_t solveDay12Part2() {
    std::vector<std::string> grid = utils::readFileLines("..\\src\\Resources\\day12.txt");
    for (std::string& line : grid) {
        line = '|' + line + '|';
    }
    std::string empty = std::string(grid[0].size(), '|');
    grid.push_back(empty);
    grid.insert(grid.begin(), empty);

    i64 result = 0;
    for (int y = 1; y < grid.size() - 1; ++y) {
        for (int x = 1; x < grid[0].size() - 1; ++x) {
            if (grid[y][x] <= 'Z') {
                i64 size = 0;
                i64 corners = 0;
                char type = grid[y][x];
                std::queue<i64> q;
                q.push(y);
                q.push(x);

                while (!q.empty()) {
                    i64 ay = q.front();
                    q.pop();
                    i64 ax = q.front();
                    q.pop();
                    if (grid[ay][ax] == type + 32) {
                        continue;
                    }

                    ++size;
                    grid[ay][ax] = type + 32;
                    for (i64 dir = 0; dir < DIRS.size(); dir += 2) {
                        i64 ny = ay + DIRS[dir];
                        i64 nx = ax + DIRS[dir + 1];
                        if (ny > 0 && ny < grid.size() - 1 && nx > 0 && nx < grid[0].size() - 1) {
                            if (grid[ny][nx] == type) {
                                q.push(ny);
                                q.push(nx);
                            }
                        }
                    }

                    if (grid[ay][ax + 1] != type && grid[ay][ax + 1] != type + 32 &&
                        grid[ay + 1][ax] != type && grid[ay + 1][ax] != type + 32) {
                        ++corners;
                    }
                    if (grid[ay][ax - 1] != type && grid[ay][ax - 1] != type + 32 &&
                        grid[ay + 1][ax] != type && grid[ay + 1][ax] != type + 32)
                        ++corners;
                    if (grid[ay][ax + 1] != type && grid[ay][ax + 1] != type + 32 &&
                        grid[ay - 1][ax] != type && grid[ay - 1][ax] != type + 32)
                        ++corners;
                    if (grid[ay][ax - 1] != type && grid[ay][ax - 1] != type + 32 &&
                        grid[ay - 1][ax] != type && grid[ay - 1][ax] != type + 32)
                        ++corners;

                    if ((grid[ay][ax + 1] == type || grid[ay][ax + 1] == type + 32) &&
                        (grid[ay + 1][ax] == type || grid[ay + 1][ax] == type + 32) &&
                         grid[ay + 1][ax + 1] != type && grid[ay + 1][ax + 1] != type + 32)
                        ++corners;
                    if ((grid[ay][ax - 1] == type || grid[ay][ax - 1] == type + 32) &&
                        (grid[ay + 1][ax] == type || grid[ay + 1][ax] == type + 32) &&
                         grid[ay + 1][ax - 1] != type && grid[ay + 1][ax - 1] != type + 32)
                        ++corners;
                    if ((grid[ay][ax + 1] == type || grid[ay][ax + 1] == type + 32) &&
                        (grid[ay - 1][ax] == type || grid[ay - 1][ax] == type + 32) &&
                         grid[ay - 1][ax + 1] != type && grid[ay - 1][ax + 1] != type + 32)
                        ++corners;
                    if ((grid[ay][ax - 1] == type || grid[ay][ax - 1] == type + 32) &&
                        (grid[ay - 1][ax] == type || grid[ay - 1][ax] == type + 32) &&
                        grid[ay - 1][ax - 1] != type && grid[ay - 1][ax - 1] != type + 32)
                        ++corners;
                }

                result += size * corners;
            }
        }
    }

    return result;
}


}
