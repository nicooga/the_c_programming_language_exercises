// TODO: remove this import
#include <stdio.h>

#include <stdlib.h>
#include <stdbool.h>

#define SIZE 0
#define MAX_SIZE 1

#define MIN(a, b) (a) < (b) ? a : b

void *stack_create(size_t initial_size);
void *_create(size_t initial_size, size_t current_size);

void stack_push_double(void *stack, double value);
double stack_pop_double(void *stack);

size_t stack_size(void *stack);

static void _set_size(void *stack, size_t size);
static size_t _max_size(void *stack);
static void _set_max_size(void *stack, size_t size);
static void _resize(void *stack, size_t new_size);

// TODO: add overflow checks (?)
void *stack_create(size_t initial_size)
{
    return _create(initial_size, 0);
}

void stack_push_double(void *stack, double value)
{
    size_t cs = stack_size(stack);
    size_t ms = _max_size(stack);
    if ((cs + 1) == ms) _resize(stack, ms*2);
    ((double *) stack)[cs + 2] = value;
    _set_size(stack, ++cs);
}

double stack_pop_double(void *stack)
{
    size_t cs = stack_size(stack);
    size_t ms = _max_size(stack);
    if (cs == 0) return 0;
    double value = ((double *) stack)[cs + 1];
    if (cs < ms/4) _resize(stack, ms/2);
    _set_size(stack, --cs);
    return value;
}

size_t stack_size(void *stack) { return ((size_t *) stack)[SIZE]; }

void *_create(size_t initial_size, size_t current_size)
{
    size_t real_size = initial_size + 2;
    void *stack = malloc(real_size);

    _set_size(stack, current_size);
    _set_max_size(stack, initial_size);

    return stack;
}

void _resize(void *stack, size_t new_size)
{
    int current_size = stack_size(stack);
    int *new_stack = _create(new_size, current_size);
    int last_index = MIN(current_size, new_size) + 1;

    for (int i = 2; i <= last_index; i++)
      ((int *) new_stack)[i] = ((int *) stack)[i];

    stack = new_stack;
}

void _set_size(void *stack, size_t x) { ((size_t *) stack)[SIZE] = x; }
size_t _max_size(void *stack) { return ((size_t *) stack)[MAX_SIZE]; }
void _set_max_size(void *stack, size_t x) { ((size_t *) stack)[MAX_SIZE] = x; }
