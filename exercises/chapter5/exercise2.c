#include <stdio.h>
#include <ctype.h>
#include "input/input.c"

#define SIZE 100

int read_float(float *pn);
char read_first_digit();

// Exercise 5-2. Write getfloat, the floating-point analog of
// getint. What type does getfloat return as its function value?
int main(void)
{
    int i;
    float array[SIZE];

    for (i = 0; i < SIZE && read_float(&array[i]) != EOF; i++);

    for (int j = 0; j < i; j++)
        printf("%f\n", array[j]);

    return 0;
}

int read_float(float *pn)
{
    char c = read_first_digit();
    float coefficient = 1;

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

    if (c == '.') {
        c = read_char();

        for (; isdigit(c); c = read_char()) {
            *pn = 10 * *pn + (c - '0');
            coefficient /= 10;
        }
    }

    *pn *= sign;
    *pn *= coefficient;

    if (c != EOF) unread_char(c);

    return c;
}

char read_first_digit()
{
    char c;
    while (!isdigit(c = read_char()) && c != EOF);
    return c;
}

