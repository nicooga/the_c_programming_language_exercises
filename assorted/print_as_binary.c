#include <stdio.h>
#include <limits.h>

void print_as_binary(unsigned n, char label[]);
short bit_count_for_uints(void);

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