#include <stdio.h>

#define MAX_LENGTH 1000
#define TARGET_LENGTH 80

void print_string(char string[], int length);
void try_print_string(char string[], int length);

// Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. 
int main(void)
{
    int length = 0;
    int c;
    char string[MAX_LENGTH];

    while ((c = getchar()) != EOF) {
        if (length < MAX_LENGTH)
            string[length] = c;

        length++;

        if (c == '\n') {
            try_print_string(string, length);
            length = 0;
        }
    }

    try_print_string(string, length);

    return 0;
}

void try_print_string(char string[], int length) {
    if (length >= TARGET_LENGTH)
        print_string(string, length);
}

void print_string(char string[], int length)
{
    for (int i = 0; i < length; i++)
        putchar(string[i]);
}