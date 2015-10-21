#include <stdio.h>

/* int is 32 bit, starts to fail with 46340^2 */
/* short is 16 bit, starts to fail with 182^2 */

int main(void) {
    int i, n;

    printf("Enter a few numbers: ");
    scanf("%d", &n);

    i = 1;
    while (i <= n) {
        short x = i * i;
        printf("%-10d %30hd\n", i, x);

        /* printf("%-10d %30d\n", i, i * i); */
        i++;
    }

    return 0;
}
