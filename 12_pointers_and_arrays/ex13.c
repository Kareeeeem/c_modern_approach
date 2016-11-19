#include <stdio.h>

#define N 10

void init_ident_array(int *a, int dimension);
void print_int_array(const int a[], int n);
void print_ident_array(const int *a, int n);

int main() {
    int ident[N][N], *ptr, zeros = 0, ident2[N][N];

    for (ptr = &ident[0][0]; ptr <= &ident[N-1][N-1]; ptr++) {
        if ((ptr == &ident[0][0]) || zeros == 10) {
            *ptr = 1;
            zeros = 0;
        } else {
            *ptr = 0;
            zeros++;
        }
    }

    for (int i = 0; i < N; i++)
        print_ident_array(ident[i], N);

    init_ident_array(ident2[0], N);

    for (int i = 0; i < N; i++)
        print_ident_array(ident2[i], N);
}

void init_ident_array(int *a, int dimension) {
    int n = dimension * dimension;
    while (n--)
        *a++ = !(n % (dimension + 1));
}

void print_int_array(const int a[], int n) {
    while (n--)
        printf("%d", *a++);
    puts("");
}

void print_ident_array(const int *a, int n) {
    while (n--) {
        printf("%d", *a++);
        if (!n % N)
            puts("");
    }
}
