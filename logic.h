
#ifndef LOGIC_H
#define LOGIC_H

void set_parameters(int argc, char**argv);
int *create_board();
void map_over_cells(int *board, void (*function)(int*));
void seed_cell(int *cell);
void step(int *board);

#endif
