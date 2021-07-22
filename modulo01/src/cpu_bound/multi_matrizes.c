#include <stdio.h>
#include <stdlib.h>

int main()
{

	//Definição de variaveis
	int i, j, x, aux = 0;
	const int L = 600;
	const int C = 600;

	int matrizA[L][C], matrizB[L][C], matrizC[L][C];

	if (L == C)
	{

		for (i = 0; i < L; i++)
		{
			for (j = 0; j < C; j++)
			{

				matrizA[i][j] = i;
			}
		}

		for (i = 0; i < L; i++)
		{
			for (j = 0; j < C; j++)
			{
				matrizB[i][j] = i + 1;
			}
		}

		// Imprime as matrizes definidas
		printf("---------------------------- 1 - Matriz Gerada A ---------------------------------\n\n");

		for (i = 0; i < L; i++)
		{
			for (j = 0; j < C; j++)
			{
				printf("%d |", matrizA[i][j]);
			}
			printf("\n\n");
		}

		printf("---------------------------- 2 - Matriz Gerada B ---------------------------------\n\n");
		for (i = 0; i < L; i++)
		{
			for (j = 0; j < C; j++)
			{
				printf("%d |", matrizB[i][j]);
			}
			printf("\n\n");
		}

		printf("---------------------------- 3 - Matriz Gerada Resultante ---------------------------------\n\n");
		//Processamento e saida em tela  =  PRODUTO DAS MATRIZES
		for (i = 0; i < L; i++)
		{
			for (j = 0; j < C; j++)
			{
				matrizC[i][j] = 0;
				for (x = 0; x < C; x++)
				{
					aux += matrizA[i][x] * matrizB[x][j];
				}
				matrizC[i][j] = aux;
				aux = 0;
			}
		}
		for (i = 0; i < L; i++)
		{
			for (j = 0; j < C; j++)
			{
				printf("%d |", matrizC[i][j]);
			}
			printf("\n\n");
		}
		printf("\n\n");
	}
	else
	{
		printf("\n\n Nao ha com multiplicar as matrizes dadas ");
	}

	return EXIT_SUCCESS;
}