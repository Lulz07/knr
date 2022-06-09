/*
 * Exercise 1-17. (page 31)
 *
 * Write a program to print all input lines that are longer
 * than 80 characters.
 *
 * Written by Lulz07.
 */

#include <stdio.h>

/*
 * if we defined MAX_CHAR as 80, only 79 characters will be
 * stored rather than 80 (excluding the null character).
 * so, lets define this as 81 instead.
 */
#define MAX_CHAR 81

int my_getline(char [], int);

int main(void)
{
    int c;
    int len;
    char line[MAX_CHAR];

    len = 0;
    while ((len = my_getline(line, MAX_CHAR)) > 0)
        if (line[len - 1] != '\n') {
            printf("%s", line);
            /* read the characters left one by one */
            while ((c = getchar()) != '\n')
                putchar(c);
            printf("\n");
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
