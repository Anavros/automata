
#include <stdlib.h>
#include <getopt.h>     /* getopt_long() */

#include "constants.h"  /* [OVER|UNDER|BIRTH]_POP Board BOARD_[W|H]*/
#include "logic.h"


void create_board() { }

void step(Board *board) { }

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
