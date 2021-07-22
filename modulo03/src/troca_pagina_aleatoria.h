/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Troca de página aleatória                                                  #
#################################################################################
*/

#ifndef SUBSTITUICAO_SIMPLES_H
#define SUBSTITUICAO_SIMPLES_H

#include "troca_pagina.h"

// Algoritmo de substituição de páginas de forma aleatória
// Subclasse de TrocaPagina
class TrocaPaginaAleatoria : public TrocaPagina
{
public:
    // Método sobrescrito
    int run(std::map<int, Pagina&> paginas_presentes) override;
};

#endif