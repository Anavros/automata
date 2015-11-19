/* constants.c */

#include "constants.h"

char *TITLE = "Automata";
int WIN_W = 200;
int WIN_H = 200;
int WIN_D = 32;
int WIN_X = 50;
int WIN_Y = 50;

/* default sim parameters */
int OVER_POP = 3;
int UNDER_POP = 2;
int BIRTH_POP = 3;

int RAND_CHANCE = 2; // higher values have lower chances (rand()%chance == 1)

//typedef enum { Moore, Neumann } Neighborhood;
Neighborhood HOOD = Moore;

int BOARD_W = 20;
int BOARD_H = 20;
