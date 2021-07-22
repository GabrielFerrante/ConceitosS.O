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

#include <iostream>
#include <map>
#include "troca_processo_best_fit.h"

using namespace std;

void TrocaProcessoBestFit::run(vector<Processo *> &tb_processos, vector<Pagina> &espaco_enderecamento, int n_vitimas)
{

    cout << "[Troca de Processo Best-Fit executando...]" << endl;

    int menos_paginas_alocadas = -1;
    Processo *processo_menos_paginas = nullptr;

    // Selecionando processo para enviar para o disco
    for (auto p : tb_processos)
    {
        int paginas_alocadas = p->tb_paginas.size();

        if (paginas_alocadas >= n_vitimas)
        {
            // Processo tem páginas suficientes para atender o total de páginas vítimas.
            // Salvar o que ocupa menos espaço, desde que atenda à
            // quantidade mínima de páginas vítimas sendo requisitadas.
            if (menos_paginas_alocadas == -1 || paginas_alocadas < menos_paginas_alocadas)
            {
                menos_paginas_alocadas = paginas_alocadas;
                processo_menos_paginas = p;
            }
        }
    }

    swap_out(processo_menos_paginas, espaco_enderecamento);

    // Desalocar processo
    desalocar_processo(processo_menos_paginas);
}

// Salvar processo no disco se necessário (páginas modificadas)
void TrocaProcessoBestFit::swap_out(Processo *proc, vector<Pagina> &espaco_enderecamento)
{

    for (auto i = 0; i < proc->tb_paginas.size(); ++i)
    {

        int num_pg = proc->tb_paginas[i];

        Pagina &pg = espaco_enderecamento[num_pg];

        if (pg.modificada)
        {
            cout << "Salvando página modificada nº " << num_pg << " do processo " << proc->id << " no disco." << endl;
            //salvar_em_disco();
        }

        // Desalocar página
        pg.alocada = false;
        pg.referenciada = false;
        pg.modificada = false;
    }
}

void TrocaProcessoBestFit::desalocar_processo(Processo *proc)
{
    proc->em_disco = true;
    proc->trocar_estado("SUSPENSO");
}

void TrocaProcessoBestFit::swap_in(Processo *proc)
{
    proc->em_disco = false;
}
