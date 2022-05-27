/*
 * Exercise 1-14. (page 24)
 *
 * Write a program to print a histogram of the frequencies
 * of different characters in its input.
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
        for (y = 0; y <= uppercase_histogram[i]; ++y)
            printf("=");
        printf("\n");
    }

    /* lowercase character histogram */
    for (i = 0; i < AMOUNT_OF_ALPHABET_CHAR; ++i) {
        printf("%c: ", i + 'a');
        for (y = 0; y <= lowercase_histogram[i]; ++y)
            printf("=");
        printf("\n");
    }

    /* numeric character histogram */
    for (i = 0; i < AMOUNT_OF_NUMERIC_CHAR; ++i) {
        printf("%d: ", i);
        for (y = 0; y <= numeric_histogram[i]; ++y)
            printf("=");
        printf("\n");
    }
    return 0;
}
