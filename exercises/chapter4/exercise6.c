#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "stack/stack.c"
#include "input/input.c"

#define MAXOP 100
#define OPERAND '0'

int get_operand_or_operator(char s[]);
void consume_blanks(void);

// Exercise 4-6. Add access to library functions like sin, exp, and pow. See <math.h> in
// Appendix B, Section 4.
int main(void)
{
    int type;
    int var_index;
    double op2;
    double last_printed_value = 0;
    char s[MAXOP];
    double variables[26];

    for (int i = 0; i < 26; i++) variables[i] = 0;

    while ((type = get_operand_or_operator(s)) != EOF)
        switch (type) {
            case OPERAND:
                stack_push(atof(s));
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
            default: {
                if (type >= 'A' && type <= 'Z') {
                    var_index = type - 'A';
                    stack_push(variables[var_index]);
                } else
                    printf("error: unknown command '%c'\n", type);
                break;
            }
        }

    return 0;
}

int get_operand_or_operator(char s[])
{
    int i = 0;
    char c;

    consume_blanks();

    c = read_char();

    if (!isdigit(c)) return c;

    s[i++] = c;

    while(isdigit(s[i++] = c = read_char()));
    if (c == '.') while (isdigit(s[i++] = c = read_char()));

    s[i] = '\0';

    if (c != EOF) unread_char(c);

    return OPERAND;
}

void consume_blanks(void)
{
    char c;
    while ((c = read_char()) == ' ' || c == '\t');
    if (c != ' ' && c != '\t') unread_char(c);
}