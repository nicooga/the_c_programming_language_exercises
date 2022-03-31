#include <stdio.h>
#include <limits.h>

void my_itoa(int n , char s[]);
void reverse(char s[]);
int length(char s[]);
int abs(int i);

// Exercise 3-4. In a two's complement number representation, our version of itoa does not 
// handle the largest negative number, that is, the value of n equal to -(2^(wordsize-1)). Explain why not.
// Modify it to print that value correctly, regardless of the machine on which it runs.
int main(void)
{
    char s[64];
    int n = INT_MAX;

    printf("n: %d\n", n);
    my_itoa(n, s);
    printf("my_itoa(n): %s\n", s);

    return 0;
}

/* itoa: convert n to characters in s */
void my_itoa(int n, char s[])
{
    int i = 0;
    short sign = n < 0 ? -1 : 1;

    do {
        s[i++] = abs(n % 10) + '0'; /* get next digit */
    } while ((n /= 10) != 0); /* delete it */

    if (sign < 0) s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}

void reverse(char s[])
{
    int l = length(s);

    for (int i = 0; i < l/2; i++) {
        char temp = s[i];
        s[i] = s[l-1-i];
        s[l-1-i] = temp;
    }
}

int length(char s[])
{
    int length;
    for (length = 0; s[length] != '\0'; length++);
    return length;
}

int abs(int i) {
    if (i < 0) return -i;
    return i;
}