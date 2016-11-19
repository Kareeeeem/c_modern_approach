#include <stdio.h>
#include <limits.h>

#define N 10

void find_two_largest(int *a, int n ,int *largest, int *second_largest);

int main (void) {
    int largest, second_largest, arr[N] = {7, 3, 8, 1, 6, 9, 8, 1, 4};

    find_two_largest(&arr[0], N, &largest, &second_largest);

    printf("result %d, %d\n", second_largest, largest);
}

void find_two_largest(int *a, int n, int *largest, int *second_largest) {
    *largest = *second_largest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (a[i] > *largest) {
            *second_largest = *largest;
            *largest = a[i];
        } else if (a[i] > *second_largest)
            *second_largest = a[i];
    }
}
