/*
 * Exercise 1-13. (page 24) (horizontal version)
 *
 * Write a program to print a histogram of the lengths of
 * words in its input. It is easy to draw the histogram with
 * the bars horizontal; a vertical orientation is more
 * challenging.
 *
 * Output accuracy is tested with the command:
 * tr ' ' '\n' < horizontal-bars.c | grep -c '^.\{<word length>\}$'
 *
 * Written by Lulz07.
 */

#include <stdio.h>

#define INSIDE_A_WORD 1
#define OUTSIDE_A_WORD 0
#define MAX_WORD_LENGTH 11

int main(void)
{
    int c, i, y, character_status;
    int histogram[MAX_WORD_LENGTH];

    for (i = 0; i < MAX_WORD_LENGTH; ++i)
        histogram[i] = 0;

    i = 0;
    character_status = INSIDE_A_WORD;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (character_status == OUTSIDE_A_WORD) {
                character_status = INSIDE_A_WORD;
                if (i < MAX_WORD_LENGTH)
                    /* prevents buffer overflow */
                    ++histogram[i];
                i = 0;
            }
        } else {
            character_status = OUTSIDE_A_WORD;
            ++i;
        }
    }

    for (i = 1; i < MAX_WORD_LENGTH; ++i) {
        printf("%d: ", i);
        for (y = 1; y <= histogram[i]; ++y)
            printf("=");
        printf(" (%d)\n", histogram[i]);
    }
    return 0;
}
