#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "lib/stack.h"
#include "lib/input.h"

#define MAXOP 100
#define OPERAND '0'

int get_operand_or_operator(char s[]);
void consume_blanks(void);

// Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in
// Appendix B, Section 4.
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    double temp;

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
            case '\n':
                printf("%.8g\n", stack_pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
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