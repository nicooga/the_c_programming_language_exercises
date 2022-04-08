#include "./string.c"

int main(void)
{
    if (string_equals("asdf", "asdf") != 1) return 1;
    if (string_equals("asdf", "asdfq") != 0) return 1;
    if (string_equals("qasdf", "asdf") != 0) return 1;
    if (string_equals("asd", "asf") != 0) return 1;

    return 0;
}