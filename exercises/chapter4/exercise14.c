#include <stdio.h>

#define swap(t, x, y) int temp = a; a = b; b = temp;

// Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t.
// (Block structure will help.)
int main(void)
{
    int a = 1;
    int b = 2;
    swap(int, a, b);
    if (a != 2) return 1;
    if (b != 1) return 1;
    return 0;
}
