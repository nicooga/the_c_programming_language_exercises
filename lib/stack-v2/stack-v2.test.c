#include <assert.h>
#include <math.h>
#include "lib/stack-v2.h"

#define MAX_EXPONENT 19

static void run_performance_test(void);

static void run_lineal_test(void);
static void run_exponential_test(void);
static void run_single_test(void);
static void run_test(size_t initial_stack_size);
static void do_run_test(size_t N);

int main(void)
{
    run_performance_test();
    return 0;
}

static void run_performance_test()
{
    run_single_test();
    run_exponential_test();
}

static void run_single_test() { run_test(100); }

static void run_exponential_test()
{
    for (int i = 1; i < pow(2, MAX_EXPONENT); i *= 2)
        run_test(i);

    run_test(pow(2, 16));
}

static void run_test(size_t N)
{
    Stack s;

    assert(s = stack_create(sizeof(double), 1));
    assert(stack_size(s) == 0);

    for (int i = 1; i <= N; i++)
    {
        double value = i * 1.111;
        assert(stack_push(s, (char *)&value));
        assert(stack_size(s) == i);
    }

    for (int i = N; i >= 1; i--)
    {
        double *value = stack_pop(s);
        assert(*value == i * 1.111);
        assert(stack_size(s) == i - 1);
    }

    free(s);
}
