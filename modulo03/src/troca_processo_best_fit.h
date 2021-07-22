/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Swapping para o disco do processo encontrado com menos memória alocada     #
#    dentre aqueles que ocupam pelo menos o número de páginas vítimas           #
#    sendo requisitadas.                                                        # 
#    Diferentemente do first fit que sempre pega o primeiro que encontrar.      #
#################################################################################
*/

#ifndef SWAPPER_BEST_FIT_H
#define SWAPPER_BEST_FIT_H

#include "troca_processo.h"

// Retirar o processo que ocupe menos espaço e que atenda o número de páginas vítimas necessárias
// Subclasse de TrocaProcesso
class TrocaProcessoBestFit : public TrocaProcesso
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