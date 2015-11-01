
//#include "logic.h" // for Board; I don't know if this is bad or not
/* I might do a single header for constant values */
/* I don't know where it would stop, though. Do I include a source file with
 * their values too? Or only the extern declarations? */
#include "SDL.h"
#include "constants.h"  /* TITLE WIN_[X|Y|W|H] Board */
#include "graphics.h"

/* may return NULL if initialization fails */
/* uses constants found in constants.h */
SDL_Window *start_sdl() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow(
        TITLE, WIN_X, WIN_Y, WIN_W, WIN_H, SDL_WINDOW_OPENGL);

    return window;
}

SDL_Surface *render_board(Board *board) {
    // TODO: board is unused
    SDL_Surface *surface;
    surface = SDL_CreateRGBSurface(0, WIN_W, WIN_H, WIN_D, 0, 0, 0, 0);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 200, 75, 75)); //Temp
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
