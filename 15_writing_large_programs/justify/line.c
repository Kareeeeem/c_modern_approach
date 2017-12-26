#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;
bool even = false;

void clear_line(void)
{
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{
    if (num_words > 0) {
        line[line_len] = ' ';
        line[line_len+1] = '\0';
        line_len++;
    }
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line()
{
    /*
     * Programming project 1.
     * Pre calculate the extra spaces for each gap.
     *
     * I've seen other solutions that will check for a flag to weight the gaps
     * to the left and then increase the variable spaces_to_insert by one by
     * one. But I had less success with this approach.
     *
     * Take for example a line with 5 words and 10 extra spaces. This would
     * result in the following spaces_to_insert.
     * (10 / (5 - 1)) + 1 = 3
     * (7 / (4 - 1))  + 1 = 3
     * (4 (3 - 1))    + 1 = 3
     * (1 (2 - 1))    + 1 = 2
     *                     -- +
     *                     11 (wrong).
     */
    int extra_spaces = MAX_LINE_LEN - line_len, gaps[num_words - 1];
    for (int i = 0; i < num_words - 1; i++) {
        gaps[i] = extra_spaces / (num_words -1 - i);
        extra_spaces -= gaps[i];
    }

    /*
     * Programming project 1 cont.
     * Traverse gaps bottomup or topdown based on wether the even flag.
     */
    int *gap, gap_direction;
    if (even) {
        gap = gaps;
        gap_direction = 1;
    } else {
        gap = gaps + (num_words - 2);
        gap_direction = -1;
    }

    for (int i = 0; i < line_len; i++) {
        if (line[i] != ' ') {
            putchar(line[i]);
        } else {
            for (int j = 1; j <= *gap + 1; j++) {
                putchar(' ');
            }
            gap += gap_direction;
        }
    }
    putchar('\n');

    /* Toggle even for the next call. */
    even = !even;
}

void flush_line(void)
{
    if (line_len > 0) {
        puts(line);
    }
}
