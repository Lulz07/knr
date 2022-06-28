/*
 * Exercise 1-19. (page 31)
 *
 * Write a function reverse(s) that reverses the charaacter
 * string s. Use it to write a program that reverses its input
 * a line at a time.
 *
 * Written by Lulz07.
 */

#include <stdio.h>

#define MAX_CHAR 150

int my_getline(char str[], int max_read);
int get_len(char str[]);
void reverse_line(char str[]);

/* reverse a line of input and print them */
int main(void)
{
    int len;
    char line[MAX_CHAR];

    while ((len = my_getline(line, MAX_CHAR)) > 0) {
        reverse_line(line);
        if (len > 1)
            printf("%s", line);
    }
    return 0;
}

/**
 * my_getline() -- read a line into str, return length.
 * @str: an array of char to save into
 * @max_read: maximum buffer to read
 *
 * Read a char from stdin and save them into str until a
 * complete line is formed, then return the length.
 *
 * Return: The length of str.
 */
int my_getline(char str[], int max_read)
{
    int c, i;

    for (i = 0; i < max_read - 1 && (c = getchar()) != EOF
        && c != '\n'; ++i)
        str[i] = c;

    if (c == '\n') {
        str[i] = c;
        ++i;
    }

    str[i] = '\0';
    return i;
}

/**
 * get_len() -- get the length of a str.
 * @str: an array of char to get the length with
 *
 * Read 'str' index by index until we met the newline char
 * '\n', then return the length.
 *
 * Return: The length of 'str'.
 */
int get_len(char str[])
{
    int i;
    for (i = 0; str[i] != '\n'; ++i);
    return i;
}

/**
 * reverse_line() -- reverse str.
 * @str: an array of char to reverse with
 *
 * Swap all char inside 'str' backwards.
 */
void reverse_line(char str[])
{
    int i, len;
    char tmp;

    len = get_len(str);
    for (i = 0; i < len; ++i) {
        tmp = str[i];
        str[i] = str[len - 1];
        str[len - 1] = tmp;
        --len;
    }
}
