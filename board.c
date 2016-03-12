/* board.c */

#include <stdlib.h>     // malloc
#include <unistd.h>     // rand
#include "constants.h"  // Board, Cell

#include "board.h"

// TODO: integrate cell.c into this file?

/* Allocate a new board with data and return the pointer. */
Board * create_board(int width, int height) {
    Board *b = malloc(sizeof(Board));
    b->data = malloc(sizeof(int)*width*height);
    b->width = width;
    b->height = height;
    return b;
}

/* Free the board and its data. */
void destroy_board(Board *b) {
    free(b->data);
    free(b);
}

int board_index(int row, int col, int width) {
    return row*width + col;
}

Cell * get_cell(int row, int col, Board *b) {
    int packed_value = b->data[board_index(row, col, b->width)];
    Cell *c = malloc(sizeof(Cell));
    c->alive = packed_value%10;
    c->direction = 0;
}

void put_cell(Cell *c, int row, int col, Board *b) {
    int *ptr = &b->data[ board_index(row, col, b->width) ];
    int packed_value = (c->alive*10) + (c->direction*100);
    *ptr = packed_value;
}


// TODO: improve and maybe outsource
// TODO: consider values other than 1 or 0
/* Randomly set cells to be alive for a starting state. */
void seed_board(int density, Board *b) {
    int x, y;
    for(x=0; x<b->width; x++) {
        for(y=0; y<b->height; y++) {
            Cell *c = get_cell(x, y, b);
            c->alive = (rand()%density == 1)? 1:0;
            put_cell(c, x, y, b);
            free(c);
        } // y
    } // x
}

void step_board(Board *);
void recount_board(Board *);
