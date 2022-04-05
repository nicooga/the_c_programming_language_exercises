#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 100

double atof(char s[]);
int my_atoi(char s[], int i);
void read_float(char s[], int lim);

// Exercise 4-2. Extend atof to handle scientific notation of the form `123.45e-6`
// where a floating-point number may be followed by e or E and an optionally signed exponent. 
int main(void)
{
    char s[MAX_LENGTH];
    read_float(s, MAX_LENGTH);
    printf("%f\n", atof(s));
    return 0;
}

void read_float(char s[], int lim)
{
    int i = 0;
    char c;
    while ((c = getchar()) != EOF &&c != '\n') s[i++] = c;
    s[i] = '\0';
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val = 0.0;
    double coefficient = 1.0;
    int i = 0;
    int sign = (s[0] == '-') ? -1 : 1;

    while (isspace(s[i])) i++;

    if (s[i] == '+' || s[i] == '-') i++;

    for (; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.') i++;

    for (; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        coefficient /= 10;
    }

    if (s[i] == 'e') {
        i++;
        int power = my_atoi(s, i);
        if (power > 0) for (int j = 0; j < power; j++) coefficient *= 10;
        if (power < 0) for (int j = 0; j < -power; j++) coefficient /= 10;
    }

    return sign * val * coefficient;
}

int my_atoi(char s[], int i)
{
    int val = 0;
    int sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-') i++;

    for (; s[i] != '\0'; i++)
        val = val * 10 + (s[i] - '0');

    return sign * val;
};