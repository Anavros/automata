
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

void run(SDL_Window *window, int *board) {
    int status = 0;
    int paused = 0;
    int start_time;
    int delta_time;
    for(;;) {
        //frame_count++;
        start_time = SDL_GetTicks();

        /* Update the simulation. */
        if(!paused) {
            step(board);
            recount(board);
        }

        /* Render the board to the screen. */
        SDL_Surface *board_image = render_board(board);
        update_sdl(window, board_image);
        free_surface(board_image);

        /* Maintain a constant FPS. */
        delta_time = SDL_GetTicks() - start_time;
        delay_to_maintain_fps(delta_time);

        /* Return with a key code after any key is pressed. */
        status = get_input();
        if(status == 1) paused = paused? 0:1;
        else if(status == -1) break;
    };
}

int main(int argc, char** argv) {
    set_parameters(argc, argv);
    srand(time(NULL));
    SDL_Window *window = start_sdl();
    int *board = create_board();

    /* Set up the initial board with a random seed. */
    seed(board);
    recount(board);

    /* Run the simulation and toggle pause when the spacebar is pressed. */
    run(window, board);

    /* Clean up. */
    free(board);
    end_sdl(window);

    return 0;
}
