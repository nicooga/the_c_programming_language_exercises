#include <stdio.h>
#include <ctype.h>

#define true 1
#define false 0

#define MAX_LENGTH 1000

void expand(char s1[], char s2[]);
int is_shorthand_notation(char s[], int i);
int expand_shortand_notation(char s[], int j, char start, char end);
void read_string(char s[], int lim);

// Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
// the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
// case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
// that a leading or trailing - is taken literally.
int main(void)
{
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];

    read_string(s1, MAX_LENGTH);
    expand(s1, s2);
    printf("%s", s2);

    return 0;
}

void read_string(char s[], int lim)
{
    int i = 0;
    char c;
    while (--lim > 0 && (c = getchar()) != EOF) s[i++] = c;
    s[i] = '\0';
};

void expand(char s1[], char s2[])
{
    int i, j;

    for (i = 0, j = 0; s1[i] != '\0'; i++)
        if (is_shorthand_notation(s1, i)) {
            j += expand_shortand_notation(s2, j, s1[i], s1[i+2]);
            i += 2;
        } else
            s2[j++] = s1[i];

    s2[j] = '\0';
}

int is_shorthand_notation(char s[], int i)
{
    return (
        (isdigit(s[i]) && s[i+1] == '-' && isdigit(s[i+2])) ||
        (isalpha(s[i]) && s[i+1] == '-' && isalpha(s[i+2]))
    ) && s[i] < s[i+2];
}

/* Expand shorthand notation into string s, starting at position i. Returns the count of characters in the expansion */
int expand_shortand_notation(char s[], int i, char start, char end)
{
    int j = i;
    while (start <= end) s[j++] = start++;
    return j - i;
}