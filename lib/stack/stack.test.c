#include <assert.h>
#include "lib/stack.h"

int run_test(size_t initial_stack_size);

int main(void)
{
    if (!run_test(100)) return 1;
    return 0;
}

int run_test(size_t initial_stack_size) {
    void *s = stack_create(initial_stack_size);

    assert(stack_size(s) == 0);
    stack_push_double(s, 1.1);
    assert(stack_size(s) == 1);
    stack_push_double(s, 2.2);
    assert(stack_size(s) == 2);
    stack_push_double(s, 3.3);
    assert(stack_size(s) == 3);
    assert(stack_pop_double(s) == 3.3);
    assert(stack_size(s) == 2);
    assert(stack_pop_double(s) == 2.2);
    assert(stack_size(s) == 1);
    assert(stack_pop_double(s) == 1.1);
    assert(stack_size(s) == 0);

    return 1;
}
