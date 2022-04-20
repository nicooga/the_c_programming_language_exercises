#include <stdio.h>
#include "string/string.c"

int test_my_strncpy(void);
int test_my_strncat(void);
int test_my_strncmp(void);

void my_strncpy(char *dst, char *src, size_t n);
void my_strncat(char *dst, char *src, size_t n);
int my_strncmp(char *s1, char *s2, size_t n);

// Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which
// operate on at most the first n characters of their argument strings. For example,
// copies at most n characters of t to s. Full descriptions are in Appendix B.
int main(void)
{
    if (!test_my_strncpy()) return 1;
    if (!test_my_strncat()) return 1;
    if (!test_my_strncmp()) return 1;
    return 0;
}

int test_my_strncpy(void)
{
    char s1[] = "asdfqwer";
    char s2[] = "    ";

    my_strncpy(s2, s1, 4);
    if (!string_equals(s2, "asdf")) return 0;

    char s3[5];

    my_strncpy(s3, s1, 10);
    if (!string_equals(s3, "asdfqwer")) return 0;

    return 1;
}

int test_my_strncat(void)
{
    char s1[100] = "asdf";
    char s2[] = "qwer";

    my_strncat(s1, s2, 2);
    if (!string_equals(s1, "asdfqw")) return 0;

    char s3[100] = "uiop";

    my_strncat(s3, s2, 10);
    if (!string_equals(s3, "uiopqwer")) return 0;

    return 1;
}

int test_my_strncmp()
{
    if (!my_strncmp("asdfqwer", "asdfuiop", 4)) return 0;
    if (my_strncmp("asdfqwer", "asdfuiop", 8)) return 0;
    if (!my_strncmp("asdf", "asdf", 8)) return 0;
    if (my_strncmp("asdf", "qwer", 8)) return 0;
    return 1;
}

void my_strncpy(char *dst, char *src, size_t n)
{
    while (n-- && (*dst++ = *src++));
}

void my_strncat(char *dst, char *src, size_t n)
{
    while (*dst) dst++;
    while (n-- && *src) *dst++ = *src++;
    *dst = '\0';
}

int my_strncmp(char *s1, char *s2, size_t n)
{
    while (n-- && (*s1 != '\0' || *s2 != '\0'))
        if (*s1++ != *s2++)
            return 0;

    return 1;
}