#include <stdio.h>

#define BUFFER_SIZE 100

char read_char(void);
void unread_char(char c);

char buffer[BUFFER_SIZE];
int buffer_size = 0;

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
