#include <stdio.h>

#define DOUBLE(x) 2*x
#define DOUBLEFIX(x) (2*(x))

int main(void) {
    printf("a: value should be 6 but it is 4. check %d\n", DOUBLE(1+2));
    printf("b: value should be 1 but it is 4. check %d\n", DOUBLE(2));

    printf("c1: value should be 6. check %d\n", DOUBLEFIX(1+2));
    printf("c2: value should be 1. check %d\n", 4/DOUBLEFIX(2));
    return 0;
}
