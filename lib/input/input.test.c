#include <assert.h>
#include "lib/string.h"
#include "lib/input.h"

#define true 1
#define false 0

#define MAX_LENGTH 1000

static int test_read_char(void);
static int test_unread_char(void);
static int test_read_line(void);
static int test_read_lines(void);
static int test_read_word(void);
static int test_read_int(void);
static void unread_word(char *s);
static void clean_buffer(void);

// This test needs to be called with string "asdf" as input.
int main(void)
{
    // Careful with commenting this test.
    // It consumes the input provided to the program.
    // Some tests may fail without this.
    if (!test_read_char())
        return 1;

    // if (!test_unread_char())
    //     return 1;

    // if (!test_read_line())
    //     return 1;

    if (!test_read_lines())
        return 1;

    // if (!test_read_word())
    //     return 1;

    // if (!test_read_int())
    //     return 1;

    return 0;
}

int test_read_char(void)
{
    if (read_char() != 'a')
        return 0;

    if (read_char() != 's')
        return 0;

    if (read_char() != 'd')
        return 0;

    if (read_char() != 'f')
        return 0;

    if (read_char() != '\n')
        return 0;

    if (read_char() != EOF)
        return 0;

    return 1;
}

int test_unread_char(void)
{
    unread_char('f');

    if (read_char() != 'f')
        return 0;

    for (int i = 0; i < 10000000; i++)
        unread_char('a');

    for (int i = 0; i < 10000000; i++)
        if (read_char() != 'a') return 0;

    clean_buffer();

    return 1;
}

int test_read_line(void)
{
    int max_length = 10;
    char s[max_length];

    unread_word("  asdf  \n  qwer  \n");

    if (read_line(s, max_length) != 9)
        return 0;

    if (!string_equals(s, "  asdf  \n"))
        return 0;

    if (read_line(s, max_length) != 9)
        return 0;

    if (!string_equals(s, "  qwer  \n"))
        return 0;

    if (read_line(s, max_length) != EOF)
        return 0;

    unread_word("  asdf  ");

    if (read_line(s, max_length) != -1)
        return 0;

    unread_word("asdfqwerzxcvuiop\n");

    if (read_line(s, max_length) != -2)
        return 0;

    clean_buffer();

    if (read_line(s, 0) != -2)
        return 0;

    return 1;
}

int test_read_lines(void)
{
    char **lines;
    unsigned int line_count = 0;

    for (int i = 0; i < 10; i++)
        unread_word("  asdf  \n  qwer \nuiop  \n");

    lines = read_lines(&line_count);

    assert(line_count == 30);

    for (int i = 0; i < 10; i++) {
        int offset = i * 3;
        printf("i: %d\n", i);
        if (i == 5) {
            printf("lines[%d]: %s\n", offset, lines[offset]);
        }
        assert(string_equals(lines[offset + 0], "  asdf  \n"));
        assert(string_equals(lines[offset + 1], "  qwer \n"));
        assert(string_equals(lines[offset + 2], "uiop  \n"));
    }

    return 1;
}

int test_read_word(void)
{
    char s[5];

    unread_word("   asdf  \n qwer    uiop  \n   ");

    read_word(s, 5);
    if (!string_equals(s, "asdf"))
        return 0;

    read_word(s, 5);
    if (!string_equals(s, "qwer"))
        return 0;

    read_word(s, 5);
    if (!string_equals(s, "uiop"))
        return 0;

    if (read_word(s, 5) != -1)
        return 0;

    return 1;
}

int test_read_int(void)
{
    unread_word("  15 23   +12 \n   22   0   -12  ");
    if (read_int() != 15)
        return 0;
    if (read_int() != 23)
        return 0;
    if (read_int() != 12)
        return 0;
    if (read_int() != 22)
        return 0;
    if (read_int() != 0)
        return 0;
    if (read_int() != -12)
        return 0;
    return 1;
}

void unread_word(char *s)
{
    char *original_s = s;

    while (*(s + 1))
        s++;

    while (s >= original_s)
        unread_char(*s--);
}

static void clean_buffer()
{
    while (read_char() != EOF)
        ;
}
