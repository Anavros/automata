
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>     /* getopt_long() */

#include "logic.h"

/* experimenting with structs in more depth */
struct Parameters {
    int test;
    enum {Moore, Neumann, Extended} neighborhood;
    int over_population;
    int under_population;
    int birth_population; 
}; typedef struct Parameters Parameters;

/* for getopt_long() */
struct option *long_options = {
    {"over-population", required_argument, 0, 'c'},
    {"under-population", required_argument, 0, 'u'},
    {"birth-population", required_argument, 0, 'b'}
};

/* Parse argv and return a struct representing the program's parameters */
Parameters *get_parameters(int argc, char**argv) {
    Parameters *result = malloc(sizeof(*result)); // Is this the right size?

    int c, index;
    do {
        c = getopt_long(argc, argv, "to:u:b:", long_options, &index);
        printf("I'm being helpful!\n");
    } while(c != -1);



/*
    int x; while( (x = getopt(argc, argv, "tac:")) != -1) switch(x) {
        case 't':
            result->test = 5;
            break;
        default:
            result->test = 0;
            break;
    }
*/
    return result;
}

int main(int argc, char** argv) {
    printf("Hi there!\n");

    Parameters *para = get_parameters(argc, argv);
    printf("Test: %i\n", para->test);
    free(para);
    return 0;
}
