
#ifndef GRAPHICS_H
#define GRAPHICS_H

SDL_Window *start_sdl(void);
SDL_Surface *render_board(int* board, SDL_Window *window);
void end_sdl(SDL_Window *window);

#endif
