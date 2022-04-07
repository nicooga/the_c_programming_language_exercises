#include "./input.c"

#define true 1
#define false 0

#define MAX_LENGTH 1000

// This test needs to be called with string "asdf" as input.
int main(void)
{
    if (read_char() != 'a') return 1;
    if (read_char() != 's') return 1;
    if (read_char() != 'd') return 1;
    if (read_char() != 'f') return 1;

    unread_char('f');
    if (read_char() != 'f') return 1;

    return 0;
}