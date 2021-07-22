/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Algoritmo do Relógio de troca de páginas                                   #
#################################################################################
*/

#include <iostream>
#include <iterator>
#include "troca_pagina_relogio.h"

using namespace std;

// Troca de páginas Relógio
int TrocaPaginaRelogio::run(map<int, Pagina &> paginas_presentes)
{
    cout << "[Troca de Página Relógio executando...]" << endl;

    int pg_vitima = -1;

    do
    {
        auto pg_it = paginas_presentes.find(this->ponteiro_relogio);
        auto &pg_apontada = pg_it->second;

        // Se bit R = 0 - selecionar como página vítima
        if (!pg_apontada.referenciada)
        {
            pg_vitima = this->ponteiro_relogio;
            avancar_ponteiro(paginas_presentes.size());
            break;
        }
        else
        {
            // bit R = 1 - limpar bit R e avançar ponteiro
            pg_apontada.referenciada = false;
            avancar_ponteiro(paginas_presentes.size());
        }
    } while (true);

    return pg_vitima;
}

// Avança o ponteiro do relógio. Caso já esteja no final, volta para o primeiro elemento.
void TrocaPaginaRelogio::avancar_ponteiro(int qtde_de_paginas)
{
    this->ponteiro_relogio++;
    this->ponteiro_relogio = this->ponteiro_relogio % qtde_de_paginas;
}

int TrocaPaginaRelogio::recuperar_ponteiro_relogio() {
    return this->ponteiro_relogio;
}

void TrocaPaginaRelogio::ajustar_ponteiro_relogio(int nova_posicao) {
    this->ponteiro_relogio = nova_posicao;
}
