#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void) {
    int wins = 0, losses = 0;
    char confirm;

    srand((unsigned) time(NULL));

    do {
        if (play_game()) {
            wins++;
            printf("you win!\n");
        } else {
            losses++;
            printf("you lost.\n");
        }
        printf("Play again? y/n > ");
        scanf(" %c", &confirm);
    } while (toupper(confirm) != 'N');

    printf("wins: %d, losses: %d\n", wins, losses);
}

int roll_dice(void) {
    return rand() % 6 + rand() % 6 + 2;
}

bool play_game(void) {
    for (int i = 0; ;i++) {
        int dice = roll_dice();
        int point;

        printf("You rolled %d!\n", dice);

        if (i == 0)
            switch (dice) {
            case 7: case 11:
                return true;
            case 2: case 3: case 12:
                return false;
            default:
                point = dice;
                printf("Your point is %d \n", point);
                break;
            }

        else if (dice == point) return true;
        else if (dice == 7)     return false;
    }
}
