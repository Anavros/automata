
#ifndef LOGIC_H
#define LOGIC_H

void set_parameters(int argc, char**argv);
int *create_board();
void seed_board(int *board);
void step(int *board);

#endif
