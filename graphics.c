

#include <stdlib.h>
#include "SDL.h"

#include "constants.h"
#include "graphics.h"
#include "logic.h"      /* get_index() */
#include "board.h"      // board

/* may return NULL if initialization fails */
/* uses constants found in constants.h */
SDL_Window *start_sdl(int width, int height) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow(
        TITLE, WIN_X, WIN_Y,
        width,
        height,
        SDL_WINDOW_OPENGL
    );
    return window;
}

int get_cell_color(int value, SDL_PixelFormat *format) {
    div_t n = div(value, 10);
    int alive = n.quot;
    int neigh = n.rem;
    int color = 80+(10*neigh)+(alive? 95:0);
    return SDL_MapRGB(format, color, color-10, color-20);
}

void render_board(Board* b, SDL_Window* window) {
    SDL_Surface *surface;
    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    surface = SDL_CreateRGBSurface(
        0,
        globalconfig.PIXEL_W,
        globalconfig.PIXEL_H,
        WIN_D, 0, 0, 0, 0
    );
    SDL_Rect box;
    box.w = box.h = globalconfig.TILE_SIZE;
    int x; for(x=0; x < b->height; x++) {
        int y; for(y=0; y < b->width; y++) {
            box.x = x*globalconfig.TILE_SIZE;
            box.y = y*globalconfig.TILE_SIZE;
            int color = get_cell_color(
                b->data[board.in(x, y, b->width)], surface->format);
            SDL_FillRect(surface, &box, color);
        }
    }
    SDL_BlitSurface(surface, NULL, window_surface, NULL);
    SDL_UpdateWindowSurface(window);
    SDL_FreeSurface(surface);
    SDL_FreeSurface(window_surface);
}

void end_sdl(SDL_Window *window) {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
