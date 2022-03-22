#include <stdio.h>

#define MAX_LENGTH 1000
#define true 1
#define false 0

int is_blank_character(char c);
void try_print_line(char line[], int last_non_blank_index, int limit);
void print_line(char line[], int max_pos, int limit);

// Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
// and to delete entirely blank lines.
int main(void)
{
    int c;
    int i = 0;
    int last_non_blank_index = -1;
    char line[MAX_LENGTH];

    while (true) {
        c = getchar();

        line[i] = c;

        if (!is_blank_character(c))
            last_non_blank_index = i;

        if (c == '\n' || c == EOF) {
            try_print_line(line, last_non_blank_index, MAX_LENGTH);

            if (c == EOF) return 0;

            i = 0;
            last_non_blank_index = -1;
        } else
            i++;
    }

    return 0;
}

int is_blank_character(char c)
{
    if (c == '\t' || c == '\b' || c == ' ' || c == '\n' || c == EOF)
        return true;
    else
        return false;
}

void try_print_line(char line[], int last_non_blank_index, int limit)
{
    if (last_non_blank_index == -1) return;
    print_line(line, last_non_blank_index, limit);
    putchar('\n');
}

void print_line(char line[], int max_pos, int limit)
{
    for (int i = 0;  i <= max_pos && i < limit; ++i)
        putchar(line[i]);
}