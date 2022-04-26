#include "./string.h"

int main(void)
{
    if (string_equals("asdf", "asdf") != 1) return 1;
    if (string_equals("asdf", "asdfq") != 0) return 1;
    if (string_equals("qasdf", "asdf") != 0) return 1;
    if (string_equals("asd", "asf") != 0) return 1;

    char s[9] = "asdfqwer";

    string_reverse(s);
    if (string_equals(s, "rewqfdsa") != 1) return 1;

    string_reverse_up_to(s, 3);
    if (string_equals(s, "qwerfdsa") != 1) return 1;

    return 0;
}