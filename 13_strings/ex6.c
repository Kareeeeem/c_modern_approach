#include <stdio.h>
#include <string.h>

#define N 1024

void censor(char *str, char *badword);

int main(void) {
    char str[N];

    fgets(str, N, stdin);
    censor(str, "foo");
    puts(str);

    return 0;
}

void censor(char *str, char *badword) {
    size_t badword_len = strlen(badword);
    char *sentinal;

    while (*str) {
        if (strncmp(str, badword, badword_len) != 0) {
            str++;
        } else {
            sentinal = str + badword_len;
            while (str < sentinal) {
                *str++ = 'x';
            }
        }
    }
}
