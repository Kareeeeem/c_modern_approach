#ifndef WORD_H
#define WORD_H

/*
 * Read a word from the input buffer and store it in word. Will make word
 * empty if word could not be read due to EOF. Will truncate word if its length
 * exeeds len.
 */
void read_word(char *word, int len);

#endif
 
