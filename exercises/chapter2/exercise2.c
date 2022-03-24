#include <stdio.h>

// Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
int main(void)
{
    int lim = 1000;
    int i = 0;
    char c;
    char s[lim];

    while (1) {
        if (i > lim-1) break;
        if ((c = getchar()) == '\n') break;
        if (c == EOF) break;
        s[i++] = c;
    }

    printf("s: %s\n", s);

    return 0;
}
