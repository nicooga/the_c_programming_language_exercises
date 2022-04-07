#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int stack_push(int item);
double stack_pop(void);
int stack_size(void);
int stack_peek(void);
void stack_duplicate_top(void);
void stack_swap_top(void);
void stack_clear(void);

void _stack_increment_size();
void _stack_decrement_size();

double stack[MAX_SIZE];
int _stack_size = 0;

// Exercise 4-4. Add the commands to print the top elements of the stack without popping, to
// duplicate it, and to swap the top two elements. Add a command to clear the stack.
int main(void)
{
    if (stack_size() != 0) return 1;

    for (int i = 0; i < 10; i++) {
        stack_push(i);
        if (stack_size() != i+1) return 1;
        if (stack_peek() != i) return 1;
    }

    for (int i = 9; i >= 0; i--) {
        if (stack_pop() != i) return 1;
        if (stack_size() != i) return 1;
    }

    for (int i = 0; i < 3; i++) stack_push(i);
    stack_duplicate_top();
    if (stack_pop() != 2) return 1;
    if (stack_pop() != 2) return 1;
    if (stack_pop() != 1) return 1;
    if (stack_pop() != 0) return 1;

    for (int i = 0; i < 3; i++) stack_push(i);
    stack_swap_top();
    if (stack_pop() != 1) return 1;
    if (stack_pop() != 2) return 1;
    if (stack_pop() != 0) return 1;

    for (int i = 0; i < 3; i++) stack_push(i);
    stack_clear();
    if (stack_size() != 0) return 1;

    return 0;
}

int stack_push(int item)
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
    if (s == 0) return -1; // todo: return null pointer instead (?)
    int item = stack[s-1];
    _stack_decrement_size();
    return item;
}

int stack_size() { return _stack_size; }

int stack_peek() { return stack[stack_size()-1]; }

void stack_duplicate_top()
{
    stack_push(stack_peek());
}

void stack_swap_top()
{
    int last = stack_pop();
    int next_to_last = stack_pop();
    stack_push(last);
    stack_push(next_to_last);
}

void stack_clear()
{
    _stack_size = 0;
}

// TODO: find a way to make these truly private
void _stack_increment_size() { _stack_size++; }
void _stack_decrement_size() { _stack_size--; }