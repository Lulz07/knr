/*
 * Exercise 1-2. (page 8)
 *
 * Experiment to find out what happens when printf's argument
 * string contains \c, where c is some character not listed
 * above.
 *
 * Written by Lulz07.
*/

#include <stdio.h>

int main(void)
{
    printf("Alert (bell) character: \\a\n");
    printf("Backspace: \\b\n");
    printf("Formfeed: \\f\n");
    printf("Newline: \\n\n");
    printf("Carriage return: \\r\n");
    printf("Horizontal tab: \\t\n");
    printf("Vertical tab: \\v\n");
    printf("Backslash: \\\n");
    printf("Question mark: \\?\n");
    printf("Single quote: \\'\n");
    printf("Double quote: \\\"\n");
    printf("Octal number: \\ooo\n");
    printf("Hexadecimal number: \\xhh\n");
    /* other than this, they invoke an undefined behaviour */
    return 0;
}
