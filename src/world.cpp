#include "world.h"
#include "biomes/rolling_planes.h"
#include "biomes/mountains.h"

void create_world(TransientChunk& chunk, int p, int q) {
    Mountains mountains;
    mountains.create_chunk(chunk, p, q);
}

