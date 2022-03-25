#include <stdio.h>

#define MAX_LENGTH 1000

int string_includes(char s[], char c);
void squeeze(char s1[], char s2[]);

// Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
// s1 that matches any character in the string s2.
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

    squeeze(s1, s2);
    printf("%s\n", s1);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++)
        if (!string_includes(s2, s1[i]))
            s1[j++] = s1[i];

    s1[j] = '\0';
}

int string_includes(char s[], char c) {
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            return 1;

    return 0;
}