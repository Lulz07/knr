/*
 * Exercise 1-17. (page 31)
 *
 * Write a program to print all input lines that are longer
 * than 80 characters.
 *
 * Written by Lulz07.
 */

#include <stdio.h>

#define MAX_CHAR 80

int my_getline(char str[], int max_read);

/* print all input lines that are longer than 80 characters */
int main(void)
{
    int c;
    int len;
    char line[MAX_CHAR + 1];

    len = 0;
    while ((len = my_getline(line, MAX_CHAR + 1)) > 0)
        if (line[len - 1] != '\n') {
            /* line[len - 1] would return the char before \0 */
            printf("%s", line);
            while ((c = getchar()) != '\n')
                putchar(c);
            printf("\n");
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
