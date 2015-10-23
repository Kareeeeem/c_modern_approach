#include <stdio.h>

#define MAX_INDEX 40

int main(void) {
    int fib_numbers[MAX_INDEX] = {0, 1};

    printf("%d %d ", fib_numbers[0], fib_numbers[1]);
    for (int i = 2; i < MAX_INDEX; i++) {
        int fib = fib_numbers[i-1] + fib_numbers[i-2];
        fib_numbers[i] = fib;
        printf("%d ", fib);
    }
    printf("\n");

    return 0;
}
