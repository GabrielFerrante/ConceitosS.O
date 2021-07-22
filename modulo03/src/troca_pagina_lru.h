/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Algoritmo LRU e troca de páginas                                           #
#################################################################################
*/

#ifndef SUBSTITUICAO_LRU_H
#define SUBSTITUICAO_LRU_H

#include "troca_pagina.h"

class TrocaPaginaLRU : public TrocaPagina
{
public:
    int run(std::map<int, Pagina&> paginas_presentes) override;
};

#endif