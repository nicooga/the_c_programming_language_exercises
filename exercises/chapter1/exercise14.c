#include <stdio.h>

#define MAX_ASCII_CODE 256

// Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
// in its input.
int main(void)
{
    int c;
    int character_counts[MAX_ASCII_CODE+1];
    int max_char_found = 0;

    for (int i = 0; i <= MAX_ASCII_CODE; i++)
        character_counts[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c > MAX_ASCII_CODE) {
            printf("Char code %d exceedes maximum expected value of %d", c, MAX_ASCII_CODE);
            return 1;
        }

        ++character_counts[c];

        if (c > max_char_found)
            max_char_found = c;
    }

    for (int i = 0; i <= max_char_found; i++) {
        printf("%c: ", i);
        for (int j = 0; j < character_counts[i] / 2.0; j++) printf("-");
        printf("\n");
    }

    return 0;
}
