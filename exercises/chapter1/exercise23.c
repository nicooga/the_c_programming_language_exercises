#include <stdio.h>

#define OUT 0
#define POTENTIALLY_WITHIN_COMMENT 1
#define IN_SINGLE_LINE_COMMENT 2
#define IN_BLOCK_COMMENT 3

int state_reducer(int state, char curChar, char prevChar, char prevPrevChar);
void perform(int state, int prevState, char curChar);

/* Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C comments don't nest.
 */
int main(void)
{
    char prevPrevChar, prevChar, curChar;
    int prevState;
    int state = POTENTIALLY_WITHIN_COMMENT;

    while ((curChar = getchar()) != EOF) {
        state = state_reducer(state, curChar, prevChar, prevPrevChar);
        perform(state, prevState, curChar);
        prevState = state;
        prevPrevChar = prevChar;
        prevChar = curChar;
    }

    return 0;
}

int state_reducer(int state, char curChar, char prevChar, char prevPrevChar)
{
    switch(state) {
        case OUT:
            if (curChar == '/') return POTENTIALLY_WITHIN_COMMENT;
            break;

        case POTENTIALLY_WITHIN_COMMENT:
            if (curChar == '/') return IN_SINGLE_LINE_COMMENT;
            else if (curChar == '*') return IN_BLOCK_COMMENT;
            else return OUT;
            break;

        case IN_SINGLE_LINE_COMMENT:
            if (curChar == '\n') return OUT;
            break;

        case IN_BLOCK_COMMENT:
            if (prevPrevChar == '*' && prevChar == '/') return OUT;
            break;
    }

    return state;
} 

void perform(int state, int prevState, char curChar)
{
    switch(state) {
        case OUT:
            if (prevState == POTENTIALLY_WITHIN_COMMENT) putchar('/');
            putchar(curChar);
            break;

        case POTENTIALLY_WITHIN_COMMENT:
        case IN_SINGLE_LINE_COMMENT:
        case IN_BLOCK_COMMENT:
            break;
    }
}
