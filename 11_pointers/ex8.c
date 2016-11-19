#include <stdio.h>

int *find_largest(int a[], int n);

int main(void) {
    int *largest = find_largest((int []){0, 2, 9, 3, 5, 7}, 6);
    printf("%d\n", *largest);
}

int *find_largest(int a[], int n) {
    int *max = a;
    for (int i = 0; i < n; i++) max = a[i] > *max ? a + i : max;
    return max;
}
