/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Algoritmo do Relógio de troca de páginas                                   #
#################################################################################
*/

#ifndef SUBSTITUICAO_CLOCK_H
#define SUBSTITUICAO_CLOCK_H

#include "troca_pagina.h"

// Algoritmo do Relógio para substituição de páginas
// Subclasse de TrocaPagina
class TrocaPaginaRelogio : public TrocaPagina
{
public:
    // Método sobrescrito
    int run(std::map<int, Pagina&> paginas_presentes) override;
    // Recuperar o número da página para qual o ponteiro do relógio está apontando
    int recuperar_ponteiro_relogio();
    // Ajustar o ponteiro do relógio para a próxima posição
    void ajustar_ponteiro_relogio(int nova_posicao);

private:
    // Ponteiro do relógio
    int ponteiro_relogio = 0;
    // Avançar o ponteiro do relógio. Dependente da quantidade de páginas que existem.
    void avancar_ponteiro(int qtde_de_paginas);
};

#endif