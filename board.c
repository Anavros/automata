/* board.c */

#include <stdlib.h>     // malloc
#include <unistd.h>     // rand
#include "constants.h"  // Board, Cell

#include "board.h"

// TODO: integrate cell.c into this file?

/* Allocate a new board with data and return the pointer. */
Board * BD_create_board(int width, int height) {
    Board *b = malloc(sizeof(Board));
    b->data = malloc(sizeof(int)*width*height);
    b->width = width;
    b->height = height;
    return b;
}

/* Free the board and its data. */
void BD_destroy_board(Board *b) {
    free(b->data);
    free(b);
}

int BD_board_index(int row, int col, int width) {
    return row*width + col;
}

Cell * BD_get_cell(int row, int col, Board *b) {
    int packed_value = b->data[BD_board_index(row, col, b->width)];
    Cell *c = malloc(sizeof(Cell));
    c->alive = packed_value%10;
    c->direction = 0;
}

void BD_put_cell(Cell *c, int row, int col, Board *b) {
    int *ptr = &b->data[ BD_board_index(row, col, b->width) ];
    int packed_value = (c->alive*10) + (c->direction*100);
    *ptr = packed_value;
}


// TODO: improve and maybe outsource
// TODO: consider values other than 1 or 0
/* Randomly set cells to be alive for a starting state. */
void BD_seed_board(int density, Board *b) {
    int x, y;
    for(x=0; x<b->width; x++) {
        for(y=0; y<b->height; y++) {
            Cell *c = BD_get_cell(x, y, b);
            c->alive = (rand()%density == 1)? 1:0;
            BD_put_cell(c, x, y, b);
            free(c);
        } // y
    } // x
}

void BD_step_board(Board* b) {}
void BD_recount_board(Board* b) {}


struct BoardNamespace const board = {
    //Board;
    //Cell;
    BD_create_board,
    BD_destroy_board,
    BD_seed_board,
    BD_step_board,
    BD_recount_board,
    BD_get_cell,
    BD_put_cell
};
