#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

// Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table. 
int main(void)
{
    printf("C°\tF°\n");

    for (int cels = LOWER; cels <= UPPER; cels += STEP)
        printf("%3d\t%6.1f\n", cels, cels * 9.0/5.0 + 32);
}
