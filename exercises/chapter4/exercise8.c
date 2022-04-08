#include <stdio.h>
#define BUFFER_SIZE 100

char read_char(void);
void unread_char(char c);

char buffered_char = '\0';
 
// Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify
// getch and ungetch accordingly
int main(void)
{
    char c = read_char();
    char t;
    if (c == EOF) return 1;
    unread_char(c);
    t = read_char();
    if (t != c) return 1;
    return 0;
}

char read_char(void)
{
    if (buffered_char != '\0') {
        char c = buffered_char;
        buffered_char = '\0';
        return c;
    } else
        getchar();
}

void unread_char(char c)
{
    if (buffered_char == '\0')
        buffered_char = c;
    else
        printf("unread_char: too many characters\n");
}

