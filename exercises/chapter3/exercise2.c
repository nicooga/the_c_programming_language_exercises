#include <stdio.h>

#define MAX_LENGTH 1000

void skip_whitespace(void);
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
    char modeFlag = getchar();
    int mode = modeFlag == 'e' ? 1 : 0;

    if (modeFlag != 'e' && modeFlag != 'u') {
        printf("First char should either be 'e' or 'u' to indicate escape or unscape mode respectively.\n");
        return 1;
    }

    read_string(s, MAX_LENGTH);

    if (mode == 1) escape(s, t);
    else unscape(s, t);

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
    int j = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;

            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;

            default:
                t[j++] = s[i];
                break;
        }
    }

    t[j] = '\0';
}

void unscape(char s[], char t[])
{
    int j = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
            case '\\':
                if (s[i+1] == 'n') {
                    t[j++] = '\n';
                    i++;
                }
                else if (s[i+1] == 't') {
                    t[j++] = '\t';
                    i++;
                }
                else t[j++] = s[i];
                break;
            default:
                t[j++] = s[i];
                break;
        }
    }

    t[j] = '\0';
}
