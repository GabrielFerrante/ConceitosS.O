#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    printf("Digite um número inteiro: ");
    //TODO:aguimarjr scanf is not a system call.
    scanf("%d", &numero);
    printf("Número %d", numero);
    return EXIT_SUCCESS;
}