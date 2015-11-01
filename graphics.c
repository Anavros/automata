
//#include "logic.h" // for Board; I don't know if this is bad or not
/* I might do a single header for constant values */
/* I don't know where it would stop, though. Do I include a source file with
 * their values too? Or only the extern declarations? */
#include "SDL.h"

int WINDOW_X = 50;
int WINDOW_Y = 50;

/* May return NULL if initialization fails */
SDL_Window *start_sdl(int width, int height, char* title) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow(
        title, WINDOW_X, WINDOW_Y, width, height, SDL_WINDOW_OPENGL);

    return window;
}

SDL_Surface *render_board(int win_w, int win_h, int win_d) { // TODO: add Board
    SDL_Surface *surface;
    surface = SDL_CreateRGBSurface(0, win_w, win_h, win_d, 0, 0, 0, 0);
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
