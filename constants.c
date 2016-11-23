/* constants.c */

#include "constants.h"

char *TITLE = "Automata";
int WIN_D = 16;
int WIN_X = 50;
int WIN_Y = 50;

struct ConfigNamespace globalconfig = {
    2,
    100,
    50, // if height is less than width, all sorts of problems
    200, // overwritten in set_parameters in main.c
    100,
    30,
    20,
    3,
    23,
};
