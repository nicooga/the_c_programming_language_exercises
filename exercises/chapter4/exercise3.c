#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lib/stack.h"
#include "lib/input.h"

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

#define PUSH(value) stack_push_double(stack, value)
#define POP() stack_pop_double(stack)

int get_operand(char s[]);

// Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
// the modulus (%) operator and provisions for negative numbers. 
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    double *stack = stack_create(300);

    while ((type = get_operand(s)) != EOF)
        switch (type) {
            case NUMBER:
                PUSH(atof(s));
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
                if (op2 != 0.0) PUSH(POP() / op2);
                else printf("error: zero divisor\n");
                break;
            case '%':
                op2 = POP();
                if (op2 != 0.0) PUSH((int) POP() % (int) op2);
                else printf("error: zero divisor\n");
                break;
            case '\n':
                printf("%.8g\n", POP());
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
