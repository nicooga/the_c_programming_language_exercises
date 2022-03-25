#include <stdio.h>

#define MAX_LENGTH 1000

int htoi(char s[]);
int hexadecimal_digit_to_i(char d);

// Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
// (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
// through 9, a through f, and A through F.
int main(void)
{
    int i;
    char c;
    char s[MAX_LENGTH];

    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < MAX_LENGTH; i++)
        s[i] = c;

    s[i] = '\0';

    printf("%d\n", htoi(s));

    return 0;
}

int htoi(char s[])
{
    int n = 0;

    for (
        int i = (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) ? 2 : 0;
        s[i] != '\0';
        i++
    )
        n = n * 16 + hexadecimal_digit_to_i(s[i]);

    return n;
}

int hexadecimal_digit_to_i(char d)
{
    if (d >= '0' && d <= '9')
        return d - '0';
    else if (d >= 'a' && d <= 'z')
        return d - 'a' + 10;
    else if (d >= 'A' && d <= 'Z')
        return d - 'A' + 10;
}