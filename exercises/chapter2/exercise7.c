#include <stdio.h>
#include <limits.h>

unsigned read_number(void);
short is_digit(char c);
short to_digit(char c);

unsigned invert(unsigned x, short p, short n);

void print_as_binary(unsigned n, char label[]);
short bit_count_for_uints(void);

// Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
// position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged. 
int main(void)
{
    unsigned x = read_number();

    short p = read_number();
    short n = read_number();

    printf("%u\n", invert(x, p, n));

    return 0;
}

unsigned invert(unsigned x, short p, short n)
{
    short b = bit_count_for_uints();

    for (short i = p; i <= p+n-1; i++)
       x ^= (1u << (b - 1)) >> i;

    return x;
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

void print_as_binary(unsigned n, char label[])
{
    short b = bit_count_for_uints();

    printf("%10s:\t(%10u)\t", label, n);

    for (short i = 0; i < b; i++) {
        if (((n << i) >> (b-1)) & 1)
            printf("[34m1[39m");

        else
            printf("0");

        printf(" ");
    }

    printf("\n");
}

short bit_count_for_uints()
{
    unsigned int i = UINT_MAX;
    short count = 0;

    while (i > 0) {
        i >>= 1;
        count++;
    }

    return count;
}