#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

double fahrenheit_to_celcius(int fahr)
{
    return 5.0/9.0 * (fahr-32);
}

// Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function
// for conversion.
int main(void)
{
    printf("F°\tC°\n");

    for (int fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d\t%6.1f\n", fahr, fahrenheit_to_celcius(fahr));

    return 0;
}