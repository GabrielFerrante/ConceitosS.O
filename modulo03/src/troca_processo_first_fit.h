/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Swapping para o disco de primeiro processo encontrado que tenha o mínimo   #
#    de páginas suficientes sendo requisitadas.                                 #
#################################################################################
*/

#ifndef SWAPPER_SIMPLES_H
#define SWAPPER_SIMPLES_H

#include "troca_processo.h"

// Retirar o primeiro processo com o número de páginas vítimas necessárias que encontrar
// Subclasse de TrocaProcesso
class TrocaProcessoFirstFit : public TrocaProcesso
{
public:
    // Método sobrescrito
    void run(std::vector<Processo *> &tb_processos, std::vector<Pagina> &espaco_enderecamento, int n_vitimas) override;

private:
    void swap_out(Processo *proc, std::vector<Pagina> &espaco_enderecamento);
    void swap_in(Processo *proc);
    // Desalocar páginas associadas ao processo vítima
    void desalocar_processo(Processo *proc);
};

#endif