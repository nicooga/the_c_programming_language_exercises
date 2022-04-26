#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib/stack.h"
#include "lib/string.h"

void my_itoa(int n, char s[]);
int _my_itoa(int n, char s[], int i);
void reverse(char s[]);

// Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert
// an integer into a string by calling a recursive routine.
int main(void)
{
    char s[11];
    my_itoa(1234567890, s);
    printf("%s\n", s);
    if (strcmp(s, "1234567890") != 0) return 1;
    return 0;
}

void my_itoa(int n, char s[])
{
    int i = 0;
    short sign = n < 0 ? -1 : 1;
    i = _my_itoa(n, s, 0);
    i++;
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';
    string_reverse_up_to(s, i-1);
}

int _my_itoa(int n, char s[], int i)
{
    s[i] = abs(n % 10) + '0';
    n /= 10;
    if (n != 0) _my_itoa(n, s, i+1);
    else return i;
}
