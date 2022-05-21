#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib/input.h"

typedef int (*comparator)(char *, char *);

int readlines(char *lineptr[], int nlines);
void print_lines(char *lineptr[], int nlines);
void my_qsort(
    char *lineptr[],
    int left, int right,
    comparator comp);
int numcmp(char *, char *);
void swap(char *v[], int, int);

// Exercise 5-14. Modify the sort program to handle a -r flag, which indicates sorting in reverse
// (decreasing) order. Be sure that -r works with -n.
int main(int argc, char *argv[])
{
    char **lines;
    int nlines;
    int numeric = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;

    line_count = read_lines(lines);

    comparator comp = numeric ? numcmp : (comparator)strcmp;

    my_qsort(lineptr, 0, nlines - 1, comp);
    print_lines(lineptr, nlines);

    return 0;
}

void my_qsort(
    char *v[],
    int left,
    int right,
    comparator comp)
{
    int i, last;

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);

    last = left;

    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);

    my_qsort(v, left, last - 1, comp);
    my_qsort(v, last + 1, right, comp);
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(char *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void print_lines(char *lineptr[], int nlines)
{
    while (nlines--)
        printf("%s\n", *lineptr++);
}
