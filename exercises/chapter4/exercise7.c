#include <stdio.h>
#include "lib/input.h"

void read_string(char s[]);
void unread_string(char s[]);
int compare_strings(char s1[], char s2[]);

// Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
// Should ungets know about buf and bufp, or should it just use ungetch?
int main(void)
{
    char s1[100];
    char s2[100];
    read_string(s1);
    if (s1[0] == '\0') return 1; // This program needs input to make useful work
    for (int i = 0; s1[i] != '\0'; i++)
        printf("%c (%d)", s1[i], s1[i]);
    unread_string(s1);
    read_string(s2);
    if (!compare_strings("asdf", "asdf")) return 1;
    if (!compare_strings(s1, s2)) return 1;
    return 0;
}

// Returns 1 if strings are equal. Zero otherwise.
int compare_strings(char s1[], char s2[]) {
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
        if (s1[i] != s2[i]) return 0;

    return 1;
}

void read_string(char s[]) {
    char c;
    int i = 0;
    while ((c = read_char()) != EOF) s[i++] = c;
    s[i] = '\0';
}

void unread_string(char s[])
{
    int i = 0;
    while (s[i+1] != '\0') i++;
    while (i >= 0) unread_char(s[i--]);
}