#include <stdio.h>

#define MAX_WORD_LENGTH 20

// Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is 
// easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
int main(void)
{
    int word_count_by_length[MAX_WORD_LENGTH+1];
    int c;
    int cur_word_length = 0;

    for (int i = 1; i <= MAX_WORD_LENGTH; i++)
        word_count_by_length[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (cur_word_length > MAX_WORD_LENGTH)
                printf(
                    "Word length `%d` exceedes max word length `%d`",
                    cur_word_length,
                    MAX_WORD_LENGTH
                );
            else {
                ++word_count_by_length[cur_word_length];
                cur_word_length = 0;
            }
        } else
            ++cur_word_length;
    }

    for (int word_length = 1; word_length <= MAX_WORD_LENGTH; word_length++) {
        int word_count = word_count_by_length[word_length];

        printf("%3d: ", word_length);

        for (int i = 0; i < word_count; i++)
            printf("-");

        printf("\n");
    }
}