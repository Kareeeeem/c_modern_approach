#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1024

void build_index_url(const char *domain, char *index_url);
void build_index_url_2(const char *domain, char *index_url);

int main(int argc, char *argv[])
{
    char index_url[N];

    if (argc != 2) {
        fprintf(stderr, "Usage: ex12 [domain].\n");
        exit(EXIT_FAILURE);
    }

    build_index_url(argv[1], index_url);
    puts(index_url);

    build_index_url_2(argv[1], index_url);
    puts(index_url);
    return 0;
}

void build_index_url(const char *domain, char *index_url)
{
    strcpy(index_url, "http://www.");
    strcat(index_url, domain);
    strcat(index_url, "/index.html");
}

void build_index_url_2(const char *domain, char *index_url)
{
    sprintf(index_url, "http://www.%s/index.html", domain);
}
