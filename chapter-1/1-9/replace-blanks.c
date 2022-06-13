/*
 * Exercise 1-9. (page 20)
 *
 * Write a program to copy its input to its output, replacing
 * each string of one or more blanks by a single blank.
 *
 * Written by Lulz07.
 */

#include <stdio.h>

#define PREVIOUS_IS_A_BLANK 1
#define PREVIOUS_IS_NOT_A_BLANK 0

/*
 * replace each string of one or more blanks by a single blank
 */
int main(void)
{
    int c, char_stats;

    char_stats = PREVIOUS_IS_NOT_A_BLANK;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (char_stats == PREVIOUS_IS_NOT_A_BLANK) {
                char_stats = PREVIOUS_IS_A_BLANK;
                putchar(c);
            }
        }

        if (c != ' ') {
            char_stats = PREVIOUS_IS_NOT_A_BLANK;
            putchar(c);
        }
    }
    return 0;
}
