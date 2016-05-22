#include <stdio.h>

double triangle(double base, double height);

int main(void) {
    double base = 7, height = 9;
    printf("area of triangle with base %.2f and height %.2f is %.2f\n",
            base, height, triangle(base, height));
    return 0;
}

double triangle(double base, double height) {
    double product;
    product = base * height;
    return product / 2;
}
