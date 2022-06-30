/*
 * Exercise 1-20. (page 34)
 *
 * Write a program detab that replaces tabs in the input with
 * the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns. Should
 * n be a variable or a symbolic parameter?
 *
 * Written by Lulz07.
 */

#include <stdio.h>

#define TABSIZE 4

int get_the_number_of_spaces_needed(int column);
int print_spaces(int column);

/* replace tabs in the input with the proper number of spaces */
int main(void)
{
    int c, column;

    column = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            column = print_spaces(column);
        } else {
            putchar(c);
            ++column;
            if (c == '\n')
                /* already at the end of line */
                column = 0;
        }
    }
    return 0;
}

/**
 * get_the_number_of_spaces_needed() -- get the proper number of
 * spaces needed according to the column value.
 * @column: current character column
 *
 * The number of spaces is determined by the formula:
 *      TABSIZE - (column % TABSIZE)
 *
 * Return: The number of spaces needed.
 */
int get_the_number_of_spaces_needed(int column)
{
    return TABSIZE - (column % TABSIZE);
}

/**
 * print_spaces() -- print all the spaces needed onto the screen
 * and update the character column value.
 * @column: current character column
 *
 * This function will print all the spaces needed onto the
 * screen and in the same time updating the value of
 * the character column.
 *
 * Return: Updated character column.
 */
int print_spaces(int column)
{
    int spaces;
    for (spaces = get_the_number_of_spaces_needed(column);
        spaces > 0; --spaces) {
        printf(" ");
        ++column;
    }
    return column;
}
