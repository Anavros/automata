
#include <stdio.h>      /* printf() */
//#include <stdlib.h>
#include <unistd.h>     /* sleep() srand() */
#include <time.h>       /* time() */

#include "SDL.h"

#include "constants.h"
#include "logic.h"
#include "graphics.h"
#include "input.h"

int main(int argc, char** argv) {
    set_parameters(argc, argv);
    srand(time(NULL));

    SDL_Window *window = start_sdl();
    int *board = create_board();
    map_over_cells(board, seed_cell);

    do {
        step(board);
        SDL_Surface *board_image = render_board(board);
        update_sdl(window, board_image);
        sleep(5); // TODO: add fps
        free_surface(board_image);
    } while(!any_key_pressed());

    free(board);
    end_sdl(window);

    return 0;
}
