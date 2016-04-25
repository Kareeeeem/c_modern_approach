#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define UP          0
#define RIGHT       1
#define DOWN        2
#define LEFT        3

#define ROWS        10
#define COLUMNS     10
#define AVAILABLE   '.'

static char grid[ROWS][COLUMNS];

static bool is_valid_move(int row, int column, int move) {
    switch (move) {
    case UP:
        return row != 0 && grid[row-1][column] == AVAILABLE;
    case DOWN:
        return row != ROWS -1 && grid[row+1][column] == AVAILABLE;
    case RIGHT:
        return column != COLUMNS -1 && grid[row][column+1] == AVAILABLE;
    case LEFT:
        return column != 0 && grid[row][column-1] == AVAILABLE;
    default:
        return false;
    }
}

int main() {
    unsigned int seed;
    int direction;
    char letter     = 'A';
    bool moves_left = true;
    int row         = 0;
    int column      = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++)
            grid[i][j] = AVAILABLE;
    }

    seed = (unsigned int) time(NULL);
    srand(seed);

    while(letter <= 'Z' && moves_left) {
        if (grid[row][column] == AVAILABLE)
            grid[row][column] = letter;

        moves_left = !(!is_valid_move(row, column, RIGHT) &&
                !is_valid_move(row, column, LEFT) &&
                !is_valid_move(row, column, UP) &&
                !is_valid_move(row, column, DOWN));

        direction = rand() % 4;

        if (direction == UP && is_valid_move(row, column, UP)) {
            row--;
            letter++;
        } else if (direction == RIGHT && is_valid_move(row, column, RIGHT)) {
            column++;
            letter++;
        } else if (direction == DOWN && is_valid_move(row, column, DOWN)) {
            row++;
            letter++;
        } else if (direction == LEFT && is_valid_move(row, column, LEFT)) {
            column--;
            letter++;
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++)
            printf("%c", grid[i][j]);
        printf("\n");
    }

    return 0;
}
