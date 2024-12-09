#include "Day.hpp"
#include "../Libraries/utils.hpp"


namespace AOC2024 {


struct Block {
    int size;
    int id;
};

int64_t solveDay9Part1() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day9.txt");
    int64_t result = 0;
    std::string &line = lines[0];
    bool include = true;
    int right = line.size() + 1;
    int right_id = (line.size() + 1) / 2;
    int id = 0;
    int right_block = 0;
    int newpos = 0;

    for (int left = 0; left <= right; ++left) {
        if (left == right) {
            while (right_block > 0) {
                result += newpos * right_id;
                --right_block;
                ++newpos;
            }
            break;
        }
        if (include) {
            int block = line[left] - '0';
            for (int i = 0 ; i < block; ++i) {
                result += newpos * id;
                ++newpos;
            }
            ++id;
        } else {
            int empty = line[left] - '0';
            while (empty > 0) {
                if (right_block == 0) {
                    --right_id;
                    right -= 2;
                    right_block = line[right] - '0';
                }
                while (right_block > 0 && empty > 0) {
                    result += newpos * right_id;
                    --right_block;
                    ++newpos;
                    --empty;
                }
            }
        }

        include = !include;
    }

    return result;
}

int64_t solveDay9Part2() {
    std::vector<std::string> lines = utils::readFileLines("..\\src\\Resources\\day9.txt");
    int64_t result = 0;
    std::string &line = lines[0];
    bool include = true;

    int id = 0;
    std::vector<Block> blocks;
    for (char block : line) {
        int block_id = include ? id : -1;
        if (block - '0' != 0) {
            blocks.push_back({block - '0', block_id});
        }

        id = include ? id + 1 : id;
        include = !include;
    }

    for (int right = blocks.size() - 1; right >= 0; --right) {
        Block r = blocks[right];
        if (r.id == -1) {
            continue;
        }
        for (int empty = 0; empty < right; ++empty) {
            Block empt = blocks[empty];
            if (empt.id != -1) {
                continue;
            }
            if (empt.size >= r.size) {
                if (empt.size == r.size) {
                    empt.id = r.id;
                    empt.size = r.size;
                } else {
                    Block add {r.size, r.id};
                    empt.size -= r.size;
                    blocks.insert(std::next(blocks.begin(), empty), add);
                    ++right;
                    ++empty;
                }
                r.id = -1;
                blocks[empty] = empt;
                blocks[right] = r;
                break;
            }
        }
    }

    int pos = 0;
    for (Block block : blocks) {
        if (block.id != -1) {
            for (int i = 0; i < block.size; ++i) {
                result += block.id * pos;
                ++pos;
            }
        } else {
            pos += block.size;
        }
    }

    return result;
}


}
