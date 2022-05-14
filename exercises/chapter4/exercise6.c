#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "lib/stack.h"
#include "lib/input.h"

#define MAXOP 100
#define OPERAND '0'
#define PUSH(value) stack_push_double(stack, value)
#define POP() stack_pop_double(stack)

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
    void *stack = stack_create(8);

    for (int i = 0; i < 26; i++) variables[i] = 0;

    while ((type = get_operand_or_operator(s)) != EOF)
        switch (type) {
            case OPERAND:
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
            default: {
                if (type >= 'A' && type <= 'Z') {
                    var_index = type - 'A';
                    PUSH(variables[var_index]);
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
