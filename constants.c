/* constants.c */

#include "constants.h"

enum Neighborhood { Moore, Neumann };
//struct Board { int *array; int width; int height; };
//struct ColorMap { int value; int r; int g; int b; };

char *TITLE = "Automata";
int WIN_W = 320;
int WIN_H = 240;
int WIN_D = 32;
int WIN_X = 50;
int WIN_Y = 50;

/* default sim parameters */
int OVER_POP = 3;
int UNDER_POP = 2;
int BIRTH_POP = 3;
Neighborhood HOOD = Moore;

int BOARD_W = 20;
int BOARD_H = 20;
