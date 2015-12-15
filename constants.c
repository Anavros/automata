/* constants.c */

#include "constants.h"

char *TITLE = "Automata";
int WIN_W = 800;
int WIN_H = 800;
int WIN_D = 16;
int WIN_X = 50;
int WIN_Y = 50;

int MAX_FPS = 10;

/* default sim parameters */
int OVER_POP = 4;
int UNDER_POP = 1;
int BIRTH_POP = 2;

int RAND_CHANCE = 2; // higher values have lower chances (rand()%chance == 1)

//typedef enum { Moore, Neumann } Neighborhood;
Neighborhood HOOD = Moore;

// XXX: if the window is 500x500 and this is 200x200, a large part of the
// window will be black instead of the board stretching to fit.
int BOARD_W = 400;
int BOARD_H = 400;
