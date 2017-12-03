#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int compute_scrabble_value(const char *word);


int main(void) {
    char c, word[BUFSIZ], *p = word;

    for (p = word;;) {
        printf("Enter a word: ");
        while ((c = getchar()) != EOF && c != '\n') {
            if (p < (word + BUFSIZ - 1)) {
                *p++ = c;
            }
        }
        *p = '\0';

        if (strncmp(word, "q", 1) == 0) {
            exit(EXIT_SUCCESS);
        }

        printf("%s is worth %d.\n", word, compute_scrabble_value(word));
    }
}

int compute_scrabble_value(const char *word) {
    int points = 0;

    for (;*word; word++) {
        switch(toupper(*word)) {
            case 'D': case 'G':
                points += 2;
                break;
            case 'B': case 'C': case 'M': case 'P':
                points += 3;
                break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                points += 4;
                break;
            case 'K':
                points += 5;
                break;
            case 'J': case 'X':
                points += 8;
                break;
            case 'Q': case 'Z':
                points += 10;
                break;
            default:
                points++;
                break;
        }
    }
    return points;
}
