#include <stdio.h>
#include <stdlib.h>

int compute_vowel_count(const char *p);

int main(void) {
    char sentence[BUFSIZ];
    printf("Enter a sentence: ");
    if (fgets(sentence, BUFSIZ - 1, stdin) == NULL)
        exit(1);
    printf("Sentence contains %d vowels.\n", compute_vowel_count(sentence));

    return 0;
}

int compute_vowel_count(const char *p) {
    int count = 0;
    while (*p) {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u') {
            count++;
        }
        p++;
    }
    return count;
}
