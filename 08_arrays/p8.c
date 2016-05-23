#include <stdio.h>

#define STUDENT_COUNT 5
#define TEST_COUNT 2

int main(void) {
    int scores[STUDENT_COUNT][TEST_COUNT];
    int current_score;

    // This exercise begs for structs but they have not been covered yet.
    // I would probably create a struct for student and exercise.

    // Two dimensional array that stores the total and average.
    // [n][0] for totals.
    // [n][1] for avarages.
    float data_students[STUDENT_COUNT][2] = {{0},{0}};

    // Two dimensional array that stores the total, average, highest, lowest.
    // [n][0] for totals.
    // [n][1] for avarages.
    // [n][2] for highest.
    // [n][3] for lowest.
    float data_tests[TEST_COUNT][4] = {{0},{0}};

    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Enter student test scores %d: ", i + 1);
        for (int j = 0; j < TEST_COUNT; j++) {
            scanf("%d", &scores[i][j]);
        }
    }

    for (int i = 0; i < STUDENT_COUNT; i++) {
        for (int j = 0; j < TEST_COUNT; j++) {

            current_score = scores[i][j];

            // update the total for the student and test.
            data_students[i][0] += current_score;
            data_tests[j][0] += current_score;

            // update the average for the student and test.
            data_students[i][1] = data_students[i][0] / TEST_COUNT;
            data_tests[j][1] = data_tests[j][0] / STUDENT_COUNT;

            // update the highest
            if (scores[i][j] > data_tests[j][2]) {
                data_tests[j][2] = current_score;
            }

            // update the lowest
            if (scores[i][j] < data_tests[j][2]) {
                data_tests[j][3] = current_score;
            }
        }
    }

    printf("\ndata students: ");
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("T%.0f/", data_students[i][0]);
        printf("A%.2f ", data_students[i][1]);
    }
    printf("\n");

    printf("\ndata tests: ");
    for (int i = 0; i < TEST_COUNT; i++) {
        printf("T%.0f/", data_tests[i][0]);
        printf("A%.2f/", data_tests[i][1]);
        printf("H%.0f/", data_tests[i][2]);
        printf("L%.0f ", data_tests[i][3]);
    }
    printf("\n");

    return 0;
}
