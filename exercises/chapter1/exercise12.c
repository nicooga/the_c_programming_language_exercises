#include <stdio.h>

// Exercise 1-12. Write a program that prints its input one word per line.
int main(void)
{
    int c, state;

    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n')
            putchar('\n');
        else
            putchar(c);
}
