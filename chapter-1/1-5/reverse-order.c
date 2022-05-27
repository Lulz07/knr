/*
 * Exercise 1-5. (page 14)
 *
 * Modify the temprature program to print the table in reverse
 * order, that is, from 300 degrees to 0.
 *
 * Written by Lulz07.
 */

#include <stdio.h>

int main(void)
{
    int fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    return 0;
}
