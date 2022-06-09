#include <stdio.h>

#define MAX_CHAR 80

int my_getline(char [], int);

int main(void)
{
    int c;
    int len;
    char line[MAX_CHAR];

    len = 0;
    while ((len = my_getline(line, MAX_CHAR)) > 0)
        if (line[len - 1] != '\n') {
            printf("%s", line);
            /* read the characters left one by one */
            while ((c = getchar()) != '\n')
                putchar(c);
            printf("\n");
        }
    return 0;
}

int my_getline(char string[], int max_read)
{
    int c, i;

    for (i = 0; i < max_read - 1
        && (c = getchar()) != EOF
        && c != '\n';
        ++i)
        string[i] = c;

    if (c == '\n') {
        string[i] = c;
        ++i;
    }

    string[i] = '\0';
    return i;
}
