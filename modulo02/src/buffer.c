/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Implementação de buffer de tamanho limitado e utilizando fila              #
#################################################################################
*/

#include "buffer.h"

// Criar Buffer de tamanho 'size' ou BUFFER_SIZE se 'size' 0 ou negativo
Buffer* criarBuffer(int size) {
    Buffer* b = (Buffer*)malloc(sizeof(Buffer));
    b->buf = createQueue();
    b->tamanho_atual = 0;
    b->tamanho_limite = size;
    return b;
}

// Quantidade de slots livres no buffer
int slotsLivres(Buffer* b) {
    return b->tamanho_limite - b->tamanho_atual;
}

// Quantidade de slots ocupados no buffer
int slotsOcupados(Buffer* b) {
    return b->tamanho_atual;
}

// Insere item no buffer, se não estiver cheio
// true - Valor inserido
// false - Buffer cheio
bool inserirNoBuffer(Buffer* b, item_type i) {
    
    if (b->tamanho_atual == b->tamanho_limite) {
        // Buffer cheio
        return false;
    }

    enQueue(b->buf,i);
    b->tamanho_atual++;
    return true;
}

bool retirarDoBuffer(Buffer* b, item_type* i) {

    if(b->tamanho_atual == 0) {
        //Buffer vazio.
        return false;
    }

    *i = b->buf->front->item;
    deQueue(b->buf);
    b->tamanho_atual--;

    return true;
}

// Estatisticas do buffer
void stats(Buffer* b) {
    printf("\nTamanho do Buffer: %d \n", b->tamanho_limite);
    printf("Slots disponíveis: %d \n", slotsLivres(b));
    printf("Slots ocupados: %d \n\n", slotsOcupados(b));
}