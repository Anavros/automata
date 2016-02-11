

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
        TITLE, WIN_X, WIN_Y, WIN_W, WIN_H, SDL_WINDOW_OPENGL);

    return window;
}

int get_cell_color(int value) {
    div_t n = div(value, 10);
    int alive = n.quot;
    int neigh = n.rem;
    return 64+(neigh*8)+(alive? 128:0);
}

SDL_Surface *render_board(int *board) {
    SDL_Surface *surface;
    surface = SDL_CreateRGBSurface(0, WIN_W, WIN_H, WIN_D, 0, 0, 0, 0);
    SDL_Rect box;
    box.w = WIN_W / BOARD_W;
    box.h = WIN_H / BOARD_H;
    int x; for(x=0; x<BOARD_W; x++) {
        int y; for(y=0; y<BOARD_H; y++) {
            box.x = x*box.w;
            box.y = y*box.h;
            int cc = get_cell_color(board[get_index(x, y)]);
            int color = SDL_MapRGB(surface->format, cc, cc, cc);
            SDL_FillRect(surface, &box, color);
        }
    }
    //free(value_board);
    //SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 200, 75, 75)); //Temp
    return surface;
}

/* blits and updates all in one */
void update_sdl(SDL_Window *window, SDL_Surface *surface) {
    SDL_Surface *window_surface = SDL_GetWindowSurface(window);
    SDL_BlitSurface(surface, NULL, window_surface, NULL);
    SDL_UpdateWindowSurface(window);
    SDL_FreeSurface(window_surface);
}

void free_surface(SDL_Surface *surface) {
    SDL_FreeSurface(surface);
}

void end_sdl(SDL_Window *window) {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
