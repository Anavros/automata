
#include <stdlib.h>
#include <getopt.h>     /* getopt_long() */

#include "logic.h"


/* TODO: organize this a bit better */
/* Set to defaults, can be overriden by program arguments */
int OVER = 3;
int UNDER = 2;
int BIRTH = 3;

enum Neighborhood {Moore, Neumann};
Neighborhood HOOD = Moore;

struct Board {  // Will this cause problems if the typedef is in logic.h?
    int *array; 
    int width; 
    int height; 
};

/* for getopt_long() */
struct option long_options[4] = {  // oh my god did that actually work
    {"over-population", required_argument, 0, 'c'},
    {"under-population", required_argument, 0, 'u'},
    {"birth-population", required_argument, 0, 'b'}
};

/* Parse argv and return a struct representing the program's parameters */
void set_parameters(int argc, char**argv) {
    int c, index;
    do {
        c = getopt_long(argc, argv, "o:u:b:", long_options, &index);
        switch(c) {
        case 'o':
            OVER = atoi(optarg); 
            break; //TODO switch atoi to something safer
        case 'u':
            UNDER = atoi(optarg);
            break;
        case 'b':
            BIRTH = atoi(optarg);
            break;
        }
    } while(c != -1);
}

Board *create_board(int width, int height) {
    Board *board = malloc(sizeof(*board));
    board->array = 0; // How to do this?
    board->width = width;
    board->height = height;
    return board;
}

void step(Board *board) { }
