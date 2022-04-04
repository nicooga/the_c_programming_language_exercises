#include <stdbool.h>

#define MAX_SIZE 100

int stack_push(int item);
int stack_pop(void);
int stack_size(void);
void stack_increment_size();
void stack_decrement_size();

int stack[MAX_SIZE];
int _stack_size = 0;

int stack_push(int item)
{
    int s = stack_size();

    if (s == MAX_SIZE) return false;

    stack[s] = item;
    stack_increment_size();

    return true;
}

int stack_pop(void)
{
    int s = stack_size();
    if (s == 0) return -1; // TODO: return null pointer instead (?)
    int item = stack[s-1];
    stack_decrement_size();
    return item;
}

int stack_size() { return _stack_size; }
void stack_increment_size() { _stack_size++; }
void stack_decrement_size() { _stack_size--; }