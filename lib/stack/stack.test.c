#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "lib/stack.h"

static void run_performance_test(void);
static void run_lineal_test(void);
static void run_exponential_test(void);
static void run_single_test(void);
static void run_test(size_t initial_stack_size);

int main(void)
{
    run_performance_test();
    return 0;
}

void run_performance_test()
{
    run_single_test();
    run_lineal_test();
    run_exponential_test();
}

void run_lineal_test()
{
    for (int i = 1; i < 1000; i++)
        run_test(i);
}
void run_exponential_test()
{
    for (int i = 1; i < pow(2, 19); i *= 2)
        run_test(i);
}
void run_single_test() { run_test(2); }

void run_test(size_t N)
{
    void *s;

    for (int j = 1; j < 1000; j++)
    {
        assert(s = stack_create(N));

        assert(stack_size(s) == 0);

        for (int i = 1; i <= N; i++)
        {
            assert(stack_push_double(s, i * 1.111));
            assert(stack_size(s) == i);
        }

        for (int i = N; i >= 1; i--)
        {
            assert(stack_pop_double(s) == i * 1.111);
            assert(stack_size(s) == i - 1);
        }
    }

    stack_free(s);
}
