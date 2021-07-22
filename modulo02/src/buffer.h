/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Implementação de buffer de tamanho limitado e utilizando fila              #
#################################################################################
*/

#include <stdbool.h>
#include "fila.h"

// Estrutura do buffer utilizando fila e com controle do tamanho atual e do máximo permitido
typedef struct Buffer {
	Queue* buf;
    int tamanho_atual;
    int tamanho_limite;
} Buffer;

// Criar Buffer de tamanho 'size'
Buffer* criarBuffer(int size);

// Quantidade de slots livres no buffer
int slotsLivres(Buffer* b);

// Quantidade de slots ocupados no buffer
int slotsOcupados(Buffer* b);

// Insere item no buffer, se não estiver cheio
// true - Valor inserido
// false - Buffer cheio
bool inserirNoBuffer(Buffer* b, item_type i);

// Retira e retorna o item do buffer a ser consumido se o buffer não estiver vazio
// true se existe item a se retornar e item item_type* i
// false se o buffer estiver vazio.
bool retirarDoBuffer(Buffer* b, item_type* i);

// Estatisticas do buffer
void stats(Buffer* b);