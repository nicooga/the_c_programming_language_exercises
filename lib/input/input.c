#include <stdio.h>

#define BUFFER_SIZE 100

int read_line(char s[], int limit);
int read_word(char s[], int limit);
char read_char(void);
void unread_char(char c);

static void skip_blanks(void);
static int is_blank(char c);

static char buffer[BUFFER_SIZE];
static int buffer_size = 0;

// TODO: create new string and return pointer to it
int read_line(char s[], int limit)
{
    int i = 0;
    char c;
    while (i < limit-1 && (c = read_char()) != EOF && c != '\n') s[i++] = c;
    if (c == '\n') s[i++] = '\n';
    s[i] = '\0';
    return i;
}

int read_word(char s[], int limit)
{
    int i = 0;
    char c;

    skip_blanks();

    while (i < limit-1 && (c = read_char())) {
        if (c == EOF || is_blank(c)) break;
        s[i++] = c;
    }

    s[i] = '\0';

    return i;
}

void skip_blanks(void)
{
    char c;
    while ((c = read_char()) && is_blank(c));
    unread_char(c);
}

char read_char(void)
{
    return (buffer_size > 0) ? buffer[--buffer_size] : getchar();
}

void unread_char(char c)
{
    if (buffer_size >= BUFFER_SIZE)
        printf("unread_char: too many characters\n");
    else
        buffer[buffer_size++] = c;
}

int is_blank(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}