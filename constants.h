
#ifndef AUTOMATA_CONSTANTS_H
#define AUTOMATA_CONSTANTS_H

typedef enum { Moore, Neumann } Neighborhood;

char *TITLE;
int WIN_W;
int WIN_H;
int WIN_D;
int WIN_X;
int WIN_Y;

int MAX_FPS;

int OVER_POP;
int UNDER_POP;
int BIRTH_POP;

int RAND_CHANCE;
Neighborhood HOOD;

int BOARD_W;
int BOARD_H;

#endif
