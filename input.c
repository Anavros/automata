
#include "SDL.h"

#include "constants.h"
#include "input.h"

int get_input() {
    /* Return Codes:
     * -1   Quit
     *  0   Continue
     *  1   Toggle Pause
     *  2   Reset
     */
    int status = 0;
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                status = -1; break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
                    case SDLK_SPACE:
                        status = 1; break;
                    case SDLK_r:
                        status = 2; break;
                    default: 
                        status = -1; break;
                }
                break;
            default:
                break;
        }
    }
    return status;
}
