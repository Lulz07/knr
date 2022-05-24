/*
 * Exercise 1-4. (page 13)
 *
 * Write a program to print the corresponding Celsius to
 * Fahrenheit table.
 *
 * Written by Lulz07.
*/

#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int start_at, stop_at, step_size;

    start_at = 0;
    stop_at = 300;
    step_size = 20;

    printf(" Celsius          Fahrenheit\n");
    printf(" -------          ----------\n");

    celsius = start_at;
    while (celsius <= stop_at) {
        /* below is the formula for the conversion */
        fahr = (celsius * 9.0 / 5.0) + 32.0;
        /* celsius will be printed 5 characters wide
         * meanwhile fahrenheit is 19 characters wide and 1
         * character after decimal point
        */
        printf("%5.0f %19.1f\n", celsius, fahr);
        celsius = celsius + step_size;
    }
    return 0;
}
