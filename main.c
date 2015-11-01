
#include <stdio.h>      /* printf() */
#include <stdlib.h>
#include <unistd.h>     /* sleep() */

#include "SDL.h"
#include "logic.h"
#include "graphics.h"
#include "input.h"

/* constants; can be changed on startup */
char *TITLE = "Automata";
int WIN_W = 320;
int WIN_H = 240;
int WIN_D = 32;

int main(int argc, char** argv) {
    set_parameters(argc, argv);
    SDL_Window *window = start_sdl(WIN_W, WIN_H, TITLE);

    do {
        SDL_Surface *board = render_board(WIN_W, WIN_H, WIN_D);
        update_sdl(window, board);
        sleep(1); // TODO: add input processing TODO: also fps
        free_surface(board);
    } while(!any_key_pressed());

    end_sdl(window);

    return 0;
}
