/*
 * Exercise 1-16. (page 30)
 *
 * Revise the main routine of the longest-line program so it
 * will correctly print the length of arbitrarily long input
 * lines, and much as possible of the text.
 *
 * Written by Lulz07.
 */

#include <stdio.h>

#define CHAR_BUFFER 150

int my_getline(char [], int);
void copy(char [], char []);

int main(void)
{
    int len;
    int max;
    char line[CHAR_BUFFER];
    char longest_line[CHAR_BUFFER];

    max = 0;
    while ((len = my_getline(line, CHAR_BUFFER)) > 0) {
        if (len == CHAR_BUFFER - 1
                && line[CHAR_BUFFER - 1] != '\n') {
            while (getchar() != '\n')
                ++len;
            ++len; /* include the newline */
        }

        if (len > max) {
            max = len;
            copy(line, longest_line);
        }
    }

    if (max > 0)
        printf("Length: %d\n%s\n", max, longest_line);
    return 0;
}

int my_getline(char string[], int max_read)
{
    int c, i;

    for (i = 0;
            i < max_read - 1
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

void copy(char from[], char to[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
