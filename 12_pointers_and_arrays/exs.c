#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 10

void print_int_array(const int a[], int n);

int sum_array(const int a[], int n);
bool search(const int a[], int n, int key);
void store_zeros(int a[], int n);
double inner_product(const double *a, const double *b, int n);
int *find_middle(int a[], int n);
void find_two_largest(const int *a, int n, int *largest, int *second_largest);

int main(void) {
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p = &a[1], *q = &a[5];

    // a: 14
    // b: 34
    // c: 4
    // d: true
    // e: false

    puts("ex1");
    printf("%d\n", *(p+3));
    printf("%d\n", *(q-3));
    printf("%ld\n", q - p);
    printf("%d\n", p < q);
    printf("%d\n", *p < *q);

    // ex 2
    // get the distance between the pointers, divide by 2 and add it to low.
    puts("ex2");
    int *low = p, *high = q, *middle;
    middle = (low + (high - low) / 2);

    printf("%d\n", *middle);

    // ex 3
    // the array is reversed
    puts("ex3");
    int b[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *pb = &b[0], *qb = &b[N-1], temp;

    while (pb < qb) {
        temp = *pb;
        *pb++ = *qb;
        *qb-- = temp;
    }

    print_int_array(b, N);
    printf("\n");

    // ex5
    // a is invalid
    // rest is true

    puts("ex5");
    int c[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *k = c;

    // printf("%d\n", k == c[0]);
    printf("%d\n", k == &c[0]);
    printf("%d\n", *k == c[0]);
    printf("%d\n", k[0] == c[0]);

    // ex6
    puts("ex6");
    int d[] = {1, 2, 3, 4, 5};
    int sum = sum_array(d, 5);
    printf("%d\n", sum);

    // ex7
    puts("ex7");
    printf("%d\n", search(d, 5, 3));
    printf("%d\n", search(d, 5, 15));

    // ex8
    puts("ex8");
    print_int_array(d, 5);
    store_zeros(d, 5);
    print_int_array(d, 5);

    // ex9
    puts("ex9");
    double one[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double two[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    printf("%g\n", inner_product(one, two, 5));

    puts("ex12");
    int nums[5] = {3, 4, 10, 1, 18};
    int l, s;
    find_two_largest(nums, 5, &l, &s);
    printf("%d, %d\n", s, l);

    return 0;
}

int sum_array(const int a[], int n) {
    int sum = 0;

    while (n--)
        sum += *a++;

    return sum;
}

bool search(const int a[], int n, int key) {
    while(n--)
        if (*a++ == key)
            return true;

    return false;
}

void store_zeros(int a[], int n) {
    while(n--)
        *a++ = 0;
}

void print_int_array(const int a[], int n) {
    while (n--)
        printf("%d", *a++);
    puts("");
}

double inner_product(const double *a, const double *b, int n) {
    double result = 0.0;

    while(n--)
        result += *a++ * *b++;

    return result;
}

// ex 10
int *find_middle(int a[], int n) {
    return a + (n / 2);
}

// ex12
void find_two_largest(const int *a, int n, int *largest, int *second_largest) {
    *largest = *second_largest = INT_MIN;
    int current;

    while (n--) {
        current = *a++;
        if (current > *largest) {
            *second_largest = *largest;
            *largest = current;
        } else if (*a > *second_largest)
            *second_largest = current;
    }
}
