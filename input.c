
#include "SDL.h"

#include "constants.h"
#include "input.h"

int get_input() {
    /* Return Codes:
     * -1   Quit
     *  0   Continue
     *  1   Toggle Pause
     */
    int status = 0;
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                status = -1;
                break;
            case SDL_KEYDOWN:
                status = (event.key.keysym.sym==SDLK_SPACE)? 1:-1;
                break;
            default:
                break;
        }
    }
    return status;
}
