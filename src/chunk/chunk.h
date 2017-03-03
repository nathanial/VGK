//
// Created by nathan on 1/17/17.
//

#ifndef CRAFT_CHUNK_H
#define CRAFT_CHUNK_H

#include <GL/glew.h>
#include "../block_map.h"
#include "../height_map.h"
#include "../sign.h"
#include <memory>
#include <mutex>
#include <vector>
#include <armadillo>

class Attrib;
class ChunkMesh;

typedef BlockMap<CHUNK_SIZE, CHUNK_HEIGHT> ChunkBlocks;

class Chunk {
private:
    mutable std::mutex _mesh_mtx;
    mutable std::mutex _block_mtx;
    const int _p;
    const int _q; // chunk position

    std::unique_ptr<ChunkBlocks> blocks;
    std::shared_ptr<ChunkMesh> _mesh;
public:
    Chunk(int p, int q);
    ~Chunk();

    int set_block(int x, int y, int z, char w);
    void set_mesh(std::shared_ptr<ChunkMesh> data);
    std::shared_ptr<ChunkMesh> mesh() const;

    std::unique_ptr<ChunkMesh> load(bool dirty, GLuint buffer) const;
    int get_block(int x, int y, int z) const;
    int get_block_or_zero(int x, int y, int z) const;
    void foreach_block(std::function<void (int, int, int, char)> func) const;
    int p() const;
    int q() const;
    int distance(int p, int q) const;
    void populate_opaque_array(BigBlockMap &opaque, HeightMap<48> &highest) const;
    void populate_light_array(BigBlockMap &opaque, BigBlockMap &light) const;

private:
    static std::vector<GLfloat> generate_geometry(int p, int q, const ChunkBlocks& blocks, BigBlockMap &opaque, BigBlockMap &light, HeightMap<CHUNK_SIZE * 3> &highest);
    static std::tuple<int,int,int> count_faces(int p, int q, const ChunkBlocks& blocks, const BigBlockMap &opaque);
};

typedef std::shared_ptr<Chunk> ChunkPtr;

int highest_block(float x, float z);
int chunk_visible(arma::mat planes, int p, int q, int miny, int maxy);

#endif //CRAFT_CHUNK_H
