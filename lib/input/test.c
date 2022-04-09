#include "./input.c"
#include "string/string.c"

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
    if (read_char() != '\n') return 1;

    unread_char('f');
    if (read_char() != 'f') return 1;

    unread_char('\n');
    unread_char('f');
    unread_char('d');
    unread_char('s');
    unread_char('a');

    char s[6];
    if (read_line(s, 6) != 5) return 1;
    if (!string_equals(s, "asdf\n")) return 1;

    return 0;
}
