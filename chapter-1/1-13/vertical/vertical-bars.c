/*
 * Exercise 1-13. (page 24) (vertical version)
 *
 * Write a program to print a histogram of the lengths of
 * words in its input. It is easy to draw the histogram with
 * the bars horizontal; a vertical orientation is more
 * challenging.
 *
 * Output accuracy is tested with the command:
 * tr ' ' '\n' < vertical-bars.c | grep -c '^.\{<word length>\}$'
 *
 * Written by Lulz07.
 */

#include <stdio.h>

#define INSIDE_A_WORD 1
#define OUTSIDE_A_WORD 0
#define MAX_WORD_LENGTH 11

/*
 * print a histogram of the lengths of words in its input;
 * vertically
 */
int main(void)
{
    int c, i, y, character_status, highest_value;
    int histogram[MAX_WORD_LENGTH];

    highest_value = 0;

    /* set all elements to 0 */
    for (i = 0; i < MAX_WORD_LENGTH; ++i)
        histogram[i] = 0;

    /* main routine */
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

    /* print the histogram */
    for (i = 1; i < 11; ++i)
        if (highest_value <= histogram[i])
            highest_value = histogram[i];

    for (i = highest_value; i >= 0; --i) {
        for (y = 1; y < MAX_WORD_LENGTH; ++y) {
            if (histogram[y] > i)
                printf("=   ");
            else
                printf("    ");
        }
        printf("\n");
    }
    return 0;
}
