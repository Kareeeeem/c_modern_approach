// This is a roundabout way of doing the job but I was experimenting with
// pointers.
// Also it's a bit unreadable but was also experimenting with control flow.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Case insentitive version of strcmp
int istrcmp(const char *s1, const char *s2);


int main(int argc, char **argv) {
    char *planets[] = {
        "mercury", "venus", "earth",
        "mars", "jupiter", "saturn",
        "uranus", "neptune", "pluto",
        NULL,
    };
    char **planet;

    while (*++argv) {
        for (planet = planets; *planet && (istrcmp(*argv, *planet)); planet++)
            ;

        if (*planet)
            printf("%s is planet %ld\n", *argv, planet - planets + 1);
        else
            printf("%s is not a planet\n", *argv);
    }
}

int istrcmp(const char *s1, const char *s2) {
    char a, b;
    while(*s1 && *s2) {
        a = tolower(*s1);
        b = tolower(*s2);
        if (a != b) {
            return a - b;
        }
        s1++;
        s2++;
    }
    return 0;
}
