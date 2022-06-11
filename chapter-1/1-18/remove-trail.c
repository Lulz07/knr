/*
 * Exercise 1-18. (page 31)
 *
 * Write a program to remove trailing blanks and tabs from
 * each line of input, and to delete entirely blank lines.
 *
 * Written by Lulz07.
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_CHAR 150

int my_getline(char [], int);
void remove_trailing_blanks_and_tabs(char [], int);

int main(void)
{
    int len;
    char line[MAX_CHAR];

    while ((len = my_getline(line, MAX_CHAR)) > 0) {
        remove_trailing_blanks_and_tabs(line, len);
        if (len > 1)
            printf("%s", line);
    }
    return 0;
}

int my_getline(char string[], int max_read)
{
    int c, i;

    for (i = 0; i < max_read - 1
        && (c = getchar()) != EOF
        && c != '\n';
        ++i)
        string[i] = c;

    if (c == '\n') {
        string[i] = c;
        ++i;
    }

    string[i] = '\0';
    return i;
}

void remove_trailing_blanks_and_tabs(char string[], int len)
{
    int have_trail;

    have_trail = FALSE;
    for (len = len - 2; len >= 0
        && (string[len] == ' ' || string[len] == '\t');
        --len)
        have_trail = TRUE;

    if (have_trail == TRUE) {
        ++len;
        string[len] = '\n';
        ++len;
        string[len] = '\0';
    }
}
