
#include <stdio.h>      /* printf() */
#include <stdlib.h>
#include <unistd.h>     /* sleep() */

#include "SDL.h"

#include "constants.h"
#include "logic.h"
#include "graphics.h"
#include "input.h"

int main(int argc, char** argv) {
    set_parameters(argc, argv);
    SDL_Window *window = start_sdl();

    do {
        SDL_Surface *board = render_board(board);
        update_sdl(window, board);
        sleep(1); // TODO: add input processing TODO: also fps
        free_surface(board);
    } while(!any_key_pressed());

    end_sdl(window);

    return 0;
}
