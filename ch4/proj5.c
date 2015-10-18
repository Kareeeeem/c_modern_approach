#include <stdio.h>

int main(void) {
    int x, evens = 0, unevens = 0;

    printf("11 digits please: ");
    for (int i = 1; i < 12; i++) {
        scanf("%1d", &x);

        if (i % 2) {
            unevens += x;
        } else {
            evens += x;
        }
    }

    printf("check_digit: %d\n", 9 - (((3 * unevens + evens) - 1) % 10));

    return 0;
}
