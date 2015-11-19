
#include <stdlib.h>     /* calloc() */
#include <stdio.h>//XXX
#include <getopt.h>     /* getopt_long() */
#include <unistd.h>     /* rand() */

#include "constants.h"  /* [OVER|UNDER|BIRTH]_POP BOARD_[W|H] RAND_CHANCE */
#include "logic.h"


int get_index(int row, int column) {
    return (row*BOARD_W) + column;
}

int *create_board() {
    int *board = calloc(sizeof(int), BOARD_W*BOARD_H);
    return board;
}

int find_sum(int x, int y, int matrix[8][2], int* board) {
    int sum = 0;
    int len = 18; // TODO
    //printf("len = %i", len);
    int n; for(n=0; n<len/2; n++) {
        //printf(" %i\n", n);
        int dx = x + matrix[n][0];
        int dy = y + matrix[n][1];
        //printf(" dx: %i; dy: %i;\n ", dx, dy);
        //printf(" mx: %i; my: %i;\n ", matrix[n][0], matrix[n][1]);

        /* verify we're not outside the board */
        if(dx < 0 || dy < 0 || dx > BOARD_W || dy > BOARD_H) {
            printf("Vetted cell; (%i, %i) is outside allowed range.\n", dx, dy);
            continue;
        } else {
            printf("Passed cell; (%i, %i) has value %i.\n", dx, dy, 
                board[get_index(dx, dy)]);
            sum += board[get_index(dx, dy)];
        }
    }
    printf("sum = %i\n", sum);
    return sum;
}

/* Return a *new* board where every cell is replaced with the value of its neighbors. */
int *create_value_board(int *board) {
    int *value_board = create_board();

    /* TODO: add support for other neighborhood types */
    int moore_matrix[8][2] = { 
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1} 
    };

    int row, column;
    for(row=0; row<BOARD_W; row++) {
        for(column=0; column<BOARD_W; column++) {
            value_board[get_index(row, column)] = 
                find_sum(row, column, moore_matrix, board);

            //printf(" %i", value_board[get_index(row, column)]);
        }
        //printf("\n");
    }
    return value_board; // don't forget to free()!
}

/* Takes a generic function of the form "void *func(int *cell);" */
void map_over_cells(int *board, void (*function)(int*)) {
    int x; for(x=0; x<BOARD_W; x++) {
        int y; for(y=0; y<BOARD_H; y++) {
            int *cell = &board[ (x*BOARD_W)+y ];
            function(cell);
        }
    }
}

// XXX could be expanded for multiple possible values
void seed_cell(int *cell) {
    int r = rand() % RAND_CHANCE;
    int n = r==1 ? 1 : 0;
    *cell = n; // XXX watch out for segfaults here!
}

void step(int *cell_board) {
    int *value_board = create_value_board(cell_board);
    int x; for(x=0; x<BOARD_W; x++) {
        int y; for(y=0; y<BOARD_W; y++) {
            int index = get_index(x, y);
            int cell_value = cell_board[index];
            int neighbors_value = value_board[index];

                    cell_board[index] = 1;
                    cell_board[index] = 0;

            switch(cell_value) {
            case (0):
                if(neighbors_value == BIRTH_POP) {
                    cell_board[index] = 1;
                }
                break;
            case (1):
                if(neighbors_value <= UNDER_POP || neighbors_value >= OVER_POP) {
                    cell_board[index] = 0;
                }
                break;
            default:
                break;
            }
        }
    }
    free(value_board);
}


/* Set program constants according to arguments. */
void set_parameters(int argc, char**argv) {

    int c, index;
    struct option long_options[4] = {
        {"over-population", required_argument, 0, 'c'},
        {"under-population", required_argument, 0, 'u'},
        {"birth-population", required_argument, 0, 'b'}
    };

    do {
        c = getopt_long(argc, argv, "o:u:b:", long_options, &index);
        switch(c) {
        case 'o':
            OVER_POP = atoi(optarg); 
            break; //TODO switch atoi to something safer
        case 'u':
            UNDER_POP = atoi(optarg);
            break;
        case 'b':
            BIRTH_POP = atoi(optarg);
            break;
        }
    } while(c != -1);
}
