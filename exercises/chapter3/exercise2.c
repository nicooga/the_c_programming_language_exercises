#include <stdio.h>

#define MAX_LENGTH 1000

void read_string(char s[], int lim);
void escape(char s[], char t[]);
void unscape(char s[], char t[]);

// Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
// into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write 
// a function for the other direction as well, converting escape sequences into the real characters. 
int main(void)
{
    char s[MAX_LENGTH];
    char t[MAX_LENGTH];

    read_string(s, MAX_LENGTH);

    // escape(s, t);
    // unscape(s, t);

    printf("%s", t);

    return 0;
}

void read_string(char s[], int lim)
{
    int i = 0;
    char c;
    while (--lim > 0 && (c = getchar()) != EOF) s[i++] = c;
    s[i] = '\0';
};

void escape(char s[], char t[])
{
    int i = 0;

    while (s[i] != '\0') {
        char c = s[i];

        switch(c) {
            case '\n':
                t[i++] = '\\';
                t[i++] = 'n';
                break;

            case '\t':
                t[i++] = '\\';
                t[i++] = 't';
                break;

            default:
                t[i++] = c;
                break;
        }
    }

    t[i] = '\0';
}

void unscape(char s[], char t[])
{
    int i = 0;

    while (s[i] != '\0') {
        char c = s[i];

        switch(c) {
            case '\\':
                if (s[i+1] == 'n') {
                    t[i++] = '\n';
                    i++;
                } else if (s[i+1] == 't') {
                    t[i++] = '\t';
                    i++;
                } else
                    t[i++] = c;

                break;

            default:
                t[i++] = c;
                break;
        }
    }

    t[i] = '\0';
}
