#include <stdio.h>

#define NELEMS(a) (sizeof(a) / sizeof(a[0]))

int array[12];

int main(void) {
    printf("It is%scorrect to say that array has 12 elements.\n",
            NELEMS(array) == 12 ? " " : " NOT ");
    return 0;
}
