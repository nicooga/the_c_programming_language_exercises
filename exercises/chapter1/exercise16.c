#include <stdio.h>

#define MAX_LENGTH 1000

int consume_next_line(char line[], int max_length); // Avoid name collision with already defined `get_line` function
void copy(char from[], char to[], int lim);

// Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print
// the length of arbitrary long input lines, and as much as possible of the text.
int main()
{
    int length;
    int max_length;
    char line[MAX_LENGTH];
    char longest_line[MAX_LENGTH];

    while ((length = consume_next_line(line, MAX_LENGTH)) > 0)
        if (length > max_length) {
            max_length = length;
            copy(line, longest_line, MAX_LENGTH);
        }

    if (max_length > 0)
        printf("%s\n", longest_line);

    return 0;
}

int consume_next_line(char s[], int max_length)
{
    int i, c;

    for (i = 0; (c = getchar()) != EOF; ++i) {
        if (i < max_length) s[i] = c;
        if (c == '\n') break;
    }

    s[i] = '\0';

    return i;
}

void copy(char from[], char to[], int lim)
{
    for (int i = 0; i < lim && (to[i] = from[i]) != '\0'; ++i);
}