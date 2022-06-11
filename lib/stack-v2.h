#include <stdlib.h>
// TODO: Remove this
#include <stdio.h>

typedef void *Stack;
// TODO: use a struct here
// A Stack is a block of memory that can hold N items of Size S.
// It's structure is as follows:
// first sizeof(size_t) bytes => max size (M)
// next sizeof(size_t) bytes => current size (N, N < M)
// next sizeof(char) byte => item size in bytes (I)
// next N * I bytes => array

// These are pointer getters.
// Non-sense, should be made obsolete with structs.
#define MAX_SIZE_P(s) s
#define CURRENT_SIZE_P(s) s + sizeof(size_t)
#define ITEM_SIZE_P(s) s + sizeof(size_t) * 2

Stack stack_create(char item_size, size_t initial_size);
char stack_push(Stack s, char *item);
void *stack_pop(Stack s);
size_t stack_size(Stack s);

static int _consumption_in_bytes(char item_size, size_t initial_max_size);

static void _set_max_size(Stack s, size_t max_size);
static size_t _max_size(Stack s);

static void _set_current_size(Stack s, size_t size);
static size_t _current_size(Stack s);

static void _set_item_size(Stack s, char item_size);
static char _item_size(Stack s);

Stack stack_create(char item_size, size_t initial_max_size)
{
    Stack s = malloc(_consumption_in_bytes(item_size, initial_max_size));

    _set_max_size(s, initial_max_size);
    _set_current_size(s, 0);
    _set_item_size(s, item_size);

    return s;
}

size_t stack_size(Stack s) { return _current_size(s); }

char stack_push(Stack s, char *item)
{
    char ms = _max_size(s);
    char cs = _current_size(s);
    char is = _item_size(s);

    // TODO: upsize
    if (cs == ms)
        return 0;

    char *original_head =
        s + sizeof(size_t) * 2 + sizeof(char) + cs * is;

    char *head = original_head;

    while (is--)
        *head++ = *item++;

    _set_current_size(s, cs + 1);

    return 1;
}

void *stack_pop(Stack s)
{

    size_t cs = _current_size(s);
    char is = _item_size(s);
    void *value =
        s + sizeof(size_t) * 2 + sizeof(char) + (cs - 1) * is;

    _set_current_size(s, cs - 1);

    return value;
}

static int _consumption_in_bytes(char item_size, size_t max_size)
{
    return sizeof(size_t) * 2 + sizeof(char) + item_size * max_size;
}

static void _set_max_size(Stack s, size_t initial_max_size)
{
    size_t *write_head = MAX_SIZE_P(s);
    *write_head = initial_max_size;
}

size_t _max_size(Stack s)
{
    size_t *read_head = MAX_SIZE_P(s);
    return *read_head;
}

static void _set_current_size(Stack s, size_t size)
{
    size_t *write_head = CURRENT_SIZE_P(s);
    *write_head = size;
}

static size_t _current_size(Stack s)
{
    size_t *read_head = CURRENT_SIZE_P(s);
    return *read_head;
}

static void _set_item_size(Stack s, char item_size)
{
    char *write_head = ITEM_SIZE_P(s);
    *write_head = item_size;
}

static char _item_size(Stack s)
{
    char *read_head = ITEM_SIZE_P(s);
    return *read_head;
    return *read_head;
}
