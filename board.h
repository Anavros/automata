
#ifndef AUTOMATA_BOARD_H
#define AUTOMATA_BOARD_H

Board * create_board(int, int);
void destroy_board(Board *);
void seed_board(int, Board *);
void step_board(Board *);
void recount_board(Board *);
Cell * get_cell(int, int, Board *);
void put_cell(Cell *, int, int, Board *);

#endif
