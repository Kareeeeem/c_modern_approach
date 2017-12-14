#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double compute_average_word_length(const char *sentence);

int main(void) {
    int c;
    char sentence[BUFSIZ], *p = sentence;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (p < &sentence[BUFSIZ - 1]) {
            *p++ = c;
        }
    }
    *p = '\0';

    printf("The average word length is %.1f\n",
            compute_average_word_length(sentence));

    return 0;
}

double compute_average_word_length(const char *sentence) {
    double words = 1, sum = 0;
    for (; *sentence; sentence++) {
        if (isspace(*sentence)) {
            words += 1;
        } else {
            sum += 1;
        }
    }
    return sum / words;
}
