#include <stdbool.h>

#define MAX_SIZE 100

int stack_push(double item);
double stack_pop(void);
int stack_size(void);
void _stack_increment_size();
void _stack_decrement_size();

double stack[MAX_SIZE];
int _stack_size = 0;

int stack_push(double item)
{
    int s = stack_size();

    if (s == MAX_SIZE) return false;

    stack[s] = item;
    _stack_increment_size();

    return true;
}

double stack_pop(void)
{
    int s = stack_size();
    if (s == 0) return -1; // TODO: return null pointer instead (?)
    double item = stack[s-1];
    _stack_decrement_size();
    return item;
}

int stack_size() { return _stack_size; }

// TODO: find a way to make these truly private
void _stack_increment_size() { _stack_size++; }
void _stack_decrement_size() { _stack_size--; }
