#include <stdio.h>
#include <limits.h>

int char_min;
int char_max;
int short_min;
int short_max;
int int_min;
int int_max;
long long_min;
long long_max;

void compute_limits(void);
void compute_char_limits(void);
void compute_short_limits(void);
void compute_int_limits(void);
void compute_long_limits(void);

// Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
// variables, both signed and unsigned, by printing appropriate values from standard headers
// and by direct computation. Harder if you compute them: determine the ranges of the various
// floating-point types.
int main(void)
{
    compute_limits();

    printf("Limits as in standard headers:\n\n");

    printf("char  -> %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("short -> %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("int   -> %d to %d\n", INT_MIN, INT_MAX);
    printf("long  -> %ld to %ld\n", LONG_MIN, LONG_MAX);

    putchar('\n');

    printf("Computed limits:\n\n");

    printf("char  -> %d to %d\n", char_min, char_max);
    printf("short -> %d to %d\n", short_min, short_max);
    printf("int   -> %d to %d\n", int_min, int_max);
    printf("long  -> %ld to %ld\n", long_min, long_max);

    return 0;
}

void compute_limits()
{
    compute_char_limits();
    compute_short_limits();
    compute_int_limits();
    compute_long_limits();
}

void compute_char_limits()
{
    char c = 1;
    while (c > 0) c *= 2;
    while (c < 0) char_min = c--; 
    char_max = c;
}

void compute_short_limits() {
    short s = 1;
    while (s > 0) s *= 2;
    while (s < 0) short_min = s--; 
    short_max = s;
}
void compute_int_limits() {
    int i = 1;
    while (i > 0) i *= 2;
    while (i < 0) int_min = i--; 
    int_max = i;
}

void compute_long_limits() {
    long l = 1;
    while (l > 0) l *= 2;
    while (l < 0) long_min = l--;
    long_max = l;
}