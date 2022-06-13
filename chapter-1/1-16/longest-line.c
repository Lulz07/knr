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

int my_getline(char str[], int max_read);
void copy(char from[], char to[]);

/* print the length of arbitrarily long input lines */
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

/**
 * my_getline() -- read a line into str, return length.
 * @str: an array of char to save into
 * @max_read: maximum buffer to read
 *
 * Read a char from stdin and save them into str until a
 * complete line is formed, then return the length.
 *
 * Return: The length of str.
 */
int my_getline(char str[], int max_read)
{
    int c, i;

    for (i = 0; i < max_read - 1 && (c = getchar()) != EOF
        && c != '\n'; ++i)
        str[i] = c;

    if (c == '\n') {
        str[i] = c;
        ++i;
    }

    str[i] = '\0';
    return i;
}

/**
 * copy() -- copy 'from' into 'to'; assume 'to' is big enough.
 * @from: an array of char to copy from
 * @to: an array of char to copy into, should be big enough
 *
 * Copy 'from' into 'to'. 'to' should have enough buffer to
 * store the content of 'from', however, this function would
 * assume that 'to' is big enough, so there's no length
 * checking would be done by this function beforehand.
 */
void copy(char from[], char to[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
