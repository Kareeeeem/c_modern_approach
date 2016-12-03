#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10

void get_extension(const char *file_name, char *extension);

int main(int argc, char *argv[])
{
    char extension[N];

    if (argc != 2) {
        fprintf(stderr, "Usage: ex12 [filename].\n");
        exit(EXIT_FAILURE);
    }

    get_extension(argv[1], extension);
    puts(extension);
    return 0;
}

void get_extension(const char *file_name, char *extension)
{
    for (;*file_name; file_name++) {
        if (*file_name == '.') {
            strcpy(extension, ++file_name);
            return;
        }
    }
    strcpy(extension, "");
}
