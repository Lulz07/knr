/*
 * Exercise 1-8. (page 20)
 *
 * Write a program to count blanks, tabs, and newlines.
 *
 * Written by Lulz07.
 */

#include <stdio.h>

int main(void)
{
    int c, blanks, tabs, newlines;

    blanks = 0;
    tabs = 0;
    newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        if (c == '\t')
            ++tabs;
        if (c == '\n')
            ++newlines;
    }

    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);
    return 0;
}
