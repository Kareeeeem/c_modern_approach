#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool are_anagrams(const char *word, const char *word2);
void read_word(char *word, int n);

int main(void) {
    char word[BUFSIZ];
    char word2[BUFSIZ];

    printf("Enter first word: ");
    read_word(word, BUFSIZ);

    printf("Enter second word: ");
    read_word(word2, BUFSIZ);

    if (are_anagrams(word, word2)) {
        puts("They are anagrams");
    } else {
        puts("They are NOT anagrams");
    }

    return 0;
}

bool are_anagrams(const char *word, const char *word2) {
    int sum = 0, sum2 = 0;
    bool same = true;
    for (; *word && *word2; word++, word2++) {
        if (*word != *word2) {
            same = false;
        }
        sum += (int) *word;
        sum2 += (int) *word2;
    }
    // the characters add up to the same amount .
    return sum == sum2 \
                // AND either the characters compared are not in the same
                // order. or if they are then what remains of them are not the
                // same.
                && (! same || (*word - *word) != 0);
}

/* Will read at most n - 1 bytes into the provided buffer or until a newline
 * or EOF is found. Will always store a null byte at the end. Will leave
 * remaining characters on the stream.
 */
void read_word(char *word, int n) {
    int c;
    char *p = word;
    for (; p < word + (n - 1); p++) {
        c = getchar();
        if (c == '\n') {
            *p = c;
            break;
        } else if (c == EOF) {
            break;
        } else if (isalpha(c)) {
            *p = c;
        }
    }
    *p = '\0';
}
