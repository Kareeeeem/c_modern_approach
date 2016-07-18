#include <stdio.h>

#define MAX_DIGITS 10
#define DIGIT_WIDTH 4
#define DIGIT_HEIGHT 3
#define SEGMENTS 7

static char digits[DIGIT_HEIGHT][MAX_DIGITS * DIGIT_WIDTH];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits(void);

int main(void) {
    clear_digits_array();

    for (int ch, i = 0; i < MAX_DIGITS; i++) {
        if ((ch = getchar()) == '\n')
            break;
        process_digit(ch - '0', i);
    }

    print_digits();
}

void clear_digits_array(void) {
    for (int i = 0; i < DIGIT_HEIGHT; i++)
        for (int j = 0; j < DIGIT_WIDTH * MAX_DIGITS; j++)
            digits[i][j] = ' ';
}

void process_digit(int digit, int position) {
    const int segments[MAX_DIGITS][SEGMENTS] = {
        {1, 1, 1, 1, 1, 1, 0}, // 0
        {0, 1, 1, 0, 0, 0, 0}, // 1
        {1, 1, 0, 1, 1, 0, 1}, // 2
        {1, 1, 1, 1, 0, 0, 1}, // 3
        {0, 1, 1, 0, 0, 1, 1}, // 4
        {1, 0, 1, 1, 0, 1, 1}, // 5
        {1, 0, 1, 1, 1, 1, 1}, // 6
        {1, 1, 1, 0, 0, 0, 0}, // 7
        {1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 1, 1, 0, 1, 1}  // 9
    };
    const int segment_map[SEGMENTS][3] = {
        // row, col, sign
        {0, 1, '_'},
        {1, 2, '|'},
        {2, 2, '|'},
        {2, 1, '_'},
        {2, 0, '|'},
        {1, 0, '|'},
        {1, 1, '_'}
    };

    for (int i = 0; i < SEGMENTS; i++) {
        if (segments[digit][i]) {
            int row = segment_map[i][0];
            int column = segment_map[i][1] + position * DIGIT_WIDTH;
            digits[row][column] = (char) segment_map[i][2];
        }
    }
}

void print_digits(void) {
    for (int i = 0; i < DIGIT_HEIGHT; i++) printf("%s", digits[i]);
    printf("\n");
}
