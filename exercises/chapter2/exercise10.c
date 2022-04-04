#include <stdio.h>

#define MAX_LENGTH 1000

int lower(int c);

// Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case,
// with a conditional expression instead of if-else. 
int main(void)
{
    char c;

    while ((c = getchar()) != EOF)
        printf("%c", lower(c));

    return 0;
}

int lower(int c)
{
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}