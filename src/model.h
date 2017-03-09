//
// Created by nathan on 1/17/17.
//

#ifndef CRAFT_MODEL_H
#define CRAFT_MODEL_H

#include <GL/glew.h>
#include "chunk/chunk.h"
#include "config.h"
#include "worker.h"
#include <functional>
#include <tuple>
#include <vector>
#include <GLFW/glfw3.h>
#include "chunk/TransientChunk.h"
#include "chunk/TransientChunkMesh.h"

class Block {
public:
    int x;
    int y;
    int z;
    int w;
};

class State {
public:
    float x;
    float y;
    float z;
    float rx;
    float ry;
    float t;
};

class Attrib {
public:
    GLuint program;
    GLuint position;
    GLuint normal;
    GLuint uv;
    GLuint matrix;
    GLuint sampler;
    GLuint camera;
    GLuint timer;
    GLuint extra1;
    GLuint extra2;
    GLuint extra3;
    GLuint extra4;
};

class Player {
public:
    int id;
    char name[MAX_NAME_LENGTH];
    State state;
    State state1;
    State state2;
    GLuint buffer;
};

class Model {
public:
    GLFWwindow *window;
    int create_radius;
    int render_radius;
    int delete_radius;
    Player players[MAX_PLAYERS];
    int player_count;
    int typing;
    char typing_buffer[MAX_TEXT_LENGTH];
    int message_index;
    char messages[MAX_MESSAGES][MAX_TEXT_LENGTH];
    int width;
    int height;
    int observe1;
    int observe2;
    int flying;
    int item_index;
    int scale;
    int ortho;
    float fov;
    int suppress_char;
    int mode;
    int mode_changed;
    char db_path[MAX_PATH_LENGTH];
    char server_addr[MAX_ADDR_LENGTH];
    int server_port;
    int day_length;
    int time_changed;
    Block block0;
    Block block1;
    Block copy0;
    Block copy1;
};

#endif //CRAFT_MODEL_H
