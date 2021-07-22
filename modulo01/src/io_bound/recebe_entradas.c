#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int main () {
    printf("Digite o seu primeiro nome: ");
    char nome[100];
    fgets(nome, MAX_SIZE, stdin);

    printf("Digite sua idade: ");
    int idade;
    scanf ("%d", &idade);

    printf("Qual a sua música favorita? ");
    char musica[100];
    fgets(musica, MAX_SIZE, stdin);

    printf("Qual a sua comida predileta? ");
    char comida[100];
    fgets(comida, MAX_SIZE, stdin);
    printf("_________________________");
    // alerta em audio
    printf("\a");

    printf("\r");

    printf("Nome: %s\nIdade: %d\nMusica: %s\nComida: %s\n", nome, idade, musica, comida);
    return 0;

}
