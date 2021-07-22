/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Superclasse para implementação de algoritmos de troca de página            #
#################################################################################
*/

#ifndef TROCA_PAGINA_H
#define TROCA_PAGINA_H

#include <string>
#include <map>
#include "memoria_virtual.h"

class TrocaPagina
{
public:
    // Destrutor virtual para herança
    virtual ~TrocaPagina(){};
    // Método run a ser implementado pelas classes de algoritmos de substituição de páginas
    virtual int run(std::map<int, Pagina&> paginas_presentes) = 0;
};

#endif