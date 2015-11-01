
#include <stdio.h>      /* printf() */
#include <stdlib.h>
#include <unistd.h>     /* sleep() */
#include <getopt.h>     /* getopt_long() */

#include "SDL.h"
#include "logic.h"
#include "graphics.h"
#include "input.h"

#define DEBUG 1

/* Constants; can be changed on startup */
char *TITLE = "Automata";
int WIN_W = 320;
int WIN_H = 240;

/* experimenting with structs in more depth */
struct Parameters {
    enum {Moore, Neumann, Extended} neighborhood;
    int over_population;
    int under_population;
    int birth_population; 
}; typedef struct Parameters Parameters;

/* for getopt_long() */
struct option long_options[4] = {  // oh my god did that actually work
    {"over-population", required_argument, 0, 'c'},
    {"under-population", required_argument, 0, 'u'},
    {"birth-population", required_argument, 0, 'b'}
};


/* Parse argv and return a struct representing the program's parameters */
Parameters *get_parameters(int argc, char**argv) {
    Parameters *result = malloc(sizeof(*result)); // Is this the right size?

    int c, index;
    do {
        c = getopt_long(argc, argv, "o:u:b:", long_options, &index);
        switch(c) {
        case 'o':
            if(DEBUG) printf("Setting 'over-population' to %s\n", optarg);
            result->over_population = atoi(optarg); 
            break; //TODO switch atoi to something safer
        case 'u':
            if(DEBUG) printf("Setting 'under-population' to %s\n", optarg);
            result->under_population = atoi(optarg);
            break;
        case 'b':
            if(DEBUG) printf("Setting 'birth-population' to %s\n", optarg);
            result->birth_population = atoi(optarg);
            break;
        }
        //printf("I'm being helpful!\n"); //XXX
    } while(c != -1);

    return result;
}


int main(int argc, char** argv) {
    printf("Hi there!\n");

    Parameters *para = get_parameters(argc, argv);
    printf("u: %i o: %i b: %i\n", 
        para->under_population, para->over_population, para->birth_population);
    free(para);

    SDL_Window *window = start_sdl(WIN_W, WIN_H, TITLE);
    sleep(1); // TODO: add input processing
    end_sdl(window);

    return 0;
}
