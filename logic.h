
#ifndef AUTOMATA_LOGIC_H
#define AUTOMATA_LOGIC_H

int get_index(int row, int column);
int *create_board(void);
int find_sum(int x, int y, int matrix[8][2], int* board);
int *create_value_board(int *board);
void seed(int *cell_board);
void recount(int *cell_board);
void step(int *cell_board);

int num_digits(int n);
int digit_included(int n, int ns);

#endif
