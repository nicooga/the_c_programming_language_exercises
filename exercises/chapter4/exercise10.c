#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "lib/stack.h"
#include "lib/input.h"

#define PUSH(value) stack_push_double(stack, value)
#define POP() stack_pop_double(stack)

#define MAX_LINE_LENGTH 100
#define MAX_PAYLOAD_LENGTH 100
#define MAX_OPERAND_LENGTH 100
#define OPERAND '0'

static int line_index = 0;
static void *stack;

void initialize_variables(void);
char read_action(char line[], char payload[]);
void reducer(char action, double payload);

// Exercise 4-10. An alternate organization uses getline to read an entire input line; this makes
// getch and ungetch unnecessary. Revise the calculator to use this approach.
int main(void)
{
    char line[MAX_LINE_LENGTH];
    char payload[MAX_PAYLOAD_LENGTH];
    stack = stack_create(8);

    while (read_line(line, MAX_LINE_LENGTH)) {
        while (line[line_index] != '\0') {
            char action = read_action(line, payload);
            reducer(action, atof(payload));
        }

        line_index = 0;
    }

    return 0;
}

char read_action(char line[], char payload[])
{
    int i = 0;
    char c;

    while (line[line_index] == ' ') line_index++;

    c = line[line_index++];

    if (!isdigit(c)) return c;

    payload[i++] = c;

    while(isdigit(payload[i++] = c = line[line_index++]));
    if (c == '.') while (isdigit(payload[i++] = c = line[line_index++]));

    payload[i] = '\0';

    return OPERAND;
}

void reducer(char action, double payload)
{
    static double variables[26];
    static double last_printed_value = 0;
    static int var_index;
    double op2;

    switch (action)
    {
    case OPERAND:
        PUSH(payload);
        break;
    case '+':
        PUSH(POP() + POP());
        break;
    case '*':
        PUSH(POP() * POP());
        break;
    case '-':
        op2 = POP();
        PUSH(POP() - op2);
        break;
    case '/':
        op2 = POP();
        if (op2 != 0.0)
            PUSH(POP() / op2);
        else
            printf("error: zero divisor\n");
        break;
    case '%':
        op2 = POP();
        if (op2 != 0.0)
            PUSH((int)POP() % (int)op2);
        else
            printf("error: zero divisor\n");
        break;
    case '^':
        op2 = POP();
        PUSH(pow(POP(), op2));
        break;
    case 'e':
        PUSH(exp(POP()));
        break;
    case 's':
        PUSH(sin(POP()));
        break;
    case '=':
        POP();
        PUSH(variables[var_index] = POP());
        var_index = -1;
        break;
    case 'v':
        PUSH(last_printed_value);
        break;
    case '\n':
        last_printed_value = POP();
        printf("%.8g\n", last_printed_value);
        break;
    default:
        if (action >= 'A' && action <= 'Z')
        {
            var_index = action - 'A';
            PUSH(variables[var_index]);
        }
        else
            printf("error: unknown command '%c'\n", action);
        break;
    }
}
