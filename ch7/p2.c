#include <stdio.h>

#define INTERVAL 24

/* int is 32 bit, starts to fail with 46340^2 */
/* short is 16 bit, starts to fail with 182^2 */

int main(void) {
    int n;

    printf("Enter a few numbers: ");
    scanf("%d%*c", &n);

    for (int i = 1; i <= n; i ++) {
        printf("%-10d %30d\n", i, i * i);

        if (!(i % INTERVAL)) {
            printf("Press Enter to continue...");
            while (getchar() != '\n')
                ;
        }

    }

    return 0;
}
