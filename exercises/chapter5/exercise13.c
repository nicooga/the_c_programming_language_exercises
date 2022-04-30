#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DEFAULT_LINE_COUNT 10
#define MAX_N_LENGTH 10
#define MAX_LINE_LENGTH 1000

int invoke_parse_args(int argc, char *argv[]);
int print_usage();
int read_int_from(char s[]);
int read_lines(char **lines, int line_count);
int read_line();
void print_lines(char **lines, int cursor);

static int line_count = DEFAULT_LINE_COUNT;

// Exercise 5-13. Write the program tail, which prints the last n lines of its input. By default, n
// is set to 10, let us say, but it can be changed by an optional argument so that
int main(int argc, char *argv[])
{
    invoke_parse_args(argc, argv);
    printf("line_count: %d\n", line_count);
    printf("\n");
    char *lines[line_count];
    int cursor = read_lines(lines, line_count);
    print_lines(lines, cursor);
    return 0;
}

int invoke_parse_args(int argc, char *argv[])
{
    if (strncmp(argv[1], "-n", 2) != 0) return print_usage();
    if (strlen(argv[1]) > 2) return print_usage();
    line_count = atoi(argv[2]);
}

int read_int_from(char s[])
{
    int i = 0;
    char t[MAX_N_LENGTH];
    while (s && isdigit(*s)) t[i++] = *s++;
    t[i] = '\0';
    return atoi(t);
}

int print_usage()
{
    fprintf(stderr, "Usage: -n N (print last N lines from stdin)\n");
    return 0;
}

static char *line; 

int read_lines(char *lines[], int line_count)
{
    int cursor = 0;
    int i = 0;

    while (1) {
        int j = i % line_count;
        if (lines[j] != 0) cursor = (j+1) % line_count;
        if (read_line() == EOF) return EOF;
        lines[j] = line;
        i++;
    };

    return cursor;
}

int read_line()
{
    char c;
    char *s = (char *) malloc(MAX_LINE_LENGTH);
    int i = 0;
    while ((c = getchar()) && c != '\n' && c != EOF) s[i++] = c;
    s[i] = '\0';
    line = s;
    return c == EOF ? c : i;
}

void print_lines(char **lines, int cursor)
{
    printf("cursor: %d\n", cursor);
    while (lines[cursor])
        printf("%s\n", lines[cursor++]);
}