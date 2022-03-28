#include <stdio.h>
#include <limits.h>

unsigned read_number(void);
short is_digit(char c);
short to_digit(char c);

int bitcount(unsigned x);

void print_as_binary(unsigned n, char label[]);

// Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit 
// in x. Explain why. Use this observation to write a faster version of bitcount.
int main(void)
{
    int x = read_number();
    printf("%d\n", bitcount(x));
    return 0;
}

unsigned read_number()
{
    unsigned n = 0;
    char c;

    while  ((c = getchar()) == ' ');

    while  (c != EOF && c != '\n' && c != ' ') {
        if (!is_digit(c)) return 0;
        n = n * 10 + to_digit(c);
        c = getchar();
    }

    return n;
}

short is_digit(char c)
{
    return c >= '0' && c <= '9';
}

short to_digit(char c)
{
    return c - '0';
}

int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x-1)) b++;
    return b;
}