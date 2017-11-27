#include <stdio.h>
#include <string.h>

#define MAX_REMIND 60
#define MSG_LEN 50

int read_line(char *word, int n);

int main(void) {
    char reminders[MAX_REMIND][MSG_LEN+3];
    char date_time_str[12], msg_str[MSG_LEN+1];
    int month, day, hours, minutes, i, j, c, num_remind = 0;
    _Bool bad_day, bad_time, bad_month;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter month/day HH:MM and reminder: ");
        scanf("%2d/%2d %2d:%2d", &month, &day, &hours, &minutes);
        if (month == 0) break;
        bad_day = day < 0 || day > 31;
        bad_month = month < 1 || month > 12;
        bad_time = hours < 0 || hours > 24 || minutes < 0 || minutes > 59;

        if (bad_day || bad_month || bad_time) {
            puts("Bad data.");
            while ((c = getchar()) != '\n' && c != EOF) ;
            continue;
        }
        sprintf(date_time_str, "%02d/%02d %02d:%02d", month, day, hours, minutes);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++) {
            if (strcmp(date_time_str, reminders[i]) < 0) {
                break;
            }
        }
        for (j = num_remind; j > i; j--) {
            strcpy(reminders[j], reminders[j-1]);
        }
        strcpy(reminders[i], date_time_str);
        strcat(reminders[i], msg_str);
        num_remind++;
    }
    printf("\n%-6s%-6s%s\n", "Day", "Time", "Reminder");
    for (i = 0; i < num_remind; i++) {
        printf("%s\n", reminders[i]);
    }
    return 0;
}

int read_line(char *word, int n) {
    int c, i = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < n) {
            word[i++] = c;
        }
    }
    word[i] = '\0';
    return i;
}
