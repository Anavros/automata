
#ifndef GRAPHICS_H
#define GRAPHICS_H

SDL_Window *start_sdl(int, int);
void render_board(Board* board, SDL_Window *window);
void end_sdl(SDL_Window *window);

#endif
