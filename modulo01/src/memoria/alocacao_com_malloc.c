#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Alocação dinâmica de memória
    int *ptr = (int *)malloc(sizeof(int));

    if (ptr == NULL)
    {
        printf("\nMemória não alocada.\n");
        return EXIT_FAILURE;
    }

    *ptr = 10;

    printf("%d\n", *ptr);

    free(ptr);

    return EXIT_SUCCESS;
}