#include <stdio.h>

#define STACK_SIZE 1000

int stack[STACK_SIZE+3];
int line = 1;
int col = 1;

void push(int stack[], char el);
int pop(int stack[]);
int peek(int stack[]);

int is_quote(char c);
char opening_char_for(char c);
void print_error_message(char stack_head, char actual);

void print_stack() {
    int head = stack[2];

    printf("stack: ");

    for (int i = head; i >= 3; i--)
        printf("%c ", stack[i]);
}

// Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
// unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
// double, escape sequences, and comments. (This program is hard if you do it in full
// generality.)
int main(void)
{
    stack[0] = STACK_SIZE; // max stack size
    stack[1] = 0; // current stack size
    stack[2] = 3; // index of head

    char c;

    while (c = getchar()) {
        switch(c) {
            case '\n': {
                if (!is_quote(peek(stack))) break;
                print_error_message(peek(stack), c);
                return 1;
                break;
            }

            case '\'': {
                if (peek(stack) == c) pop(stack);
                else if (peek(stack) != '"') push(stack, c);
                break;
            }

            case '"': {
                if (peek(stack) == c) pop(stack);
                else if (peek(stack) != '\'') push(stack, c);
                break;
            }

            case '{':
            case '[':
            case '(': {
                if (is_quote(peek(stack))) break;
                push(stack, c);
                break;
            }

            case '}':
            case ']':
            case ')': {
                if (is_quote(peek(stack))) break;
                int last_char = pop(stack);
                if (last_char == opening_char_for(c)) break;
                print_error_message(last_char, c);
                return 1;
                break;
            }

            case EOF: {
                if (stack[1] == 0) break;
                print_error_message(pop(stack), EOF);
                return 1;
                break;
            }

            default:
                break;
        }

        if (c == '\n') {
            ++line;
            col = 1;
        } else
            ++col;
    }

    return 0;
}

void push(int stack[], char item)
{
    int max_size = stack[0];
    int size = stack[1];
    int head = stack[2];

    if (size == max_size) return;

    printf("Pushing char '%c'\n", item);

    ++stack[1];
    ++stack[2];

    int newHead = stack[2];

    stack[newHead] = item;
}

int peek(int stack[])
{
    int head = stack[2];
    return stack[head];
}

int pop(int stack[])
{
    int size = stack[1];
    int head = stack[2];

    if (size == 0) return '\0';

    int item = stack[head];
    
    printf("Popping char '%c'\n", item);

    --stack[1];
    --stack[2];

    return item;
}

int is_quote(char c)
{
    return c == '\'' || c == '"';
}

char opening_char_for(char c)
{
    if (c == '}') return '{';
    else if (c == ']') return '[';
    else if (c == ')') return '(';
}

void print_error_message(char opening_char, char actual)
{
    printf("Syntax error on [%d:%d]: expected closing char for '%c'. ", line, col, opening_char);
    
    if (actual == '\n')
        printf("Got '\\n' instead.\n");
    else if (actual == EOF)
        printf("Got end of file instead.\n");
    else
        printf("Got '%c' instead.\n", actual);
}