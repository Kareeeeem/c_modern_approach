#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Case insentitive version of strcmp
int istrcmp(const char *s1, const char *s2);
int find_needle(const char *needle, char **haystack, size_t size);


int main(int argc, char **argv) {
    char *planets[] = {
        "mercury", "venus", "earth",
        "mars", "jupiter", "saturn",
        "uranus", "neptune", "pluto",
    };
    int loc;
    size_t planet_count = (sizeof(planets) / sizeof(planets[0]));
    while (*++argv) {
        if ((loc = find_needle(*argv, planets, planet_count)) == 0)
            printf("%s is not a planet\n", *argv);
        else
            printf("%s is planet %d\n", *argv, loc + 1);
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

int find_needle(const char *needle, char **haystack, size_t size) {
    for (char **p = haystack; p < haystack + size; p++)
        if ((istrcmp(needle, *p)) == 0)
            return (p - haystack);
    return 0;
}
