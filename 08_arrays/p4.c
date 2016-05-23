#include <stdio.h>

#define SIZE(a) (int) (sizeof(a) / sizeof(a[0]))

int main(void) {
    int a[10], i;

    printf("Enter %d numbers: ", SIZE(a));
    for (i = 0; i < SIZE(a); i++)
        scanf("%d", &a[i]);

    printf("In reverse order");
    for (i = SIZE(a)-1; i >= 0; i--)
        printf(" %d", a[i]);

    printf("\n");

    return 0;
}
