#include <stdio.h>

// Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
int main(void)
{
    char c;

    do {
        printf("%d\n", (c = getchar()) != EOF);
    } while (c != EOF);

    return 0;
}
