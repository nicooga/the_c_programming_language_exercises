#include <stdlib.h>
#include <stdbool.h>

#define SIZE 0
#define MAX_SIZE 1

void *stack_create(size_t initial_size);
void stack_free(void *stack);
int stack_push_double(void *stack, double value);
double stack_pop_double(void *stack);
size_t stack_size(void *stack);

static void _set_size(void *stack, size_t size);
static size_t _max_size(void *stack);
static void _set_max_size(void *stack, size_t size);
static int _resize(void **stack, size_t new_size);
static size_t _memory_consumption(size_t size);

// TODO: add overflow checks (?)
void *stack_create(size_t initial_size)
{
    void *stack = malloc(_memory_consumption(initial_size));
    if (!stack)
        return 0;
    _set_size(stack, 0);
    _set_max_size(stack, initial_size);
    return stack;
}

void stack_free(void *stack) { free(stack); }

int stack_push_double(void *stack, double value)
{
    size_t cs = stack_size(stack);
    size_t ms = _max_size(stack);
    if (cs == ms && !_resize(&stack, (ms *= 2)))
        return 0;
    ((double *)stack)[cs + 2] = value;
    _set_size(stack, ++cs);
    return 1;
}

double stack_pop_double(void *stack)
{
    size_t cs = stack_size(stack);
    size_t ms = _max_size(stack);
    if (cs == 0)
        return 0;
    double value = ((double *)stack)[cs + 1];
    _set_size(stack, --cs);
    if (cs < ms / 4)
        _resize(&stack, (ms /= 2));
    return value;
}

size_t stack_size(void *stack) { return ((size_t *)stack)[SIZE]; }

int _resize(void **stack, size_t new_size)
{
    size_t bytes = _memory_consumption(new_size);
    *stack = realloc(*stack, bytes);
    if (!*stack)
        return 0;
    _set_max_size(*stack, new_size);
    return 1;
}

void _set_size(void *stack, size_t x) { ((size_t *)stack)[SIZE] = x; }
size_t _max_size(void *stack) { return ((size_t *)stack)[MAX_SIZE]; }
void _set_max_size(void *stack, size_t x) { ((size_t *)stack)[MAX_SIZE] = x; }
size_t _memory_consumption(size_t size) { return sizeof(void *) * (size + 2); }
