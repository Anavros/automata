/* board.c */

#include <stdlib.h>     // malloc
#include <unistd.h>     // rand
#include "constants.h"  // Board, Cell

#include "board.h"
#include "logic.h"      // digit_included

/* Allocate a new board with data and return the pointer. */
static Board * create(int width, int height) {
    Board *b = malloc(sizeof(Board));
    b->data = malloc(sizeof(int)*width*height);
    b->width = width;
    b->height = height;
    return b;
}

/* Free the board and its data. */
static void destroy_board(Board *b) {
    free(b->data);
    free(b);
}

static int in(int row, int col, int width) {
    return row*width + col;
}

static Cell * get_cell(int row, int col, Board *b) {
    int packed_value = b->data[in(row, col, b->width)];
    Cell *c = malloc(sizeof(Cell));
    c->alive = packed_value%10;
    c->direction = 0;
    return c;
}

static void put_cell(Cell *c, int row, int col, Board *b) {
    int *ptr = &b->data[ in(row, col, b->width) ];
    int packed_value = (c->alive*10) + (c->direction*100);
    *ptr = packed_value;
}


// TODO: improve and maybe outsource
// TODO: consider values other than 1 or 0
/* Randomly set cells to be alive for a starting state. */
static void seed_board(int density, Board *b) {
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

static void step_board(Board* b) {
    int x; for(x=0; x<b->width; x++) {
        int y; for(y=0; y<b->height; y++) {
            int i = in(x, y, b->width);
            int value = b->data[i];

            // format for cell value is number of neighbors + 10 if alive
            div_t n = div(value, 10);
            int alive = n.quot;
            int neigh = n.rem;
            if(alive) {
                /* check if we should kill it */
                if(!digit_included(neigh, SURVIVAL_VALUES)) {
                    b->data[i] = neigh;
                }
            } else {
                /* check if we should spawn it */
                if(digit_included(neigh, BIRTH_VALUES)) {
                    b->data[i] = neigh+10;
                }
            }
        } // y
    } // x
}

static void recount_board(Board* b) {
    int x; for(x=0; x<b->width; x++) {
        int y; for(y=0; y<b->height; y++) {

            int value = 0;
            int i; for(i=-1; i<=1; i++) {
                int j; for(j=-1; j<=1; j++) {
                    int dx = x+i;
                    int dy = y+j;
                    /* verify we're not outside the board */
                    if(dx == -1) { // it's only the sides that crash!
                        dx = b->width-1;
                    } else if(dx == b->width) {
                        dx = 0;
                    }
                    if(dy == -1) {
                        dy = b->height-1;
                    } else if(dy == b->height) {
                        dy = 0;
                    }
                    if(b->data[in(dx, dy, b->width)] >= 10) {
                        value++;
                    }
                } // j
            } // i
            if(b->data[in(x, y, b->width)] >= 10) // cell is alive
                value += 9; // minus one for the false positive in the center
            b->data[in(x, y, b->width)] = value;
        } // y
    } // x
}

struct BoardNamespace const board = {
    create,
    destroy_board,
    seed_board,
    step_board,
    recount_board,
    in,
    get_cell,
    put_cell
};
