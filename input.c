
#include "SDL.h"

#include "constants.h"
#include "input.h"

int any_key_pressed() {
    int status = 0;
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                status = 1;
                break;
            case SDL_KEYDOWN:
                status = 1;
                break;
            default:
                break;
        }
    }
    return status;
}
