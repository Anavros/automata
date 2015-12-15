
#include "SDL.h"

#include "constants.h"  /* TITLE WIN_[X|Y|W|H] */
#include "graphics.h"

/* may return NULL if initialization fails */
/* uses constants found in constants.h */
SDL_Window *start_sdl(void) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow(
        TITLE, WIN_X, WIN_Y, WIN_W, WIN_H, SDL_WINDOW_OPENGL);

    return window;
}

SDL_Surface *render_board(int *board) {
    SDL_Surface *surface;
    surface = SDL_CreateRGBSurface(0, WIN_W, WIN_H, WIN_D, 0, 0, 0, 0);

    int color_1 = SDL_MapRGB(surface->format, 200, 200, 200);
    int color_0 = SDL_MapRGB(surface->format, 100, 100, 100);

    SDL_Rect box;
    box.w = WIN_W / BOARD_W;
    box.h = WIN_H / BOARD_H;
    int x; for(x=0; x<BOARD_W; x++) {
        int y; for(y=0; y<BOARD_H; y++) {
            box.x = x*box.w;
            box.y = y*box.h;

            int color;
            //printf("segfaults ahead!\n");
            //printf("...trying to access board at %i\n", (x*BOARD_W)+y);
            if(board[ (x*BOARD_W)+y ] == 1) { color = color_1; }
            else { color = color_0; }

            SDL_FillRect(surface, &box, color);
        }
    }
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
