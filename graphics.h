
#ifndef GRAPHICS_H
#define GRAPHICS_H

SDL_Window *start_sdl(int width, int height, char* title);
SDL_Surface *render_board();
void update_sdl();
void free_surface(SDL_Surface *surface);
void end_sdl(SDL_Window *window);

#endif
