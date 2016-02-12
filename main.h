
#ifndef AUTOMATA_MAIN_H
#define AUTOMATA_MAIN_H

void set_parameters(int argc, char **argv);
void delay_to_maintain_fps(int exec_time);
int run(SDL_Window *window, int *board);
int main(int argc, char **argv);

#endif
