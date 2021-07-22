/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Parser para argumentos de entrada do programa Simulador                    #
#################################################################################
*/

#ifndef OPCOES_H
#define OPCOES_H

#include <string>
#include "troca_pagina_aleatoria.h"
#include "troca_pagina_lru.h"
#include "troca_pagina_relogio.h"
#include "troca_processo_first_fit.h"
#include "troca_processo_best_fit.h"
#include "cxxopts.hpp"

struct OpcoesSimulador
{
    // Nome do arquivo de instruções
    std::string finput;
    // Tamanhos da(o): página, frame, memória física, memória principal
    int pgsize, frsize, mfsize, mvsize, iprsize;
    // Algoritmo de substituição de páginas escolhido
    TrocaPagina *substituicao_pagina;
    // Algoritmo de swapping de processo para o disco escolhido
    TrocaProcesso *swapper;
    // Habilitação de modo debug para mostrar valores das estruturas de dados internas do simulador
    bool debug;

    // Método responsável por tratar as opções informadas na linha de comando e preencher a struct OpcoesSimulador
    static OpcoesSimulador *tratarOpcoes(int argc, char **argv);
};

// Realizar o parser das opções informadas na linha de comando pelo usuário

#endif