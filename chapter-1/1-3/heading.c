/*
 * Exercise 1-3. (page 13)
 *
 * Modify the temperature conversion program to print a
 * heading above the table.
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

    printf(" Fahrenheit          Celsius\n");
    printf(" ----------          -------\n");

    fahr = start_at;
    while (fahr <= stop_at) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%7.0f %19.1f\n", fahr, celsius);
        fahr = fahr + step_size;
    }
    return 0;
}
