#include <stdio.h>

int max(int a[], int n);
double avg(int a[], int n);
int number_pos(int a[], int n);

int main(void) {
    return 0;
}

int max(int a[], int n) {
    // incase an empty array gets passed.
    if (n == 0) return 0;

    // initialize max to the first element.
    int max = a[0];
    // start comparing with the second element.
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

double avg(int a[], int n) {
    // incase an empty array gets passed
    if (n == 0) return 0;

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum / (double) n;
}

int number_pos(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > -1)
            count++;

    return count;
}
