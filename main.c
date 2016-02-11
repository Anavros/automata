
#include <stdio.h>      /* printf() */
//#include <stdlib.h>
#include <unistd.h>     /* sleep() srand() */
#include <time.h>       /* time() */
#include <getopt.h>     /* getopt_long() */

#include "SDL.h"

#include "constants.h"
#include "logic.h"
#include "graphics.h"
#include "input.h"

/* Set program constants according to arguments. */
void set_parameters(int argc, char**argv) {

    int c, index;
    struct option long_options[5] = {
        {"survive", required_argument, 0, 's'},
        {"birth", required_argument, 0, 'b'},
        {"frames-per-second", required_argument, 0, 'f'},
        {"seed-density", required_argument, 0, 'r'}
    };

    do {
        c = getopt_long(argc, argv, "s:b:f:r:", long_options, &index);
        switch(c) {
        case 's':
            LIVE_NS = atoi(optarg);
            break;
        case 'b':
            BORN_NS = atoi(optarg);
            break;
        case 'f':
            MAX_FPS = atoi(optarg);
            break;
        case 'r':
            RAND_CHANCE = atoi(optarg);
            break;
        }
    } while(c != -1);
}

/* Wait n milliseconds so that (n + exec_time) is equal to the desired max framerate. */
void delay_to_maintain_fps(int exec_time) {
    int total = 1000/MAX_FPS;
    int down_time = total - exec_time;
    if(down_time>0) {
        SDL_Delay(down_time);
    }
}

int main(int argc, char** argv) {
    set_parameters(argc, argv);
    srand(time(NULL));

    SDL_Window *window = start_sdl();
    int *board = create_board();
    seed(board);
    recount(board);

    do {
        int timer = SDL_GetTicks();

        step(board);
        recount(board);
        SDL_Surface *board_image = render_board(board);
        update_sdl(window, board_image);

        free_surface(board_image);

        // FPS maintenance
        int delta = SDL_GetTicks() - timer;
        delay_to_maintain_fps(delta);
    } while(!any_key_pressed());

    free(board);
    end_sdl(window);

    return 0;
}
