#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool test_extension(const char *file_name, const char *extension);
void get_extension(const char *file_name, char *extension);
void strtolower(char *s);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: ex17 [file_name] [extension].\n");
        exit(EXIT_FAILURE);
    }

    bool match = test_extension(argv[1], argv[2]);
    printf("It is %sa match.\n", match ? "" : "not ");
}

bool test_extension(const char *file_name, const char *extension)
{
    char file_ext[20],
         *file_ext_ptr = file_ext;

    get_extension(file_name, file_ext);

    for (;toupper(*file_ext_ptr) == toupper(*extension); file_ext_ptr++, extension++) {
        if (*file_ext_ptr == '\0') {
            return true;
        }
    }

    return false;
}

// This accounts for more than one '.' by going back from the end.
void get_extension(const char *file_name, char *extension)
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
