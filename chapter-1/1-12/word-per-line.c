/*
 * Exercise 1-12. (page 21)
 *
 * Write a program that prints its input one word per line.
 *
 * Written by Lulz07.
 */

#include <stdio.h>

#define INSIDE_A_WORD 1
#define OUTSIDE_A_WORD 0

int main(void)
{
    int c, character_status;

    character_status = INSIDE_A_WORD;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (character_status == OUTSIDE_A_WORD) {
                character_status = INSIDE_A_WORD;
                printf("\n");
            }
        } else {
            character_status = OUTSIDE_A_WORD;
            putchar(c);
        }
    }
    return 0;
}
