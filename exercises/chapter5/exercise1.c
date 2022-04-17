#include <stdio.h>
#include <ctype.h>
#include "input/input.c"

#define SIZE 100

int read_int(int *pn);
char read_first_digit();

// Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid
// representation of zero. Fix it to push such a character back on the input.
int main(void)
{
    int i;
    int array[SIZE];

    for (i = 0; i < SIZE && read_int(&array[i]) != EOF; i++);

    for (int j = 0; j < i; j++)
        printf("%d\n", array[j]);

    return 0;
}

int read_int(int *pn)
{
    char c = read_first_digit();

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        unread_char(c);
        return 0;
    }

    int sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        c = read_char();

        if (!isdigit(c)) {
            unread_char(c);
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = read_char())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF) unread_char(c);

    return c;
}

char read_first_digit()
{
    char c;
    while (!isdigit(c = read_char()) && c != EOF);
    return c;
}
