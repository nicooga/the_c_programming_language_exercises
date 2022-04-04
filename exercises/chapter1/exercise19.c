#include <stdio.h>

#define MAX_LENGTH 1000

int read_line(char line[], int lim);
void reverse_print_line(char line[], int i);

// Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
// write a program that reverses its input a line at a time.
int main(void)
{
    int c;
    int i = 0;
    int length;
    char line[MAX_LENGTH];

    while (length = read_line(line, MAX_LENGTH))
        reverse_print_line(line, length);

    return 0;
}

/* Reads line into char array. Returns line length. */
int read_line(char line[], int lim)
{
    int i = 0;
    char c;
    while ((c = getchar()) != EOF && c != '\n' && i < lim) line[i++] = c;
    line[i] = '\0';
    return i;
}

void reverse_print_line(char line[], int i)
{
    while (i >= 0) putchar(line[i--]);
    printf("\n");
}