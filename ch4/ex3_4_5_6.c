#include <stdio.h>

int main() {
    printf("In C89:\n");
    printf("8/5 \t\t= 1\n");
    printf("-8/5 \t\t= -1 or -2\n");
    printf("8/-5 \t\t= 1 or -2\n");
    printf("-8/-5 \t\t= 1\n");

    printf("In C99:\n");
    printf("8/5 \t\t= 1\n");
    printf("-8/5 \t\t= -1\n");
    printf("8/-5 \t\t= -1\n");
    printf("-8/-5 \t\t= 1\n");

    printf("In C89:\n");
    printf("8 %% 5 \t\t= 3\n");
    printf("-8 %% 5 \t\t= -3 or 2\n");
    printf("8 %% -5 \t\t= 3 or -2\n");
    printf("-8 %% -5 \t= -3\n");

    printf("In C99:\n");
    printf("8 %% 5 \t\t= 3\n");
    printf("-8 %% 5 \t\t= -3\n");
    printf("8 %% -5 \t\t= 3\n");
    printf("-8 %% -5 \t= -3\n");

    return 0;
}
