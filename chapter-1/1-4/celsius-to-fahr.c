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
        fahr = (celsius * 9.0 / 5.0) + 32.0;
        printf("%5.0f %19.1f\n", celsius, fahr);
        celsius = celsius + step_size;
    }
    return 0;
}
