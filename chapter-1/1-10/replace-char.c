/*
 * Exercise 1-10. (page 20)
 *
 * Write a program to copy its input to its output,
 * replacing each tab by \t, each backspace by \b, and each
 * backslash by \\. This makes tabs and backspaces visible
 * in an unambigous way.
 *
 * Written by Lulz07.
 */

#include <stdio.h>

/* replace tab by \t, backspace by \b, and backslash by \\ */
int main(void)
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        if (c == '\b')
            printf("\\b");
        if (c == '\\')
            printf("\\\\");
        if ((c != '\t') == (c != '\b') == (c != '\\'))
            putchar(c);
    }
    return 0;
}
