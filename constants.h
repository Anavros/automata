
#ifndef AUTOMATA_CONSTANTS_H
#define AUTOMATA_CONSTANTS_H

typedef enum { Moore, Neumann } Neighborhood;

char *TITLE;
int WIN_D;
int WIN_X;
int WIN_Y;

int CELL_SIZE;
int BOARD_SIZE;
int MAX_FPS;
int RAND_CHANCE;
int BIRTH_VALUES;
int SURVIVAL_VALUES;

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
