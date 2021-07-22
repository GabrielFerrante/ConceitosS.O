/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Simulador                                                                  #
#################################################################################
*/

#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <vector>
#include "instrucao.h"
#include "cpu.h"
#include "mmu.h"
#include "memoria_virtual.h"
#include "memoria_fisica.h"
#include "troca_processo.h"
#include "troca_pagina.h"
#include "opcoes_simulador.h"
#include "agregador_info.h"

class Simulador
{

public:
    // Construtor padrão
    Simulador();
    // Inicializa o simulador com as opções de linha de comando e lista de instruções a serem executadas.
    Simulador(OpcoesSimulador *opcoes, std::vector<Instrucao> cmds);
    // Destrutor
    ~Simulador();
    // Executar todas as instruções
    void executar();
    // Executar a instrução atual apontada pelo contador de instruções
    void executar_1_passo();
    // Encerrar a simulação
    void finalizar();

private:
    // Opções do simulador
    OpcoesSimulador *opcoes;
    // Lista de instruções
    std::vector<Instrucao> cmds;
    // Ponteiro para a CPU
    CPU* cpu;
    // Ponteiro para a MMU
    MMU* mmu;
    // Ponteiro para a memória física
    MemoriaFisica* mem_fisica;
    // Ponteiro para a memória virtual
    MemoriaVirtual* mem_virtual;
    // Consolidador de informações estatístiscas das estruturas de dados internas
    AgregadorInfo* info;
    // Contador de instruções
    int contador_instrucao = 0;
    // Flag de debug
    bool debug = false;
};

#endif