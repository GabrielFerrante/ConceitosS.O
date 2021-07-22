/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Produtor/Consumidor com o uso de semáforos                                 #
#################################################################################
*/

#define _GNU_SOURCE
#define _MULTI_THREADED
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#include "buffer.h"
#include "opcoes.h"
#include "msleep.h"

/* Prototipos */
void *producer(void *arg);
void *consumer(void *arg);
void insert_item(item_type item);
item_type remove_item();

/* Semaforos */
sem_t mutex, empty, full;

/* Buffer - Implementação com fila */
Buffer *buffer;

/* Argumentos fornecidos na linha de comando */
struct arguments args;

int main(int argc, char **argv)
{
	// Tratando argumentos da linha de comando
	args = tratarOpcoes(argc, argv);

	int TAM = args.bsize;	 // Tamanho do Buffer
	int N_PROD = args.nprod; // Quantidade de produtores
	int N_CONS = args.ncons; // Quantidade de consumidores

	// Criando buffer limitado
	buffer = criarBuffer(TAM);

	pthread_t prods[N_PROD], cons[N_CONS];
	int i;
	sem_init(&mutex, 0, 1);
	sem_init(&empty, 0, TAM);
	sem_init(&full, 0, 0);

	/* Cria as Threads de produtores */
	for (i = 0; i < N_PROD; i++)
	{
		pthread_create(&prods[i], NULL, producer, NULL);
	}

	/* Cria as Threads de consumidores */
	for (i = 0; i < N_CONS; i++)
	{
		pthread_create(&cons[i], NULL, consumer, NULL);
	}

	// Tempo total de espera pelas threads - Após esse tempo em segundos, prosseguir e terminar o programa.
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);

	// Default: 30 segundos
	ts.tv_sec += args.time;

	/* Faz o join em todas as threads */
	for (i = 0; i < N_PROD; i++)
	{
		pthread_timedjoin_np(prods[i], NULL, &ts);
	}

	for (i = 0; i < N_CONS; i++)
	{
		pthread_timedjoin_np(cons[i], NULL, &ts);
	}
	return 0;
}

// Gerador sequencial de items
item_type _gerarValorItem() {
    static int x = 0;
    x++;
    return x;
}

/** Produtor */
void *producer(void *arg)
{
	item_type item;

	do
	{
		sem_wait(&empty);
		sem_wait(&mutex);
		item = _gerarValorItem();
		insert_item(item);
		sem_post(&mutex);
		sem_post(&full);
	} while (1);
}

/** Consumidor */
void *consumer(void *arg)
{
	do
	{
		sem_wait(&full);
		sem_wait(&mutex);
		remove_item();
		sem_post(&mutex);
		sem_post(&empty);
	} while (1);
}

/* Insere no buffer */
void insert_item(item_type item)
{
	bool inseriu = inserirNoBuffer(buffer, item);

	if (!inseriu)
	{
		printf("[Produtor ID: %lu] Buffer cheio - Não é possível produzir novo item no momento.\n", pthread_self());
	}
	else {
		printf("[Produtor ID: %lu] Item produzido: %d\n", pthread_self(), item); /* produz item */
	}

	stats(buffer);

	if (args.sprod != 0)
	{
		msleep(args.sprod);
	}
}

/* Remove do buffer */
item_type remove_item()
{
	item_type item;

	bool retirou = retirarDoBuffer(buffer, &item);

	if (!retirou)
	{
		printf("[Consumidor ID: %lu] Buffer vazio - Não há item para consumir no momento.\n", pthread_self());
	}
	else
	{
		printf("[Consumidor ID: %lu] Item consumido: %d\n", pthread_self(), item); /* consome item */
	}

	stats(buffer);

	if (args.scons != 0)
	{
		msleep(args.scons);
	}

	return item;
}
