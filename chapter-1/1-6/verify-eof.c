/*
 * Exercise 1-6. (page 17)
 *
 * Verify that the expression getchar() != EOF is 0 or 1.
 *
 * Written by Lulz07.
*/

#include <stdio.h>

int main(void)
{
    int c;
    c = getchar();
    printf("c != EOF: %d\n", c != EOF);
    return 0;
}
