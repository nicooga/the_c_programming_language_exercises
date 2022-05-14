#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "lib/stack.h"

static int run_lineal_test(void);
static int run_exponential_test(void);
static int run_single_test(void);
static int run_test(size_t initial_stack_size);
static int do_run_test(size_t initial_stack_size);

#define VERBOSE 0

int main(void)
{
    char line[100];

    VERBOSE && printf("--- Running resizing stack tests ...\n");

    if (!run_single_test())
        return 1;

    if (!run_lineal_test())
        return 1;

    if (!run_exponential_test())
        return 1;

    return 0;
}

int run_lineal_test()
{
    for (int i = 1; i < 1000; i++)
        if (!run_test(i))
            return 1;
}

int run_exponential_test()
{
    for (int i = 1; i < pow(2, 19); i *= 2)
        if (!run_test(i))
            return 1;

    return 1;
}

int run_single_test()
{
    run_test(2);
}

int run_test(size_t N)
{
    VERBOSE && printf("--- ... for initial_size=%lu ...", N);
    int result = do_run_test(N);
    if (VERBOSE && result)
        printf(" success\n");
    return result;
}

int do_run_test(size_t N)
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

    return 1;
}
