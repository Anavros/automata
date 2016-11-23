
#ifndef AUTOMATA_CONSTANTS_H
#define AUTOMATA_CONSTANTS_H

typedef enum { Moore, Neumann } Neighborhood;

char *TITLE;
int WIN_D;
int WIN_X;
int WIN_Y;

extern struct ConfigNamespace {
    int TILE_SIZE;
    int BOARD_W;
    int BOARD_H;
    int PIXEL_W;
    int PIXEL_H;
    int FPS;
    int SEED_DENSITY;
    int BIRTH;
    int SURVIVAL;
} globalconfig;

struct _Cell {
    int alive;          // 0-1
    int direction;      // 0-7
};
typedef struct _Cell Cell;

struct _Board {
    int width;
    int height;
    int * data;
};
typedef struct _Board Board;

#endif
