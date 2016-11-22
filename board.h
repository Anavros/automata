
#ifndef AUTOMATA_BOARD_H
#define AUTOMATA_BOARD_H

Board * BD_create_board(int, int);
void BD_destroy_board(Board *);
void BD_seed_board(int, Board *);
void BD_step_board(Board *);
void BD_recount_board(Board *);
Cell * BD_get_cell(int, int, Board *);
void BD_put_cell(Cell *, int, int, Board *);

struct BoardNamespace {
    //Board;
    //Cell;
    Board* (*BD_create_board)(int, int);
    void (*BD_destroy_board)(Board*);
    void (*BD_seed_board)(int, Board*);
    void (*BD_step_board)(Board*);
    void (*BD_recount_board)(Board*);
    Cell* (*BD_get_cell)(int, int, Board*);
    void (*BD_put_cell)(Cell*, int, int, Board*);
};
extern struct BoardNamespace const board;

#endif
