#include <stdlib.h>
// TODO: Remove this
#include <stdio.h>

// TODO: use a struct here, and then remove obsolete explanatory comment.
// A Stack is a block of memory that can hold N items of Size S.
// It's structure is as follows:
// [
//   (sizeof(size_t) bytes): max_size,
//   (sizeof(size_t) bytes): current_size,
//   (sizeof(char) bytes): item_size,
//   (current_size * item_size bytes): array of <current_size> items
// ]
//
typedef void **Stack;
// These are pointer getters.
// Should be made obsolete with structs.
#define MAX_SIZE_P(s) *s
#define CURRENT_SIZE_P(s) *s + sizeof(size_t)
#define ITEM_SIZE_P(s) *s + sizeof(size_t) * 2
#define NEXT_ITEM_P(s) *s + sizeof(size_t) * 2 + sizeof(char) + cs *is;
#define CURRENT_ITEM_P(s) *s + sizeof(size_t) * 2 + sizeof(char) + (cs - 1) * is;

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

static char _resize(Stack s, size_t new_size);

Stack stack_create(char item_size, size_t initial_max_size)
{
    Stack s = malloc(sizeof(Stack));

    *s = malloc(_consumption_in_bytes(item_size, initial_max_size));

    _set_max_size(s, initial_max_size);
    _set_current_size(s, 0);
    _set_item_size(s, item_size);

    return s;
}

size_t stack_size(Stack s) { return _current_size(s); }

// Returns 1 if push was successful.
// Returns 0 if a resize was needed and failed to allocate memory for it.
char stack_push(Stack s, char *item)
{
    size_t ms = _max_size(s);
    size_t cs = _current_size(s);
    char is = _item_size(s);

    if (cs == ms && !_resize(s, ms * 2))
        return 0;

    char *original_head = NEXT_ITEM_P(s);
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
    void *value = CURRENT_ITEM_P(s);
    _set_current_size(s, cs - 1);
    return value;
}

static char _resize(Stack s, size_t new_size)
{
    char is = _item_size(s);
    *s = realloc(*s, _consumption_in_bytes(is, new_size));

    if (*s == NULL)
        return 0;

    _set_max_size(s, new_size);

    return 1;
}

static void _set_max_size(Stack s, size_t initial_max_size)
{
    size_t *write_head = MAX_SIZE_P(s);
    *write_head = initial_max_size;
}

static size_t _max_size(Stack s)
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

static int _consumption_in_bytes(char item_size, size_t max_size)
{
    return sizeof(size_t) * 2 + sizeof(char) + item_size * max_size;
}
