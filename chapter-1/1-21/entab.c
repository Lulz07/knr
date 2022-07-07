/*
 * Exercise 1-21. (page 34)
 *
 * Write a program entab that replaces strings of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as for
 * detab. When either a tab or a single blank would suffice to reach a tab stop,
 * which should be given preference?
 *
 * Written by Lulz07.
 */

#include <stdio.h>

#define TABSIZE 4

int get_tabs_needed(int column, int blanks);
int get_spaces_needed(int column);
void print_char(int amount, char char_to_print);
void replace_blanks(int blanks, int column);

/* replace blanks with minimum number of tabs and blanks */
int main(void)
{
    int c, column, blanks;

    column = blanks = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
            ++column;
        } else {
            replace_blanks(blanks, column);
            blanks = 0;
            putchar(c);
            if (c == '\n')
                column = 0;
            else
                ++column;
        }
    }
    return 0;
}

/* get the amount of tabs required */
int get_tabs_needed(int column, int blanks)
{
    return column / TABSIZE - (column - blanks) / TABSIZE;
}

/* get the amount of spaces required */
int get_spaces_needed(int column)
{
    return column - (column / TABSIZE) * TABSIZE;
}

/* printing a char onto the screen repeatedly */
void print_char(int amount, char char_to_print)
{
    int i;
    for (i = 0; i < amount; ++i)
        printf("%c", char_to_print);
}

/* replace the string of blanks with the required number of tabs and blanks */
void replace_blanks(int blanks, int column)
{
    if (blanks == 1) {
        printf(" ");
        return;
    }

    if (blanks > 1) {
        int tabs;
        tabs = get_tabs_needed(column, blanks);
        print_char(tabs, '\t');
        if (tabs >= 1)
            blanks = get_spaces_needed(column);
        print_char(blanks, ' ');
    }
}
