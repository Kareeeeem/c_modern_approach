#include <string.h>
#include "line.h"
#include "word.h"

# define MAX_WORD_LEN 20

int main(void)
{
    /*
     * One extra space for a * in case of truncation.
     * And one for the \0 byte.
     */
    char word[MAX_WORD_LEN + 2];
    int word_len;

    clear_line();
    for (;;) {
        read_word(word, MAX_WORD_LEN+1);
        word_len = strlen(word);
        if (word_len == 0) {
            flush_line();
            return 0;
        }
        if (word_len + 1 > space_remaining()) {
            write_line();
            clear_line();
        }
        add_word(word);
    }
    return 0;
}
