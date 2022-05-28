/*
 * Exercise 1-14. (page 24)
 *
 * Write a program to print a histogram of the frequencies
 * of different characters in its input.
 *
 * Accuracy is tested with the command:
 * egrep -o '<char>' char-frequencies.c | wc -l
 *
 * Written by Lulz07.
 */

#include <stdio.h>

#define AMOUNT_OF_NUMERIC_CHAR 10
#define AMOUNT_OF_ALPHABET_CHAR 26

int main(void)
{
    int c, i, y;
    int uppercase_histogram[AMOUNT_OF_ALPHABET_CHAR];
    int lowercase_histogram[AMOUNT_OF_ALPHABET_CHAR];
    int numeric_histogram[AMOUNT_OF_NUMERIC_CHAR];

    for (i = 0; i < AMOUNT_OF_ALPHABET_CHAR; ++i) {
        uppercase_histogram[i] = 0;
        lowercase_histogram[i] = 0;
    }

    for (i = 0; i < AMOUNT_OF_NUMERIC_CHAR; ++i)
        numeric_histogram[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z')
            ++uppercase_histogram[c - 'A'];
        else if (c >= 'a' && c <= 'z')
            ++lowercase_histogram[c - 'a'];
        else if (c >= '0' && c <= '9')
            ++numeric_histogram[c - '0'];
    }

    /* uppercase character histogram */
    for (i = 0; i < AMOUNT_OF_ALPHABET_CHAR; ++i) {
        printf("%c: ", i + 'A');
        for (y = 1; y <= uppercase_histogram[i]; ++y)
            printf("=");
        printf(" (%d)\n", uppercase_histogram[i]);
    }

    /* lowercase character histogram */
    for (i = 0; i < AMOUNT_OF_ALPHABET_CHAR; ++i) {
        printf("%c: ", i + 'a');
        for (y = 1; y <= lowercase_histogram[i]; ++y)
            printf("=");
        printf(" (%d)\n", lowercase_histogram[i]);
    }

    /* numeric character histogram */
    for (i = 0; i < AMOUNT_OF_NUMERIC_CHAR; ++i) {
        printf("%d: ", i);
        for (y = 1; y <= numeric_histogram[i]; ++y)
            printf("=");
        printf(" (%d)\n", numeric_histogram[i]);
    }
    return 0;
}
