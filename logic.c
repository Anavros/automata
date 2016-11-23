/* logic.c */

#include <stdlib.h>     // calloc(), div()
#include <stdio.h>
#include <unistd.h>     // rand()
#include <math.h>       // log10(), pow()

#include "constants.h"  // Program Parameters

#include "logic.h"


int num_digits(int n) {
    return (int) floor(log10((double) n))+1;
}

int digit_included(int n, int m) {
    if(m < 10) {
        return n == m;
    }
    int m_len = num_digits(m);
    char digit_string[m_len+1];
    snprintf(digit_string, m_len+1, "%d", m);
    int i; for(i=0; i<m_len; i++) {
        if(n+'0' == digit_string[i]) {
            return 1;
        }
    }
    return 0;
}
