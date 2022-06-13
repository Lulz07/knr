/*
 * Exercise 1-15. (page 27)
 *
 * Rewrite the temperature conversion program of Section 1.2
 * to use a function for conversion.
 *
 * Written by Lulz07.
 */

#include <stdio.h>

#define START_AT 0
#define STOP_AT 300
#define STEP_SIZE 20

int fahr_to_celsius(int fahr);

/* Fahrenheit-Celsius conversion program; 0, 20, ..., 300 */
int main(void)
{
    int fahr;

    fahr = START_AT;
    while (fahr <= STOP_AT) {
        printf("%d\t%d\n", fahr, fahr_to_celsius(fahr));
        fahr = fahr + STEP_SIZE;
    }
    return 0;
}

/**
 * fahr_to_celsius() -- convert 'fahr' into its equivalent
 * Celsius value
 * @fahr: value of Fahrenheit
 *
 * Convert 'fahr' into its equivalent Celsius value, using
 * the formula:
 *      5 * (fahr - 32) / 9
 *
 * Return: Equivalent Celsius value of 'fahr'
 */
int fahr_to_celsius(int fahr)
{
    return 5 * (fahr - 32) / 9;
}
