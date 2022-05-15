#include <stdio.h>
#include <ctype.h>
#include "lib/stack.h"
#include "lib/input.h"

#define STACK_INITIAL_SIZE 8
#define MAX_TERM_SIZE 40
#define OPERAND 0

static void *stack;

static char read_action(char *action, double *payload);
static void reduce(char action, double payload);
static void push(double value);
static double pop(void);

// Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the
// command line, where each operator or operand is a separate argument. For example,
//
//     expr 2 3 4 + *
//
// evaluates 2 * (3+4).
int main(void)
{
    stack = stack_create(STACK_INITIAL_SIZE);

    char action;
    double payload;

    while (read_action(&action, &payload) != -1)
        reduce(action, payload);

    printf("%.2f\n", pop());
}

char read_action(char *action, double *payload)
{
    char term[MAX_TERM_SIZE];

    if (read_word(term, MAX_TERM_SIZE) == -1)
        return -1;

    if (isdigit(term[0]) || (term[0] == '-' && isdigit(term[1])))
    {
        *payload = atof(term);
        *action = OPERAND;
    }
    else if (term[1] != 0)
    {
        printf("invalid term '%s'\n", term);
        return -1;
    }
    else
        *action = term[0];

    return 1;
}

void reduce(char action, double payload)
{
    double temp_operand;

    switch (action)
    {
    case OPERAND:
        push(payload);
        break;

    case '+':
        push(pop() + pop());
        break;

    case '-':
        temp_operand = pop();
        push(pop() - temp_operand);
        break;

    case '*':
        push(pop() * pop());
        break;

    case '/':
        temp_operand = pop();
        push(pop() / temp_operand);
        break;
    }
}

static void push(double value) { stack_push_double(stack, value); }
static double pop(void) { return stack_pop_double(stack); }
