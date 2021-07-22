/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Simulador da memória física                                                #
#################################################################################
*/

#include <iostream>
#include "memoria_fisica.h"

using namespace std;

// Tamanho do pageframe em kbytes
Quadro::Quadro(int tam)
{
    this->tamanho = tam * 1024;
}

MemoriaFisica::MemoriaFisica(int tam_mem, int tam_pagina)
{
    tamanho = tam_mem * 1024;
    tamanho_quadro = tam_pagina * 1024;
    num_quadros = tamanho / tamanho_quadro;
    espaco_enderecamento.reserve(num_quadros);
}

void MemoriaFisica::ler_endereco(int addr) {
    cout << "Leitura de memória física realizada. Endereço: " << addr << endl;
    
}

void MemoriaFisica::escrita_endereco(int addr) {
    cout << "Escrita na memória física realizada. Endereço: " << addr << endl;
    
}