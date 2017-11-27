#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int sum = 0;
    while (*++argv) {
        sum += atoi(*argv);
    }
    printf("%d\n", sum);
    return 0;
}
