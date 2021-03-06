#include <stdio.h>
#include <string.h>

int string_equals(char s1[], char s2[]);

void string_reverse(char s[]);
void string_reverse_up_to(char s[], int p);
void _string_reverse(char s[], int p);

int string_equals(char *s1, char *s2)
{
    while (*s1 != '\0' || *s2 != '\0')
        if (*s1++ != *s2++)
            return 0;

    return 1;
}

void string_reverse(char s[])
{
    int l = strlen(s);
    _string_reverse(s, l);
}

void string_reverse_up_to(char s[], int p)
{
    _string_reverse(s, p+1);
}

void _string_reverse(char s[], int p)
{
    for (int i = 0; i < p/2; i++) {
        char temp = s[i];
        s[i] = s[p-1-i];
        s[p-1-i] = temp;
    }
}
