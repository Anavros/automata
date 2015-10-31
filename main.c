
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    int test;
} Parameters;

/* Parse argv and return a struct representing the program's parameters */
Parameters *get_parameters(int argc, char**argv) {
    Parameters *result = malloc(sizeof(*result)); // Is this the right size?
    int x; while( (x = getopt(argc, argv, "tac:")) != -1) switch(x) {
        case 't':
            result->test = 5;
            break;
        default:
            result->test = 0;
            break;
    }
    return result;
}

int main(int argc, char** argv) {
    printf("Hi there!\n");

    Parameters *para = get_parameters(argc, argv);
    printf("Test: %i\n", para->test);
    free(para);
    return 0;
}
