#include <stdio.h>
#include <ctype.h>

#define MAXWORDS 30
#define WORDLEN 20

int main(void) {
    char sentence[MAXWORDS][WORDLEN];
    char (*word)[WORDLEN] = sentence;
    char *p = word[0];
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (! (word < word + MAXWORDS)) {
            break;
        } else if (isspace(c) || ! (p < (word[0] + WORDLEN - 1))) {
            *p = '\0';
            p = (++word)[0];
        } else {
            *p++ = c;
        }
    }
    *p = '\0';

    for (int i = word - sentence; i >= 0; i--) {
        printf("%s ", sentence[i]);
    }

    printf("\b\n");
    return 0;
}
