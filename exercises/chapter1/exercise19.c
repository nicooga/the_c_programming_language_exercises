#include <stdio.h>

#define MAX_LENGTH 1000

void reverse_print_line(char line[], int i);

// Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
// write a program that reverses its input a line at a time.
int main(void)
{
    int c;
    int i = 0;
    char line[MAX_LENGTH];

    while (1) {
        c = getchar();

        if (c == EOF) {
            reverse_print_line(line, i-1);
            return 0;
        }

        line[i] = c;

        if (c == '\n') {
            reverse_print_line(line, i);
            i = 0;
        } else
            ++i;
    }

    return 0;
}

void reverse_print_line(char line[], int i)
{
    for (; i >= 0; --i) putchar(line[i]);
}