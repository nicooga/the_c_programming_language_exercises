#include <stdio.h>

#define MAX_LENGTH 1000

int any(char s1[], char s2[]);

// Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
// where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. 
// (The standard library function strpbrk does the same job but returns a pointer to the
// location.) 
int main(void)
{
    int i = 0;
    char c;
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];

    while ((c = getchar()) != EOF && c != '\n' && c != ' ')
        s1[i++] = c;

    s1[i] = '\0';

    i = 0;

    while ((c = getchar()) != EOF && c != '\n' && c != ' ')
        s2[i++] = c;

    s2[i] = '\0';

    printf("%d\n", any(s1, s2));

    return 0;
}

int any(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0'; i++)
        for (int j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return i;

    return -1;
}