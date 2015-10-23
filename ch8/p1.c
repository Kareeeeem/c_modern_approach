#include <stdbool.h>
#include <stdio.h>


int main(void) {
    bool digit_seen[10][2] = {{false}};

    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    printf("Repeated digits: ");

    while (n > 0) {
        digit = n % 10;
        n /= 10;

        if (digit_seen[digit][0])
            digit_seen[digit][1] = true;

        digit_seen[digit][0] = true;
    }

    for (int i = 0; i < 10; i++) {
        if (digit_seen[i][1])
            printf("%d", i);
    }

    printf("\n");

    return 0;
}

