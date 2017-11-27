#include <stdio.h>
#include <string.h>

#define WORD_LEN 20

int read_line(char *word, int n);

int main(void) {
    char word[WORD_LEN + 1];
    char smallest[WORD_LEN + 1] = {"\0"};
    char largest[WORD_LEN + 1] = {"\0"};
    size_t len;
    int i = 0;

    while ((len = read_line(word, WORD_LEN + 1)) != 4) {
        if (strcmp(word, smallest) < 0 || i == 0) {
            strcpy(smallest, word);
        }
        if (strcmp(word, smallest) > 0 || i == 0) {
            strcpy(largest, word);
        }
        i++;
    }
    printf("largest: %s. smallest: %s\n", largest, smallest);
    return 0;
}

int read_line(char *word, int n) {
    int c, i = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < n) {
            *word++ = c;
        }
        i++;
    }
    *word = '\0';
    return i;
}
