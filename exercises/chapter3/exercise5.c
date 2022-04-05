#include <stdio.h>
#include <stdlib.h>

void itob(int n, char s[], int b);
char digit_to_char(short d);
void reverse(char s[]);
int length(char s[]);

// Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
// character representation in the string s. In particular, itob(n,s,16) formats s as a 
// hexadecimal integer in s. 
int main(void)
{
    char s[100];
    int n;
    int b;
    scanf("%d", &n);
    scanf("%d", &b);
    itob(n, s, b);
    printf("%s\n", s);
    return 0;
}


void itob(int n, char s[], int b)
{
   int i = 0;
   short sign = n < 0 ? -1 : 1;

    do {
        s[i++] = digit_to_char(abs(n % b));
    } while ((n /= b) != 0);

    if (sign < 0) s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}

char digit_to_char(short d)
{
    if (d >= 0 && d <= 9) return d + '0';
    else if (d > 9) return d - 10 + 'A';
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
