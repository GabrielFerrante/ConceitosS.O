/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Programa para testar implementação do buffer com lista encadeada           #
#################################################################################
*/

#include "buffer.h"

int main()
{
    int a, b, c, d;
    
    Buffer* bf = criarBuffer(3);

    printf("\n### Inserindo itens produzidos no buffer ###\n");
    inserirNoBuffer(bf, 1);
    stats(bf);
    inserirNoBuffer(bf, 2);
    stats(bf);
    inserirNoBuffer(bf, 3);
    stats(bf);

    bool inseriu = inserirNoBuffer(bf, 4);
    if (!inseriu) {
        printf("Buffer cheio - Não foi possível inserir.\n");
    }
    stats(bf);

    printf("\n### Retirando itens do buffer para consumo ###\n\n");
    
    retirarDoBuffer(bf, &a);
    printf("Item %d\n", a);
    stats(bf);
    retirarDoBuffer(bf, &b);
    printf("Item %d\n", b);
    stats(bf);
    retirarDoBuffer(bf, &c);
    printf("Item %d\n", c);
    stats(bf);

    bool removeu = retirarDoBuffer(bf, &d);

    if (!removeu) {
        printf("Buffer vazio - Não há o que retirar.\n");
    }

    stats(bf);
    
    return EXIT_SUCCESS;
}

