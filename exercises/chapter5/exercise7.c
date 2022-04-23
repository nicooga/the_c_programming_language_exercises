#include <stdio.h>

#define MAX_LINES 1000
#define BUFFER_SIZE 20

#define STORAGE_EXHAUSTED -2

void read_lines(
    char *lines[],
    unsigned max_lines,
    char *buffer,
    size_t buffer_size
);

int read_line(char *p, char *max_p);

void print_lines(char *lines[]);

// Exercise 5-7. Rewrite readlines to store lines in an array supplied by main, rather than
// calling alloc to maintain storage. How much faster is the program?
int main(void)
{
    char *lines[MAX_LINES];
    char lines_storage[BUFFER_SIZE];

    read_lines(lines, MAX_LINES, lines_storage, BUFFER_SIZE);
    print_lines(lines);

    return 0;
}

// Read lines into `buffer`, storing pointers to their first char in `lines`.
void read_lines(
    char *lines[],
    unsigned max_lines,
    char *buffer,
    size_t buffer_size
)
{
    char *p = buffer;
    char *max_p = buffer + buffer_size - 1;
    int length;

    while (length = read_line(p, max_p)) {
        switch (length) {
            case EOF:
            case STORAGE_EXHAUSTED: return;
            case 0: continue;
            default:
                *lines++ = p;
                p += length;
        }
    }
}

// Read line into string pointed to by p, up to position pointed to by max_p.
// Return line length, -1 if EOF reached, or -2 if storage exhausted.
int read_line(char *p, char *max_p)
{
    int length = 0;

    while (1) {
        if (p > max_p) return length;

        char c = getchar();

        if (c == '\n') {
            *p++ = '\0';
            length++;
            return length;
        }

        if (c == EOF) return c;

        *p++ = c;
        length++;
    }

    return length;
}

void print_lines(char *lines[])
{
    char *line;
    while(line = *lines++) printf("%s\n", line);
}
