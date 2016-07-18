#include <stdio.h>

void avg_sum(double a[], int n, double *avg, double *sum);

int main(void) {
    double a[5] = {0.1, 0.2, 0.3, 0.4, 0.5}, avg, sum;
    avg_sum(a, 5, &avg, &sum);
    printf("avg: %g, sum: %g\n", avg, sum);
}

void avg_sum(double a[], int n, double *avg, double *sum) {
    *sum = 0.0;
    for (int i = 0; i < n; i++)
        *sum += a[i];
    *avg = *sum / n;
}
