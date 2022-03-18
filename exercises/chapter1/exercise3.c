#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

// Exercise 1-3. Modify the temperature conversion program to print a heading above the table. 
main()
{
    printf("F°\tC°\n");

    for (int fahr = UPPER; fahr >= LOWER; fahr -= STEP)
        printf("%3d\t%6.1f\n", fahr, 5.0/9.0 * (fahr-32));
}