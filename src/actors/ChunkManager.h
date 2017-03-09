//
// Created by Nathanial Hartman on 3/9/17.
//

#ifndef CRAFT_CHUNKMANAGER_H
#define CRAFT_CHUNKMANAGER_H

#include <caf/all.hpp>
#include "../chunk/chunk.h"
#include "../chunk/ChunkMesh.h"

using chunk_manager_add = caf::atom_constant<caf::atom("cmadd")>;
using chunk_manager_remove = caf::atom_constant<caf::atom("cmremove")>;
using chunk_manager_find_neighborhood = caf::atom_constant<caf::atom("cmfn")>;
using chunk_manager_add_mesh = caf::atom_constant<caf::atom("cmam")>;
using chunk_manager_set_block = caf::atom_constant<caf::atom("cmsb")>;
using chunk_manager_get_block = caf::atom_constant<caf::atom("cmgb")>;

typedef std::unordered_map<ChunkPosition, ChunkPtr, ChunkPositionHash> ChunkMap;
typedef std::unordered_map<ChunkPosition, std::shared_ptr<ChunkMesh>, ChunkPositionHash> ChunkMeshMap;

class ChunkManager : public caf::event_based_actor {
private:
    ChunkMap _chunks;
    ChunkMeshMap _meshes;
public:
    ChunkManager(caf::actor_config& cfg);
    caf::behavior make_behavior() override;

private:
    int hit_test(int previous, float x, float y, float z, float rx, float ry,
                 int *bx, int *by, int *bz);

    int hit_test_face(Player *player, int *x, int *y, int *z, int *face);
};

#endif //CRAFT_CHUNKMANAGER_H
