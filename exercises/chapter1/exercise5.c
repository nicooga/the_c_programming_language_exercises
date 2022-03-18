#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

// Exercise 1-5. Modify the temperature conversion program to print the table in reverse order, 
// that is, from 300 degrees to 0.
int main(void)
{
    printf("C°\tF°\n");

    for (int cels = UPPER; cels >= LOWER; cels -= STEP)
        printf("%3d\t%6.1f\n", cels, cels * 9.0/5.0 + 32);
}
