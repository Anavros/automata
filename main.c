
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

int main(int argc, char** argv) {
    set_parameters(argc, argv);
    SDL_Window *window = start_sdl(WIN_W, WIN_H, TITLE);
    sleep(1); // TODO: add input processing
    end_sdl(window);

    return 0;
}
