
#ifndef LOGIC_H
#define LOGIC_H

struct Board;
typedef struct Board Board;  // This always strikes me as clunky

enum Neighborhood;
typedef enum Neighborhood Neighborhood;

void set_parameters(int argc, char**argv);
Board *create_board(int width, int height);
void step(Board *board);

#endif
