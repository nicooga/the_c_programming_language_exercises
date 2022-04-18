#include <stdio.h>

int strend(char *s, char *t);

// Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
// end of the string s, and zero otherwise.
int main(void)
{
    if (strend("asdfdf", "df") != 1) return 1;
    if (strend("asdfdf", "fd") != 0) return 1;
    if (strend("a", "asdf") != 0) return 1;

    return 0;
}

int strend(char *s, char *t)
{
    char *initial_s = s;
    char *initial_t = t;

    while (*(s+1) != '\0') s++;
    while (*(t+1) != '\0') t++;

    if ((t-initial_t) > (s-initial_s))
        return 0;

    while (t >= initial_t)
        if (*s-- != *t--)
            return 0;

    return 1;
}
