/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Implementação da estrutura de dados de fila com lista encadeada            #
#    Adaptação da implementação do site https://www.geeksforgeeks.org/          #
#################################################################################
*/

#include <stdio.h>
#include <stdlib.h>

typedef int item_type;

// Lista encadeada para guardar os itens da fila
typedef struct QNode {
	item_type item;
	struct QNode* next;
} QNode;

// front - aponta para a início da fila, próximo item que será consumido
// rear - aponta para o final da fila, onde um novo item produzido será inserido
typedef struct Queue {
	QNode *front, *rear;
} Queue;

// Criar um novo item com o valor k informado
QNode* newNode(item_type k);

// Cria uma fila vazia
Queue* createQueue();

// Empilha k na fila q
void enQueue(Queue* q, item_type k);

// Desempilha item da frente da fila
void deQueue(Queue* q);