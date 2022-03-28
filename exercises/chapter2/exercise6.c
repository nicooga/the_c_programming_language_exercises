#include <stdio.h>
#include <limits.h>

unsigned read_number(void);
short is_digit(char c);
short to_digit(char c);
unsigned setbits(unsigned x, short p, short n, unsigned y);

void print_as_binary(unsigned n, char label[]);
short bit_count_for_uints(void);

// Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at 
// position p set to the rightmost n bits of y, leaving the other bits unchanged.
int main(void)
{
    unsigned x = read_number();
    unsigned p = read_number();
    unsigned n = read_number();
    unsigned y = read_number();

    printf("%u\n", setbits(x, p, n, y));

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

unsigned setbits(unsigned x, short p, short n, unsigned y)
{
    short b = bit_count_for_uints();

    unsigned first_segment = p == 1 ? 0 : (x >> (b - p)) << (b - p);
    unsigned second_segment = (y << (b - n)) >> p;
    unsigned third_segment = (x << (p + n)) >> (p + n);

    return first_segment | second_segment | third_segment;
};

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
