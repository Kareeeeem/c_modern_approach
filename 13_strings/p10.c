#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void reverse_name(const char *name);
void get_name(char *name, size_t n);


int main(void) {
    char name[BUFSIZ];
    printf("Enter a name: ");
    get_name(name, BUFSIZ - 1);
    reverse_name(name);
    return 0;
}

void get_name(char *name, size_t n) {
    char c, *p = name;
    while ((c = getchar()) != EOF && c != '\n') {
        if (p < (name + n)) {
            *p++ = c;
        }
    }
    *p = '\0';
}

void reverse_name(const char *name) {
    const char *last = name, *p;

    // Find the start of the last name if more than one name is given.
    for (p = name; *p ; p++) {
        if (*(p - 1) == ' ') {
            last = p;
        }
    }

    // Print the last name capitalized.
    printf("%c", toupper(*last));
    printf("%s", last + 1);

    // If last is not just the name given, then print each first letter of the
    // previous names.
    if (last != name) {
        printf(", ");
        p = name;
        printf("%c. ", toupper(*p));
        for (; p < last; p++) {
            if (*(p - 1) == ' ') {
                printf("%c. ", toupper(*p));
            }
        }
    } else {
        printf(".");
    }
    printf("\n");
}
