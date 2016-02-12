

#include<stdlib.h>
#include"SDL.h"

#include"constants.h"  /* TITLE WIN_[X|Y|W|H] */
#include"graphics.h"
#include"logic.h"      /* get_index() */

/* may return NULL if initialization fails */
/* uses constants found in constants.h */
SDL_Window *start_sdl(void) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow(
        TITLE, WIN_X, WIN_Y,
        CELL_SIZE*BOARD_SIZE, CELL_SIZE*BOARD_SIZE,
        SDL_WINDOW_OPENGL);

    return window;
}

int get_cell_color(int value, SDL_PixelFormat *format) {
    div_t n = div(value, 10);
    int alive = n.quot;
    int neigh = n.rem;
    int color = 80+(10*neigh)+(alive? 95:0);
    return SDL_MapRGB(format, color, color-10, color-20);
}

SDL_Surface *render_board(int *board, SDL_Window *window) {
    SDL_Surface *surface;
    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    surface = SDL_CreateRGBSurface(
        0, CELL_SIZE*BOARD_SIZE, CELL_SIZE*BOARD_SIZE, WIN_D, 0, 0, 0, 0);
    SDL_Rect box;
    box.w = box.h = CELL_SIZE;
    int x; for(x=0; x<BOARD_SIZE; x++) {
        int y; for(y=0; y<BOARD_SIZE; y++) {
            box.x = x*CELL_SIZE;
            box.y = y*CELL_SIZE;
            int color = get_cell_color(board[get_index(x, y)], surface->format);
            SDL_FillRect(surface, &box, color);
        }
    }
    SDL_BlitSurface(surface, NULL, window_surface, NULL);
    SDL_UpdateWindowSurface(window);
    SDL_FreeSurface(window_surface);
}

void end_sdl(SDL_Window *window) {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
