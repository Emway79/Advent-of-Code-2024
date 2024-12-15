#include "Day.hpp"
#include "../Libraries/utils.hpp"
#include "../Libraries/definitions.hpp"


static std::vector<int> DIRS = {-1, 0, 0, 1, 1, 0, 0, -1};


namespace AOC2024 {

int64_t solveDay15Part1() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day15.txt");
    std::vector<std::string> grid;
    std::string moves;

    bool warehouse = true;
    for (std::string& line : lines) {
        if (line.empty()) {
            warehouse = false;
            continue;
        }

        if (warehouse) {
            grid.push_back(line);
        } else {
            moves.append(line);
        }
    }

    int x = 0;
    int y = 0;
    for (int yr = 0; yr < grid.size(); ++yr) {
        for (int xr = 0; xr < grid[0].size(); ++xr) {
            if (grid[yr][xr] == '@') {
                x = xr;
                y = yr;
                goto found;
            }
        }
    }
    found:

    for (const char c : moves) {
        int dir = 0;
        switch (c) {
            case '^': {
                dir = 0;
                break;
            }
            case '>': {
                dir = 1;
                break;
            }
            case 'v': {
                dir = 2;
                break;
            }
            case '<': {
                dir = 3;
                break;
            }
        }

        const int dy = DIRS[dir * 2];
        const int dx = DIRS[dir * 2 + 1];

        if (grid[y + dy][x + dx] == '.') {
            grid[y][x] = '.';
            grid[y + dy][x + dx] = '@';
            x += dx;
            y += dy;
            continue;
        }

        int moved = 1;
        while (true) {
            if (grid[y + moved * dy][x + moved * dx] == '#') {
                break;
            }
            if (grid[y + moved * dy][x + moved * dx] == '.') {
                for (int i = moved; i >= 1; --i) {
                    grid[y + i * dy][x + i * dx] = grid[y + (i - 1) * dy][x + (i - 1) * dx];
                }
                grid[y][x] = '.';
                x += dx;
                y += dy;
                break;
            }
            ++moved;
        }
    }


    s64 result = 0;
    for (int yr = 0; yr < grid.size(); ++yr) {
        for (int xr = 0; xr < grid[0].size(); ++xr) {
            if (grid[yr][xr] == 'O') {
                result += yr * 100 + xr;
            }
        }
    }

    return result;
}

int64_t solveDay15Part2() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day15.txt");
    std::vector<std::string> grid;
    std::string moves;

    bool warehouse = true;
    for (std::string& line : lines) {
        if (line.empty()) {
            warehouse = false;
            continue;
        }

        if (warehouse) {
            std::string newLine;
            for (char c : line) {
                if (c == '@') {
                    newLine.push_back('@');
                    newLine.push_back('.');
                } else if (c == 'O') {
                    newLine.push_back('[');
                    newLine.push_back(']');
                } else {
                    newLine.push_back(c);
                    newLine.push_back(c);
                }
            }
            grid.push_back(newLine);
        } else {
            moves.append(line);
        }
    }

    int x = 0;
    int y = 0;
    for (int yr = 0; yr < grid.size(); ++yr) {
        for (int xr = 0; xr < grid[0].size(); ++xr) {
            if (grid[yr][xr] == '@') {
                x = xr;
                y = yr;
                goto found;
            }
        }
    }
    found:

    int steps = 0;
    for (char c : moves) {
        ++steps;
        int dir = 0;
        switch (c) {
            case '^': {
                dir = 0;
                break;
            }
            case '>': {
                dir = 1;
                break;
            }
            case 'v': {
                dir = 2;
                break;
            }
            case '<': {
                dir = 3;
                break;
            }
        }

        const int dy = DIRS[dir * 2];
        const int dx = DIRS[dir * 2 + 1];

        if (grid[y + dy][x + dx] == '.') {
            grid[y][x] = '.';
            grid[y + dy][x + dx] = '@';
            x += dx;
            y += dy;
            continue;
        }
        if (grid[y + dy][x + dx] == '#') {
            continue;
        }

        if (dx != 0) {
            int moved = 1;
            while (true) {
                if (grid[y][x + moved * dx] == '#') {
                    break;
                }
                if (grid[y][x + moved * dx] == '.') {
                    for (int i = moved; i >= 1; --i) {
                        grid[y][x + i * dx] = grid[y][x + (i - 1) * dx];
                    }
                    grid[y][x] = '.';
                    x += dx;
                    break;
                }
                ++moved;
            }
        } else {
            int moved = 1;
            std::vector<int> xs;
            if (grid[y + moved * dy][x] == '[') {
                xs.push_back(x);
                xs.push_back(x + 1);
            } else {
                xs.push_back(x - 1);
                xs.push_back(x);
            }

            std::vector<std::vector<int>> changes;
            while (true) {
                std::vector<int> newXs;
                int nY = y + moved * dy;
                for (int bx : xs) {
                    if (grid[nY][bx] == '#') {
                        goto end;
                    }

                    if (grid[nY][bx] == '[') {
                        newXs.push_back(bx);
                        newXs.push_back(bx + 1);
                    } else if (grid[nY][bx] == ']') {
                        newXs.push_back(bx - 1);
                        newXs.push_back(bx);
                    }
                }

                changes.push_back(xs);

                if (newXs.empty()) {
                    for (int i = changes.size() - 1; i >= 1; --i) {
                        std::vector<int> indices = changes[i];
                        for (int j : indices) {
                            grid[nY][j] = grid[nY - dy][j];
                        }
                        for (int j : indices) {
                            grid[nY - dy][j] = '.';
                        }

                        nY -= dy;
                    }

                    grid[y + dy][x] = '@';
                    grid[y][x] = '.';
                    y += dy;

                    goto end;
                }

                xs = newXs;
                ++moved;
            }
        }
        end:
    }


    s64 result = 0;
    for (int yr = 0; yr < grid.size(); ++yr) {
        for (int xr = 0; xr < grid[0].size(); ++xr) {
            if (grid[yr][xr] == '[') {
                result += yr * 100 + xr;
            }
        }
    }

    return result;
}


}
