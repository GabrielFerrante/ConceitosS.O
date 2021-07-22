/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Implementação da estrutura de dados de fila com lista encadeada            #
#    Adaptação da implementação do site https://www.geeksforgeeks.org/          #
#################################################################################
*/

#include "fila.h"

// Criar um novo item com o valor k informado
QNode* newNode(item_type k)
{
	QNode* temp = (QNode*)malloc(sizeof(QNode));
	temp->item = k;
	temp->next = NULL;
	return temp;
}

// Cria uma fila vazia
Queue* createQueue()
{
	Queue* q = (struct Queue*)malloc(sizeof(Queue));
	q->front = q->rear = NULL;
	return q;
}

// Empilha k na fila q
void enQueue(Queue* q, int k)
{
	// Novo item
	QNode* temp = newNode(k);

	// Se a fila estiver vazia, front e rear são os mesmos.
	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}

	// Adiciona o novo nó no final da fila e faz 'rear' apontar para esse novo item
	q->rear->next = temp;
	q->rear = temp;
}

// Desempilha item da frente da fila
void deQueue(Queue* q)
{
	// Se a fila está vazia, retorne.
	if (q->front == NULL)
		return;

	// Guarda o valor de 'front' que será consumido e move o ponteiro 'front' pra frente
	QNode* temp = q->front;

	q->front = q->front->next;

	// Se 'front' é nulo, então faça rear = front.
	if (q->front == NULL)
		q->rear = NULL;

	free(temp);
}
