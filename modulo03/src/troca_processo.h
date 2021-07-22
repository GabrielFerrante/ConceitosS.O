/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Superclasse para implementação de algoritos de swapping de processo        #
#    para o disco.                                                              #
#################################################################################
*/

#ifndef SWAPPER_H
#define SWAPPER_H

#include <vector>
#include "processo.h"
#include "memoria_virtual.h"

class TrocaProcesso
{
public:
    // Destrutor virtual para herança
    virtual ~TrocaProcesso(){};
    // Método run a ser implementado pelas classes de algoritmos de swapping de processos para o disco
    virtual void run(std::vector<Processo *> &tb_processos, std::vector<Pagina> &espaco_enderecamento, int n_vitimas) = 0;
    // Método de swap-in a ser implementado pelas classes classes de algoritmos de swapping de processos para o disco
    virtual void swap_in(Processo *proc) = 0;
};

#endif