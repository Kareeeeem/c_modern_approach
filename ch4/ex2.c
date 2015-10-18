#include <stdio.h>

int main() {
    char *question = "If i and j are psitive integers, does (-i)/j always have"
                     " the same value as -(i/j)?";

    char * answer = "in C89 the result can be rounded up or down. In C99 the"
                     " result is always truncated towards zero.";

    printf("%s\n\n%s\n", question, answer);
    return 0;
}
