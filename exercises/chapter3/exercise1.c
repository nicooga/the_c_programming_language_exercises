#include <stdio.h>

#define N 10000
#define TRIALS 10000

int binsearch(int x, int v[], int n);
int binsearch_improved(int x, int v[], int n);

// Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at 
// the price of more tests outside.) Write a version with only one test inside the loop and
// measure the difference in run-time.
// Result: no noticeable difference
int main(void)
{
    int v[N];

    for (int i = 0; i < N; i++) v[i] = i;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < TRIALS; j++)
            // if (binsearch_improved(i, v, N) != i) return 1;
            if (binsearch(i, v, N) != i) return 1;

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid]) high = mid - 1;
        else if (x > v[mid]) low = mid + 1;
        else return mid;
    }

    return -1;
}

int binsearch_improved(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low != high) {
        mid = (low+high)/2;
        if (v[mid] < x) low = mid+1;
        else high = mid;
    }

    return v[low] == x ? low : -1;
}
