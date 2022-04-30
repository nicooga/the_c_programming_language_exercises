#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DEFAULT_LINE_COUNT 10
#define MAX_N_LENGTH 10
#define MAX_LINE_LENGTH 1000

static int line_count = DEFAULT_LINE_COUNT;
static int range_start;
static int range_end;
static char *line; 

static int invoke_parse_args(int argc, char *argv[]);
static int print_usage();
static int read_int_from(char s[]);
static void read_lines(char **lines);
static void push_range_start();
static int read_line();
static void print_lines(char **lines);
static void print_line(char *line);

// Exercise 5-13. Write the program tail, which prints the last n lines of its input. By default, n
// is set to 10, let us say, but it can be changed by an optional argument so that
int main(int argc, char *argv[])
{
    invoke_parse_args(argc, argv);
    char *lines[line_count];
    read_lines(lines);
    print_lines(lines);
    return 0;
}

int invoke_parse_args(int argc, char *argv[])
{
    if (strncmp(argv[1], "-n", 2) != 0) return print_usage();
    if (strlen(argv[1]) > 2) return print_usage();

    line_count = atoi(argv[2]);

    if (line_count < 0) {
        line_count = 0;
        return print_usage();
    }
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

void read_lines(char *lines[])
{
    int i = 0;
    range_start = -1;

    while (read_line()) {
        if (i == range_start) push_range_start();
        lines[i] = line;
        range_end = i;
        if (range_start == -1) range_start = i;
        i = (i + 1) % line_count;
    }
}

void push_range_start()
{
    range_start = (range_start + 1) % line_count;
}

int read_line()
{
    char c;
    char *s = (char *) malloc(MAX_LINE_LENGTH);
    int i = 0;
    while ((c = getchar()) && c != '\n' && c != EOF) s[i++] = c;
    s[i] = '\0';
    if (c == EOF && s[i] == '\0') return 0;
    line = s;
    return 1;
}


void print_lines(char *lines[])
{
    int _line_count = line_count;

    for (
        int i = range_start;
        _line_count-- && *lines[i];
        i = (i + 1) % line_count
    ) {
        print_line(lines[i]);
        if (i == range_end) break;
    }
}

void print_line(char *line)
{
    printf("%s\n", line);
}
