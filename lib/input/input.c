#include <stdio.h>

#define BUFFER_SIZE 100

int read_line(char s[], int limit);
char read_char(void);
void unread_char(char c);

char buffer[BUFFER_SIZE];
int buffer_size = 0;

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
