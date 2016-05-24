#include <stdio.h>

int num_digits(int n);

int main(void) {
    int i;
    printf("Enter a number: ");
    scanf("%d", &i);
    printf("%d has %d digits\n", i, num_digits(i));
    return 0;
}

int num_digits(int n) {
    int count = 0;
    while (n) {
        count++;
        n /= 10;
    }
    return count;
}
