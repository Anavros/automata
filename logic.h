
#ifndef AUTOMATA_LOGIC_H
#define AUTOMATA_LOGIC_H

int get_index(int row, int column);
int *create_board(void);
int find_sum(int x, int y, int matrix[8][2], int* board);
int *create_value_board(int *board);
void map_over_cells(int *board, void (*function)(int*));
void seed_cell(int *cell);
void step(int *board);

#endif
