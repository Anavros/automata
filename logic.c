
#include <stdlib.h>     /* calloc() */
#include <getopt.h>     /* getopt_long() */
#include <unistd.h>     /* rand() */

#include "constants.h"  /* [OVER|UNDER|BIRTH]_POP BOARD_[W|H]*/
#include "logic.h"


int *create_board() {
    int *board = calloc(sizeof(int), BOARD_W*BOARD_H);
    return board;
}

/* Could I create a generic function to touch all elements of the board? */
void seed_board(int *board) {
    int x; for(x=0; x<BOARD_W; x++) {
        int y; for(y=0; y<BOARD_H; y++) {
            int r = rand() % 20; // TODO set as global constant
            int n = r==1 ? 1 : 0;
            board[ (x*BOARD_W)+y ] = n;
        }
    }
}


void step(int *board) { }


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
