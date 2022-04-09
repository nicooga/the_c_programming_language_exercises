#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "stack/stack.c"
#include "input/input.c"

#define MAX_LINE_LENGTH 100
#define MAX_PAYLOAD_LENGTH 100
#define MAX_OPERAND_LENGTH 100
#define OPERAND '0'

int line_index = 0;

void initialize_variables(void);
char read_action(char line[], char payload[]);
void reducer(char action, double payload);

// Exercise 4-10. An alternate organization uses getline to read an entire input line; this makes
// getch and ungetch unnecessary. Revise the calculator to use this approach.
int main(void)
{
    char line[MAX_LINE_LENGTH];
    char payload[MAX_PAYLOAD_LENGTH];

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

    switch (action) {
        case OPERAND:
            stack_push(payload);
            break;
        case '+':
            stack_push(stack_pop() + stack_pop());
            break;
        case '*':
            stack_push(stack_pop() * stack_pop());
            break;
        case '-':
            op2 = stack_pop();
            stack_push(stack_pop() - op2);
            break;
        case '/':
            op2 = stack_pop();
            if (op2 != 0.0) stack_push(stack_pop() / op2);
            else printf("error: zero divisor\n");
            break;
        case '%':
            op2 = stack_pop();
            if (op2 != 0.0) stack_push((int) stack_pop() % (int) op2);
            else printf("error: zero divisor\n");
            break;
        case '^':
            op2 = stack_pop();
            stack_push(pow(stack_pop(), op2));
            break;
        case 'e':
            stack_push(exp(stack_pop()));
            break;
        case 's':
            stack_push(sin(stack_pop()));
            break;
        case '=':
            stack_pop();
            stack_push(variables[var_index] = stack_pop());
            var_index = -1;
            break;
        case 'v':
            stack_push(last_printed_value);
            break;
        case '\n':
            last_printed_value = stack_pop();
            printf("%.8g\n", last_printed_value);
            break;
        default:
            if (action >= 'A' && action <= 'Z') {
                var_index = action - 'A';
                stack_push(variables[var_index]);
            } else
                printf("error: unknown command '%c'\n", action);
            break;
    }
}
