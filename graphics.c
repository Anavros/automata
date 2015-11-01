
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

SDL_Surface *render_board();

void update_sdl();

void free_surface(SDL_Surface *surface) {
    SDL_FreeSurface(surface);
}

void end_sdl(SDL_Window *window) {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
