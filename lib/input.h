#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 80
#define BUFFER_EXHAUSTED -2

int read_line(char s[], int limit);
int read_word(char s[], int limit);
char read_char(void);
void unread_char(char c);

static void skip_blanks(void);
static int is_blank(char c);
static int to_digit(char c);

static char *buffer;
static size_t buffer_size = 0;
static size_t buffer_position = 0;

int read_line(char s[], int limit)
{
    if (limit == 0) return BUFFER_EXHAUSTED;

    int i = 0;
    char c;

    while (--limit && (c = read_char()) != EOF) {
        s[i++] = c;
        if (c == '\n')
            break;
    }

    if (limit == 0) return BUFFER_EXHAUSTED;

    s[i] = '\0';

    return c == EOF ? EOF : i;
}

int read_word(char s[], int limit)
{
    int i = 0;
    char c;

    skip_blanks();

    while (--limit && (c = read_char()) != EOF && !is_blank(c))
        s[i++] = c;

    s[i] = '\0';

    if (c == EOF)
        return EOF;

    return i;
}

void skip_blanks(void)
{
    char c;
    while ((c = read_char()) && is_blank(c))
        ;
    unread_char(c);
}

int read_int(void)
{
    int n = 0;
    char sign = 1;

    skip_blanks();

    char c = read_char();

    if (c == '-')
    {
        sign = EOF;
        c = read_char();
    };

    if (c == '+')
        c = read_char();

    while (isdigit(c))
    {
        int d = to_digit(c);
        n = n * 10 + d;
        c = read_char();
    }

    unread_char(c);

    return n * sign;
}

int to_digit(char c)
{
    return c - '0';
}

char read_char(void)
{
    if (buffer_position > 0)
        return buffer[--buffer_position];

    return getchar();
}

void unread_char(char c)
{
    if (buffer_size == 0lu)
        buffer = (char *)malloc(sizeof(char) * (buffer_size = INITIAL_BUFFER_SIZE));

    if (buffer_position > buffer_size - 1)
        buffer = realloc(buffer, sizeof(char) * (buffer_size *= 2));

    buffer[buffer_position++] = c;
}

int is_blank(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}
