#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lib/stack.h"
#include "lib/input.h"

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int get_operand(char s[]);

// Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
// the modulus (%) operator and provisions for negative numbers. 
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = get_operand(s)) != EOF)
        switch (type) {
            case NUMBER:
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
            case '\n':
                printf("%.8g\n", stack_pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }

    return 0;
}

int get_operand(char s[])
{
    int i, c;

    while ((s[0] = c = read_char()) == ' ' || c == '\t');

    s[1] = '\0';

    if (!isdigit(c) && c != '.') return c;

    i = 0;

    if (isdigit(c))
        while (isdigit(s[++i] = c = read_char()));

    if (c == '.')
        while (isdigit(s[++i] = c = read_char()));

    s[i] = '\0';

    if (c != EOF)
        unread_char(c);

    return NUMBER;
}
