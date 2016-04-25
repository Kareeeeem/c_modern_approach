#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define UP          0
#define RIGHT       1
#define DOWN        2
#define LEFT        3

#define ROWS        10
#define COLUMNS     10
#define DOT         '.'

static char grid[ROWS][COLUMNS] = {
    {DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT},
    {DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT},
    {DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT},
    {DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT},
    {DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT},
    {DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT},
    {DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT},
    {DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT},
    {DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT},
    {DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT, DOT},
};

static bool is_valid_move(int row, int column, int move) {
    switch (move) {
    case UP:
        return row != 0 && grid[row-1][column] == DOT;
    case DOWN:
        return row != ROWS -1 && grid[row+1][column] == DOT;
    case RIGHT:
        return column != COLUMNS -1 && grid[row][column+1] == DOT;
    case LEFT:
        return column != 0 && grid[row][column-1] == DOT;
    default:
        return false;
    }
}

int main(int argc, char *argv[]) {
    unsigned int seed;
    int direction;
    int row = 0;
    int column = 0;
    bool moves_left = true;

    if (argc != 2){
        fprintf(stderr, "Usage: %s <seed>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    seed = (unsigned int) atoi(argv[1]);
    srand(seed);

    for (char i = 'A'; i <= 'Z'; i++) {
        if (!moves_left)
            break;

        grid[row][column] = i;

        while (true) {
            direction = rand() % 4;

            if (!is_valid_move(row, column, RIGHT) &&
                    !is_valid_move(row, column, LEFT) &&
                    !is_valid_move(row, column, UP) &&
                    !is_valid_move(row, column, DOWN)){
                moves_left = false;
                break;
            }

            if (direction == UP && is_valid_move(row, column, UP)) {
                row--;
                break;

            } else if (direction == RIGHT && is_valid_move(row, column, RIGHT)) {
                column++;
                break;

            } else if (direction == DOWN && is_valid_move(row, column, DOWN)) {
                row++;
                break;

            } else if (direction == LEFT && is_valid_move(row, column, LEFT)) {
                column--;
                break;
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++)
            printf("%c", grid[i][j]);
        printf("\n");
    }

    return 0;
}
