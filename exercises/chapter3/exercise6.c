#include <stdio.h>

void my_itoa(int n , char s[], int p);
void reverse(char s[]);
int length(char s[]);
int abs(int i);

// Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
// argument is a minimum field width; the converted number must be padded with blanks on the
// left if necessary to make it wide enough.
int main(void)
{
    char s[64];
    int n = 366;
    short p = 10;

    my_itoa(n, s, p);

    printf("n: %d\n", n);
    printf("p: %d\n", p);
    printf("my_itoa(n, s, p): %s\n", s);

    return 0;
}

/* itoa: convert n to characters in s */
void my_itoa(int n, char s[], int p)
{
    int i = 0;
    short sign = n < 0 ? -1 : 1;

    do {
        s[i++] = abs(n % 10) + '0'; /* get next digit */
    } while ((n /= 10) != 0); /* delete it */

    if (sign < 0) s[i++] = '-';
    while (i < p) s[i++] = ' ';

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