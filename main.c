/* main.c */

#include <stdio.h>      /* printf() */
//#include <stdlib.h>
#include <unistd.h>     /* sleep() srand() */
#include <time.h>       /* time() */
#include <getopt.h>     /* getopt_long required_argument option */

#include "SDL.h"

#include "constants.h"  // globalconfig (various other constants)
#include "graphics.h"
#include "input.h"
#include "board.h"      // board

/* Set program constants according to arguments. */
void set_parameters(int argc, char**argv) {

    int c, index;
    struct option long_options[8] = {
        {"width",               required_argument, 0, 'w'},
        {"height",              required_argument, 0, 'h'},
        {"survive",             required_argument, 0, 's'},
        {"birth",               required_argument, 0, 'b'},
        {"frames-per-second",   required_argument, 0, 'f'},
        {"seed-density",        required_argument, 0, 'r'},
        {"cell-size",           required_argument, 0, 'c'}
    };

    do {
        c = getopt_long(argc, argv, "w:h:s:b:f:r:c:", long_options, &index);
        switch(c) {
        case 'w':
            // TODO: bring in the better int casting function
            globalconfig.BOARD_W = atoi(optarg);
            break;
        case 'h':
            globalconfig.BOARD_H = atoi(optarg);
            break;
        case 'c':
            globalconfig.TILE_SIZE = atoi(optarg);
            break;
        case 's':
            globalconfig.SURVIVAL = atoi(optarg);
            break;
        case 'b':
            globalconfig.BIRTH = atoi(optarg);
            break;
        case 'f':
            globalconfig.FPS = atoi(optarg);
            break;
        case 'r':
            globalconfig.SEED_DENSITY = atoi(optarg);
            break;
        }
    } while(c != -1);
    globalconfig.PIXEL_W = globalconfig.BOARD_W * globalconfig.TILE_SIZE;
    globalconfig.PIXEL_H = globalconfig.BOARD_H * globalconfig.TILE_SIZE;
}

/* Wait n milliseconds so that (n + exec_time) is equal to the desired max framerate. */
void delay_to_maintain_fps(int exec_time) {
    int total = 1000/globalconfig.FPS;
    int down_time = total - exec_time;
    if(down_time>0) {
        SDL_Delay(down_time);
    }
}

int run(SDL_Window* window, Board* b) {
    int status = 0;
    int paused = 0;
    int start_time;
    int delta_time;
    for(;;) {
        //frame_count++;
        start_time = SDL_GetTicks();

        /* Update the simulation given it's not paused. */
        if(!paused) {
            board.step(b);
            board.recount(b);
            render_board(b, window);
        }

        /* Maintain a constant FPS. */
        delta_time = SDL_GetTicks() - start_time;
        delay_to_maintain_fps(delta_time);

        /* Toggle pause if the spacebar has been pressed. */
        /* All other keys will end the program. */
        status = get_input();
        if(status == 1) paused = paused? 0:1;
        else if(status == -1 || status == 2) break;
    }
    return status;
}

int main(int argc, char** argv) {
    set_parameters(argc, argv);
    srand(time(NULL));
    SDL_Window *window = start_sdl(globalconfig.PIXEL_W, globalconfig.PIXEL_H);
    Board* b = board.create(globalconfig.BOARD_W, globalconfig.BOARD_H);

    /* Set up the initial board with a random seed and send it off. */
    for(;;) {
        // Every time the program is reset with 'r', the inner loop in run()
        // terminates and control comes back up here.
        board.seed(globalconfig.SEED_DENSITY, b);
        board.recount(b);
        if(run(window, b) != 2) break;
    }

    /* Clean up. */
    board.destroy(b);
    end_sdl(window);

    return 0;
}
