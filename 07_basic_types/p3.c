#include <stdio.h>

int main(void) {
    double n, sum = 0;

    printf("Enter a few integers (0 to terminate): ");

    scanf("%lf", &n);
    while (n != 0) {
        sum += n;
        scanf("%lf", &n);
    }

    printf("The sum is: %lf\n", sum);

    return 0;
}
