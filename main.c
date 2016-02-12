
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
    struct option long_options[6] = {
        {"survive",             required_argument, 0, 's'},
        {"birth",               required_argument, 0, 'b'},
        {"frames-per-second",   required_argument, 0, 'f'},
        {"seed-density",        required_argument, 0, 'r'},
        {"cell-size",           required_argument, 0, 'c'}
    };

    do {
        c = getopt_long(argc, argv, "s:b:f:r:c:", long_options, &index);
        switch(c) {
        case 's':
            SURVIVAL_VALUES = atoi(optarg);
            break;
        case 'b':
            BIRTH_VALUES = atoi(optarg);
            break;
        case 'f':
            MAX_FPS = atoi(optarg);
            break;
        case 'r':
            RAND_CHANCE = atoi(optarg);
            break;
        case 'c':
            CELL_SIZE = atoi(optarg);
            BOARD_SIZE = 800/CELL_SIZE;
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

int run(SDL_Window *window, int *board) {
    int status = 0;
    int paused = 0;
    int start_time;
    int delta_time;
    for(;;) {
        //frame_count++;
        start_time = SDL_GetTicks();

        /* Update the simulation given it's not paused. */
        if(!paused) {
            step(board);
            recount(board);
        }

        /* Render the board to the screen. */
        render_board(board, window);

        /* Maintain a constant FPS. */
        delta_time = SDL_GetTicks() - start_time;
        delay_to_maintain_fps(delta_time);

        /* Toggle pause if the spacebar has been pressed. */
        /* All other keys will end the program. */
        status = get_input();
        if(status == 1) paused = paused? 0:1;
        else if(status == -1 || status == 2) break;
    };
    return status;
}

int main(int argc, char** argv) {
    set_parameters(argc, argv);
    srand(time(NULL));
    SDL_Window *window = start_sdl();
    int *board = create_board();

    /* Set up the initial board with a random seed and send it off. */
    restart:
    for(;;) {
        seed(board);
        recount(board);
        if(run(window, board) != 2) break;
    }

    /* Clean up. */
    free(board);
    end_sdl(window);

    return 0;
}
