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

int my_getline(char str[], int max_read);
void remove_trail(char str[], int len);

/* remove trailing blanks and tabs from each line of input */
int main(void)
{
    int len;
    char line[MAX_CHAR];

    while ((len = my_getline(line, MAX_CHAR)) > 0) {
        remove_trail(line, len);
        if (len > 1)
            printf("%s", line);
    }
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
 * remove_trail() -- remove trailing blanks and tabs from str.
 * @str: an array of char to remove from
 * @len: the length of str
 *
 * This function would modify str so that there's no more
 * trailing blanks and tabs inside it.
 */
void remove_trail(char str[], int len)
{
    int have_trail;

    have_trail = FALSE;
    for (len = len - 2; len >= 0
        && (str[len] == ' ' || str[len] == '\t'); --len)
        if (have_trail == FALSE)
            have_trail = TRUE;

    if (have_trail == TRUE) {
        ++len;
        str[len] = '\n';
        ++len;
        str[len] = '\0';
    }
}
