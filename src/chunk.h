//
// Created by nathan on 1/17/17.
//

#ifndef CRAFT_CHUNK_H
#define CRAFT_CHUNK_H

#include <GL/glew.h>
#include "block_map.h"
#include "height_map.h"
#include "sign.h"
#include <memory>

class WorkerItem;

class Chunk {
public:
    std::unique_ptr<BlockMap<CHUNK_SIZE, CHUNK_HEIGHT>> blocks;
    std::unique_ptr<BlockMap<CHUNK_SIZE, CHUNK_HEIGHT>> light_levels;
    std::unique_ptr<HeightMap<CHUNK_SIZE>> height_map;

    ~Chunk();

    SignList signs;
    int p, q; // chunk position
    int faces;
    int sign_faces;
    bool dirty;
    int miny;
    int maxy;
    GLuint buffer;
    GLuint sign_buffer;

    Chunk(int p, int q);

    int get_block(int x, int y, int z) const;
    int get_block_or_zero(int x, int y, int z) const;
    int set_block(int x, int y, int z, char w);

    int set_light_level(int x, int y, int z, char value);
    int get_light_level(int x, int y, int z) const;

    int distance(int p, int q);
    void set_dirty_flag();

    void foreach_block(std::function<void (int, int, int, char)> func);
};

typedef std::shared_ptr<Chunk> ChunkPtr;

int highest_block(float x, float z);
int chunk_visible(float planes[6][4], int p, int q, int miny, int maxy);

#endif //CRAFT_CHUNK_H
