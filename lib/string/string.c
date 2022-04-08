#include <stdio.h>

int string_equals(char s1[], char s2[]);

int string_equals(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
        if (s1[i] != s2[i]) return 0;

    return 1;
}