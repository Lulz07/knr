/*
 * Exercise 1-12. (page 21)
 *
 * Write a program that prints its input one word per line.
 *
 * Written by Lulz07.
*/

#include <stdio.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            /* outside a word */
            printf("\n");
        else
            /* inside a word */
            putchar(c);
    }
    return 0;
}
