
#include <stdlib.h>
#include "logic.h"

struct Board {  // Will this cause problems if the typedef is in logic.h?
    int *array; 
    int width; 
    int height; 
};

Board *create_board(int width, int height) {
    Board *board = malloc(sizeof(*board));
    board->array = 0; // How to do this?
    board->width = width;
    board->height = height;
    return board;
}
