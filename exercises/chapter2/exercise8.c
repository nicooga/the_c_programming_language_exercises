#include <stdio.h>
#include <limits.h>

unsigned read_number(void);
short is_digit(char c);
short to_digit(char c);

unsigned rightrot(unsigned x, short n);

void print_as_binary(unsigned n, char label[]);
short bit_count_for_uints(void);

// Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
// to the right by n positions. 
int main(void)
{
    unsigned x = read_number();
    short n = read_number();

    print_as_binary(x, "before");

    printf("%u\n", rightrot(x, n));

    print_as_binary(rightrot(x, n), "after");

    return 0;
}

unsigned rightrot(unsigned x, short n)
{
    short b = bit_count_for_uints();

    for (int i = 0; i < n; i++) {
        short first_bit = (x << (b-1)) >> (b-1);
        x >>= 1;
        if (first_bit == 1) x |= 1 << (b - 1);
    }

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