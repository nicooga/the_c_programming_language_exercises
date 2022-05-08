#include <math.h>
#include <assert.h>
#include "lib/stack.h"
#include "lib/input.h"

int run_test(size_t initial_stack_size);

int main(void)
{
    char line[100];

    printf("--- Running resizing stack tests ...\n");

    for (int i = 1; i < pow(2, 19); i *= 2) {
        printf("--- ... for initial_size=%d ...", i);
        if (!run_test(i)) return 1;
        printf(" success\n");
        read_word(line, 100);
    }

    return 0;
}

int run_test(size_t N) {
    void *s = stack_create(N);

    assert(stack_size(s) == 0);

    for (int i = 1; i <= N; i++) {
        stack_push_double(s, i * 1.1);
        assert(stack_size(s) == i);
    }

    for (int i = N; i >= 1; i--) {
        assert(stack_pop_double(s) == i * 1.1);
        assert(stack_size(s) == i-1);
    }

    stack_free(s);

    return 1;
}
