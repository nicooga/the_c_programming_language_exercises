#include <stdio.h>

int strindex(char s[], char t[]);
int is_substring(char s[], char t[], int i);

// Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
// occurrence of t in s, or -1 if there is none. 
int main(void)
{
    char s1[] = "asdf-qwer-asdf-qwer";

    if (strindex(s1, "asdf") != 10) return 1;
    if (strindex(s1, "qwer") != 15) return 1;
    if (strindex(s1, "uiop") != -1) return 1;

    return 0;
}

int strindex(char s[], char t[])
{
    int last_ocurrence = -1;

    for (int i = 0; s[i] != '\0'; i++)
        if (is_substring(s, t, i))
            last_ocurrence = i;

    return last_ocurrence;
};

/* Returns 0 if string t matches string s at position i */
int is_substring(char s[], char t[], int i)
{
    // printf("s: %s\n", s);
    // printf("t: %s\n", t);

    for (int j = i; t[j-i] != '\0' && s[j] != '\0'; j++) {
        // printf("i: %d, j: %d\n", i, j);
        if (s[j] != t[j-i]) return 0;
    }

    return 1;
}