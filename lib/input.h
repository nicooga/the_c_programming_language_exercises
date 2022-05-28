#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFFER_EXHAUSTED -2
#define READ_CHAR_INITIAL_BUFFER_SIZE 80
#define READ_LINES_INITIAL_BUFFER_SIZE 30
#define READ_LINES_INITIAL_LINES_SIZE 10

size_t read_line(char s[], int limit);
char **read_lines(unsigned int *line_count);
int read_word(char s[], int limit);
char read_char(void);
void unread_char(char c);

static void skip_blanks(void);
static int is_blank(char c);
static int to_digit(char c);

static char *buffer;
static size_t buffer_size = 0;
static size_t buffer_position = 0;

size_t read_line(char s[], int limit)
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

char **read_lines(unsigned int *line_count) {
    size_t buffer_size = READ_LINES_INITIAL_BUFFER_SIZE;
    size_t lines_size = READ_LINES_INITIAL_LINES_SIZE;

    char *buffer = malloc(sizeof(char) * buffer_size);
    char *initial_buffer = buffer;
    char **lines = malloc(sizeof(char *) * lines_size);

    unsigned int remaining_space_in_buffer = buffer_size;

    char **_lines = lines;
    size_t last_line_size;

    *line_count = 0;

    while (1)
    {

        for (int i = 0; i < lines_size; i++)
        {
            // for (int j = 0; j < buffer_size; j++)
            //     printf("buffer[%d]: %c (%d)\n", j, buffer[j], buffer[j]);

            printf("remaining_space_in_buffer: %u\n", remaining_space_in_buffer);

            last_line_size = read_line(buffer, remaining_space_in_buffer);

            printf("last_line_size: %lu\n", last_line_size);

            if (last_line_size == BUFFER_EXHAUSTED) {
                printf("buffer exhausted");
                buffer = realloc(buffer, sizeof(char) * (buffer_size *= 2));
                last_line_size = read_line(buffer, remaining_space_in_buffer);
                continue;
            }

            if (last_line_size == EOF)
                break;

            *_lines = buffer;

            (*line_count)++;
            remaining_space_in_buffer -= last_line_size + 1;
            _lines++;
            buffer += last_line_size + 1;
        }

        if (last_line_size == EOF)
            break;

        // lines = realloc(lines, sizeof(char *) * (lines_size *= 2));
        printf("================\n");
    }

    return lines;
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
        buffer = (char *)malloc(sizeof(char) * (buffer_size = READ_CHAR_INITIAL_BUFFER_SIZE));

    if (buffer_position > buffer_size - 1)
        buffer = realloc(buffer, sizeof(char) * (buffer_size *= 2));

    buffer[buffer_position++] = c;
}

int is_blank(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}
