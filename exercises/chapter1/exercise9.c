#include <stdio.h>

#define NORMAL 0
#define CONSUMING_BLANKS 1

// Exercise 1-9. Write a program to copy its input to its output,
// replacing each string of one or more blanks by a single blank.
int main(void)
{
    int state = NORMAL;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (state == NORMAL) {
                putchar(' ');
                state = CONSUMING_BLANKS;
            }
        } else {
            state = NORMAL;
            putchar(c);
        }
    }
}
