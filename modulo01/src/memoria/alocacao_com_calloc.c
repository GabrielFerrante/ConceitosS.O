#include <stdio.h>
#include <stdlib.h>

int main () {
   int n = 10;
   int *array = (int*)calloc(n, sizeof(int));

   free(array);
   
   return EXIT_SUCCESS;
}
