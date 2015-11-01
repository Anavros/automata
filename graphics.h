
#ifndef GRAPHICS_H
#define GRAPHICS_H

SDL_Window *start_sdl();
SDL_Surface *render_board();
void update_sdl(SDL_Window *window, SDL_Surface *surface);
void free_surface(SDL_Surface *surface);
void end_sdl(SDL_Window *window);

#endif
