#include <ctype.h>
#include <stdio.h>


int compute_scrabble_value(const char *word);


int main(int argc, char **argv) {
    while (*++argv) {
        printf("%s is worth %d.\n", *argv, compute_scrabble_value(*argv));
    }

    return 0;
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
