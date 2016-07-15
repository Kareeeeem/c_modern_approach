#include <stdio.h>
#include <ctype.h>

#define MAX 1024

void selection_sort(int numbers[], int n);

int main(void) {
    int numbers[MAX], i;
    for (i = 0; i < MAX; i++) {
        int c = getchar();
        if (!isdigit(c)) break;
        numbers[i] = c - '0';
    }
    selection_sort(numbers, i);

    for (int j = 0; j < i; j ++) {
        printf("%d", numbers[j]);
    }
    printf("\n");
}

void selection_sort(int numbers[], int n) {
    if (n == 0)
        return;

    int maxidx = 0;
    for (int i = 0; i < n; i++)
        maxidx = (numbers[i] > numbers[maxidx]) ? i : maxidx;

    int temp = numbers[maxidx];
    numbers[maxidx] = numbers[n - 1];
    numbers[n - 1] = temp;

    selection_sort(numbers, --n);
}
