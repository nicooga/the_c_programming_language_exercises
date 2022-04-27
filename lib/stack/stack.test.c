#include "lib/stack.h"

int main(void)
{
    if (stack_size() != 0) return 1;
    stack_push(1);
    if (stack_size() != 1) return 1;
    stack_push(2);
    if (stack_size() != 2) return 1;
    stack_push(3);
    if (stack_size() != 3) return 1;
    if (stack_pop() != 3) return 1;
    if (stack_size() != 2) return 1;
    if (stack_pop() != 2) return 1;
    if (stack_size() != 1) return 1;
    if (stack_pop() != 1) return 1;
    if (stack_size() != 0) return 1;

    return 0;
}