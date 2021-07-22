/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Swapping para o disco de primeiro processo encontrado que tenha o mínimo   #
#    de páginas suficientes sendo requisitadas.                                 #
#################################################################################
*/

#include <iostream>
#include "troca_processo_first_fit.h"

using namespace std;

void TrocaProcessoFirstFit::run(vector<Processo*> &tb_processos, vector<Pagina> &espaco_enderecamento, int n_vitimas) {
    
     cout << "[Troca de Processo First-Fit executando...]" << endl;

    for(auto p : tb_processos) {
        int paginas_alocadas = p->tb_paginas.size();

        if (paginas_alocadas >= n_vitimas) {
            // Processo tem páginas suficientes para atender o total de páginas vitimas. 
            swap_out(p, espaco_enderecamento);

            // Desalocar processo
            desalocar_processo(p);

            break;
        }
    }
}

// Salvar processo no disco se necessário (páginas modificadas)
void TrocaProcessoFirstFit::swap_out(Processo *proc, vector<Pagina> &espaco_enderecamento) {

        for (auto i = 0; i < proc->tb_paginas.size(); ++i) {

            int num_pg = proc->tb_paginas[i];

            Pagina &pg = espaco_enderecamento[num_pg];

            if (pg.modificada) {
                cout << "Salvando página modificada nº " << num_pg << " do processo " << proc->id << " no disco." << endl;
                //salvar_em_disco();
            }

            // Desalocar página
            pg.alocada = false;
            pg.referenciada = false;
            pg.modificada = false;
        }
}

void TrocaProcessoFirstFit::desalocar_processo(Processo *proc) {
    proc->em_disco = true;
    proc->trocar_estado("SUSPENSO");
}

void TrocaProcessoFirstFit::swap_in(Processo *proc) {
    proc->em_disco = false;
}
