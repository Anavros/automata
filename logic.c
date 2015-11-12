
#include <stdlib.h>     /* calloc() */
#include <getopt.h>     /* getopt_long() */
#include <unistd.h>     /* rand() */

#include "constants.h"  /* [OVER|UNDER|BIRTH]_POP BOARD_[W|H] RAND_CHANCE */
#include "logic.h"


int *create_board() {
    int *board = calloc(sizeof(int), BOARD_W*BOARD_H);
    return board;
}

/* Could I create a generic function to touch all elements of the board? */
/* Takes a generic function of the form "void *func(int *cell);" */
void map_over_cells(int *board, void (*function)(int*)) {
    int x; for(x=0; x<BOARD_W; x++) {
        int y; for(y=0; y<BOARD_H; y++) {
            int *cell = &board[ (x*BOARD_W)+y ];
            function(cell);
        }
    }
}

/* Return a list of cell values (ints). */
/* Reads the type of neighborhood from constants. */
/* XXX Should protect against segfaults! */
/* Includes the center cell's value! */
int *get_neighbor_values(int *board, int row, int column) {
    switch(HOOD) {
    case Neighborhood.Moore:
        int values[8];
        int x, y;
        for(x = -1; x <= 1; x++) {
            for(y = -1; y <= 1; y++) {

                // 0 0 0 0 0 0 0
                // 0 1 1 1 1 1 0
                // 0 1 1 1 1 1 0
                // 0 1 1 1 1 1 0
                // 0 1 1 1 1 1 0
                // 0 1 1 1 1 1 0
                // 0 0 0 0 0 0 0

                int index = (row*BOARD_W) + column;
                index += y + (x*BOARD_W);
            }
        }
        break;
    case Neighborhood.Neumann:
        break;
    }
}

// XXX could be expanded for multiple possible values
void seed_cell(int *cell) {
    int r = rand() % RAND_CHANCE;
    int n = r==1 ? 1 : 0;
    *cell = n; // XXX watch out for segfaults here!
}

/* Initially, I am only going to implement simple game of life rules. */
/* After the program is stable and working I will get more complicated. */
void step_cell(int *cell) {
    //pass
}


/* Parse argv and return a struct representing the program's parameters */
void set_parameters(int argc, char**argv) {

    int c, index;
    struct option long_options[4] = {  // oh my god did that actually work
        {"over-population", required_argument, 0, 'c'},
        {"under-population", required_argument, 0, 'u'},
        {"birth-population", required_argument, 0, 'b'}
    };

    do {
        c = getopt_long(argc, argv, "o:u:b:", long_options, &index);
        switch(c) {
        case 'o':
            OVER_POP = atoi(optarg); 
            break; //TODO switch atoi to something safer
        case 'u':
            UNDER_POP = atoi(optarg);
            break;
        case 'b':
            BIRTH_POP = atoi(optarg);
            break;
        }
    } while(c != -1);
}
