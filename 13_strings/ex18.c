#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void remove_filename(char *url);
void remove_filename_2(char *url);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: ex18 [url].\n");
        exit(EXIT_FAILURE);
    }

    char f1[1024];
    strcpy(f1, argv[1]);
    char f2[1024];
    strcpy(f2, argv[1]);

    remove_filename(f1);
    puts(f1);

    remove_filename(f2);
    puts(f2);

    return 0;
}

void remove_filename(char *url)
{
    char *p = url;
    long slash_idx = 0;
    while (*p++) {
        if (*p == '/')
            slash_idx = p - url;
    }
    url[slash_idx] = '\0';
}

void remove_filename_2(char *url)
{
    char *p = url + (strlen(url) - 1);

    while (p >= url && *p != '/')
        p--;

    *p = '\0';
}
