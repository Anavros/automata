
#include <stdlib.h>     /* calloc() div() */
#include <stdio.h>
#include <unistd.h>     /* rand() */
#include <math.h>       /* log10() pow() */

#include "constants.h"  /* [OVER|UNDER|BIRTH]_POP BOARD_[W|H] RAND_CHANCE */
#include "logic.h"


/* Shortcut to calculate the index for a "2D" matrix that is actually 1D. */
int get_index(int row, int column) {
    return (row*BOARD_W) + column;
}

/* Allocates and memsets a new chunk of memory.
 * Takes board dimensions from constants.h.
 */
int *create_board(void) {
    int *board = calloc(sizeof(int), BOARD_W*BOARD_H);
    return board;
}

int num_digits(int n) {
    return (int) floor(log10((double) n))+1;
}

int digit_included(int n, int m) {
    if(m < 10) {
        return n == m;
    }
    int m_len = num_digits(m);
    char digit_string[m_len+1];
    snprintf(digit_string, m_len+1, "%d", m);
    int i; for(i=0; i<m_len; i++) {
        if(n+'0' == digit_string[i]) {
            return 1;
        }
    }
    return 0;
}

void seed(int *cell_board) {
    int x; for(x=0; x<BOARD_W; x++) {
        int y; for(y=0; y<BOARD_W; y++) {
            cell_board[get_index(x, y)] = (rand()%RAND_CHANCE)==1? 10:0;
        }
    }
}

void step(int *cell_board) {
    int x; for(x=0; x<BOARD_W; x++) {
        int y; for(y=0; y<BOARD_W; y++) {
            int index = get_index(x, y);
            int value = cell_board[index];
            // format for cell value is number of neighbors + 10 if alive
            div_t n = div(value, 10);
            int alive = n.quot;
            int neigh = n.rem;
            if(alive) {
                /* check if we should kill it */
                if(!digit_included(neigh, LIVE_NS)) {
                    //printf("killing cell\n");
                    cell_board[index] = neigh;
                }
            } else {
                /* check if we should spawn it */
                if(digit_included(neigh, BORN_NS)) {
                    //printf("birthing cell\n");
                    cell_board[index] = neigh+10;
                }
            } // if/else
        } // y
    } // x
} // step

void recount(int *cell_board) {
    int x; for(x=0; x<BOARD_W; x++) {
        int y; for(y=0; y<BOARD_W; y++) {

            int value = 0;
            int i; for(i=-1; i<=1; i++) {
                int j; for(j=-1; j<=1; j++) {
                    /* verify we're not outside the board */
                    if(x+i < 0 || y+j < 0 || x+i >= BOARD_W || y+j >= BOARD_H) {
                        continue;
                    } else {
                        if(cell_board[get_index(x+i, y+j)] >= 10) value++;
                    } // if-else
                } // j
            } // i
            if(cell_board[get_index(x, y)] >= 10) // cell is alive
                value += 9; // minus one for the false positive in the center
            cell_board[get_index(x, y)] = value;
        } // y
    } // x
}
