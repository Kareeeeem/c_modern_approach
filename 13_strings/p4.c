#include <stdio.h>

int main(int argc, char *argv[]) {
    while (--argc) {
        printf("%s ", *(argv+argc));
    }
    puts("");
    return 0;
}
