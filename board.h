
#ifndef AUTOMATA_BOARD_H
#define AUTOMATA_BOARD_H

extern struct BoardNamespace {
    Board* (*create)(int, int);
    void (*destroy)(Board*);
    void (*seed)(int, Board*);
    void (*step)(Board*);
    void (*recount)(Board*);
    int (*in)(int, int, int);  // change to take Board* for width
    Cell* (*get_cell)(int, int, Board*);
    void (*put_cell)(Cell*, int, int, Board*);
} const board;

#endif
