#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool is_palendrome(char *message);

int main() {
    char message[BUFSIZ];
    fgets(message, BUFSIZ - 1, stdin);
    puts(is_palendrome(message) ? "palindrome" : "not a palindrome");
}

bool is_palendrome(char *message) {
    char *begin = message, *end;
    // set the end to before the newline.
    end = message + (strlen(message) - 2);
    while (begin < end) {
        if (*begin++ != *end--) {
            return false;
        }
    }
    return true;
}
