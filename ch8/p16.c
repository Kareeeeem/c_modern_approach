#include <stdio.h>
#include <ctype.h>

#define LENALPHA 26

int main(void) {
    int count[LENALPHA] = {0};
    int anagrams = 1;
    int ch;

    printf("Enter first word: ");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (!isalpha(ch))
            continue;
        count[tolower(ch) - 'a']++;
    }

    printf("Enter second word: ");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (!isalpha(ch))
            continue;
        count[tolower(ch) - 'a']--;
    }

    for (int i = 0; i < LENALPHA; i++) {
        if (count[i] != 0) {
            anagrams = 0;
            break;
        }
    }

    if (anagrams != 0)
        printf("The words are anagrams.");
    else
        printf("The words are not anagrams.");
    printf("\n");

    return 0;
}
