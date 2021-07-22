/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Simulador da memória física                                                #
#################################################################################
*/

#ifndef MEMORIA_FISICA_H
#define MEMORIA_FISICA_H

#include <vector>

class Quadro
{

public:
	// Especificar o tamanho do quadro em kbytes
	Quadro(int tam);

private:
	// Tamanho do quadro em bytes
	int tamanho;
};

class MemoriaFisica
{

public:
	// Inicializar memória física especificando o tamanho da memória em kbytes e a quantidade de quadros
	MemoriaFisica(int tam_mem, int tam_quadro);
	// Tamanho do quadro em kbytes
	int tamanho_quadro;
	// Quantidade de quadros
	int num_quadros;
	// Ler posição de memória indicada por addr
	void ler_endereco(int addr);
	// Escrever posição de memória indicada por addr
	void escrita_endereco(int addr);

private:
	// Tamanho da memória física em kbytes
	int tamanho;
	// Espaço de endereçamento físico
	std::vector<Quadro> espaco_enderecamento;
};

#endif