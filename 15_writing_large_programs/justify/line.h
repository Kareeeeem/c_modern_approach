#ifndef LINE_H
#define LINE_H

/*
 * Clears the current line
 */
void clear_line(void);

/*
 * Adds a word to the end of the current line. If it is not the first word
 * include a leading space.
 */
void add_word(const char *word);

/*
 * Return the remainig characters left in the line.
 */
int space_remaining(void);

/*
 * Write the current line to stdout with justification.
 */
void write_line();

/*
 * Write the current line without justification.
 */
void flush_line(void);

#endif
