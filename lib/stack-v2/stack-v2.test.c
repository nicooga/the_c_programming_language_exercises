#include <assert.h>
#include <math.h>
#include "lib/stack-v2.h"

static void run_performance_test(void);

static void run_lineal_test(void);
static void run_exponential_test(void);
static void run_single_test(void);
static void run_test(size_t initial_stack_size);
static void do_run_test(size_t N);

static int TRIALS = 10;

int main(void)
{
    run_performance_test();
    return 0;
}

static void run_performance_test()
{
    run_single_test();
    // run_lineal_test();
    // run_exponential_test();
}

static void run_lineal_test()
{
    for (int i = 1; i < 1000; i++)
        run_test(i);
}

static void run_exponential_test()
{
    for (int i = 1; i < pow(2, 19); i *= 2)
        run_test(i);
}

static void run_single_test() { run_test(2); }

static void run_test(size_t N)
{
    while (TRIALS--)
        do_run_test(N);
}

static void do_run_test(size_t N)
{
    Stack s;

    assert(s = stack_create(sizeof(double), N));
    assert(stack_size(s) == 0);

    for (int i = 1; i <= N; i++)
    {
        double value = i * 1.111;
        assert(stack_push(s, (char *)&value));
        assert(stack_size(s) == i);
    }

    for (int i = N; i >= 1; i--)
    {
        double *v = stack_pop(s);
        assert(*v == i * 1.111);
        assert(stack_size(s) == i - 1);
    }

    free(s);
}
