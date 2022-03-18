#include <stdio.h>

// Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
int main(void)
{
  while (1)
    printf("%d", getchar() != EOF);
}
