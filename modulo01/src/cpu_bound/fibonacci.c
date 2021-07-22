#include <stdlib.h>
#include <stdio.h>

int main()
{
    int i, n = 1000000, t1 = 0, t2 = 1;
    int nextTerm = t1 + t2;
    int *v;
    //Aloca memória para um vetor de tamanho N
    v = malloc(n * sizeof(int));
    printf("Fibonacci Series: %d, %d, ", t1, t2);

    for (i = 1; i <= n; ++i) {
        printf("%d, ", nextTerm);
        v[i] = nextTerm;
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }

    return 0;


}
