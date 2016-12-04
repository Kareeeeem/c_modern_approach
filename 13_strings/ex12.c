#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10

void get_extension(const char *file_name, char *extension);
void get_extension_2(const char *file_name, char *extension);

int main(int argc, char *argv[])
{
    char extension[N];

    if (argc != 2) {
        fprintf(stderr, "Usage: ex12 [filename].\n");
        exit(EXIT_FAILURE);
    }

    get_extension(argv[1], extension);
    puts(extension);

    get_extension_2(argv[1], extension);
    puts(extension);
    return 0;
}

void get_extension(const char *file_name, char *extension)
{
    while (*file_name) {
        if (*file_name++ == '.') {
            strcpy(extension, file_name);
            return;
        }
    }
    strcpy(extension, "");
}

// This accounts for more than one '.' by going back from the end.
void get_extension_2(const char *file_name, char *extension)
{
    const char *p = file_name + (strlen(file_name) - 1);

    for (;p >= file_name; p--) {
        if (*p == '.') {
            strcpy(extension, ++p);
            return;
        }
    }

    strcpy(extension, "");
}
