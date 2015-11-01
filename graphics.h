
#ifndef GRAPHICS_H
#define GRAPHICS_H

SDL_Window *start_sdl(int width, int height, char* title);
SDL_Surface *render_board(int win_w, int win_h, int win_d);
void update_sdl(SDL_Window *window, SDL_Surface *surface);
void free_surface(SDL_Surface *surface);
void end_sdl(SDL_Window *window);

#endif
