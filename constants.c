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
int BORN_NS = 3;
int LIVE_NS = 23;

int RAND_CHANCE = 20; // higher values have lower chances (rand()%chance == 1)

// XXX: if the window is 500x500 and this is 200x200, a large part of the
// window will be black instead of the board stretching to fit.
int BOARD_W = 400;
int BOARD_H = 400;
