
#ifndef GRAPHICS_H
#define GRAPHICS_H

SDL_Window *start_sdl(void);
void render_board(int* board, SDL_Window *window);
void render_new_board(Board* board, SDL_Window *window);
void end_sdl(SDL_Window *window);

#endif
