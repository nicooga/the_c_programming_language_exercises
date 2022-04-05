#include <stdio.h>

#define MAX_LENGTH 1000

int read_string(char s[], int lim);
int strindex(char s[], int s_size, char t[], int t_size);
int is_substring(char s[], char t[], int i);

// Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
// occurrence of t in s, or -1 if there is none. 
int main(void)
{
    char s[MAX_LENGTH];
    char t[MAX_LENGTH];
    int s_size = read_string(s, MAX_LENGTH);
    int t_size = read_string(t, MAX_LENGTH);
    printf("%d\n", strindex(s, s_size, t, t_size));
    return 0;
}

int read_string(char s[], int lim)
{
    char c;
    int i = 0;
    while ((c = getchar()) != EOF && c != ',' && c != '\n') s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], int s_size, char t[], int t_size)
{
    for (int i = s_size-t_size; i >= 0; i--)
        if (is_substring(s, t, i))
            return i;

    return -1;
};

/* Returns 1 if string t matches string s at position p */
int is_substring(char s[], char t[], int p)
{
    for (int i = p; t[i-p] != '\0' && s[i] != '\0'; i++)
        if (s[i] != t[i-p]) return 0;

    return 1;
}