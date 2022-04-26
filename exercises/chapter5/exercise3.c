#include <stdio.h>
#include "lib/stack.h"

void my_strcat(char *s, char *t);

// Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
// strcat(s,t) copies the string t to the end of s.
int main(void)
{
    char s1[] = "asdf";
    char s2[] = "qwer";

    my_strcat(s1, s2);

    if (strcmp(s1, "asdfqwer") != 0) return 1;

    return 0;
}

void my_strcat(char *s, char *t)
{
    while (*s != '\0') s++;
    while (*s++ = *t++);
}
