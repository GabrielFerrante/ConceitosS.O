#include <stdlib.h>
#include <stdio.h>

int main()
{
     int *v;
     //Aloca memória para um vetor de tamanho 1000
     v = malloc(1000 * sizeof(int));
     printf("\nVETOR COM 1000\n");
     for (int i = 0; i < 990; i++)
     {
          v[i] = i;
          printf("%d | ", i);
     }
     //redimensionar o tamanho alocado para 2000
     printf("\nVETOR COM MAIS 1000\n");
     //Recebe com parametros a referência para o vetor e o tamanho desejado
     v = realloc(v, 2000 * sizeof(int));
     for (int i = 990; i < 2000; i++)
     {
          v[i] = i;
          printf("%d | ", i);
     }
     printf("\n VETOR TOTAL\n");
     for (int i = 0; i < 2000; i++)
     {
          printf("%d | ", v[i]);
     }

     return EXIT_SUCCESS;
}
