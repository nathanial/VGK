#ifndef _map_h_
#define _map_h_

#include <functional>
#include <cmath>
#include <unordered_map>
#include "config.h"

template<unsigned int WIDTH, unsigned int HEIGHT>
class BlockMap {
public:
    char _data[WIDTH][HEIGHT][WIDTH] = {{{0}}};

    BlockMap() {}

    ~BlockMap() {}

    BlockMap(const BlockMap&) = delete;
    BlockMap& operator=(const BlockMap&) = delete;
    BlockMap(BlockMap&&) = delete;
    BlockMap& operator=(BlockMap&&) = delete;

    int set(int x, int y, int z, char w) {
        if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT || z < 0 || z >= WIDTH){
            printf("Bad Index %d,%d,%d\n", x, y, z);
            throw new std::invalid_argument("Bad Index");
        }

        int overwrite = 0;
        if(this->_data[x][y][z] > 0){
            overwrite = 1;
        }
        this->_data[x][y][z] = w;
        if(w){
            return 1;
        }
        return overwrite;
    }
    char get(int x, int y, int z) {
        if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT|| z < 0 || z >= WIDTH){
            printf("Bad Index %d,%d,%d\n", x, y, z);
            throw new std::invalid_argument("Bad Index");
        }
        return this->_data[x][y][z];
    }
    char get_or_default(int x, int y, int z, char _default) {
        if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT|| z < 0 || z >= WIDTH){
            return _default;
        }
        return this->_data[x][y][z];
    }
    void each(std::function<void (int, int, int, char)> func) {
        for(int x = 0; x < WIDTH; x++){
            for(int y = 0; y < HEIGHT; y++){
                for(int z = 0; z < WIDTH; z++){
                    if(this->_data[x][y][z] != 0){
                        func(x, y, z, this->_data[x][y][z]);
                    }
                }
            }
        }
    }
    unsigned int size() {
        return WIDTH * WIDTH * HEIGHT;
    };
};

#endif