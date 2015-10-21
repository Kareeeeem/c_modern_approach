#include <stdio.h>

int main(void) {
    printf("int %d\n", (int) sizeof(int));
    printf("short %d\n", (int) sizeof(short));
    printf("long %d\n", (int) sizeof(long));
    printf("float %d\n", (int) sizeof(float));
    printf("double %d\n", (int) sizeof(double));
    printf("long double %d\n", (int) sizeof(long double));
    return 0;
}
