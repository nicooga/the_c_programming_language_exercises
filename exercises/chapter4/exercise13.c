#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void _reverse(char s[], int i, int length);

// Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the
// string s in place.
int main(void)
{
    char s[] = "asdfqwer";
    reverse(s);
    if (strcmp(s, "rewqfdsa") != 0) return 1;
    return 0;
}

void reverse(char s[])
{
    int l = strlen(s);
    _reverse(s, 0, l);
}

void _reverse(char s[], int i, int length)
{
    if (i >= length/2) return;
    char temp = s[i];
    s[i] = s[length-1-i];
    s[length-1-i] = temp;
    _reverse(s, i+1, length);
}
