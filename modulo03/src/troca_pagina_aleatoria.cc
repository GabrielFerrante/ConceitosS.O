/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Troca de página aleatória                                                  #
#################################################################################
*/

#include <iostream>
#include <iterator>
#include "troca_pagina_aleatoria.h"

using namespace std;

// Escolhe uma página presente aleatoriamente
int TrocaPaginaAleatoria::run(map<int, Pagina&> paginas_presentes) {

    cout << "[Troca de Página Aleatória executando...]" << endl;
    
    auto it = paginas_presentes.cbegin();
    int random = rand() % paginas_presentes.size();
    advance(it, random);
 
    return it->first;    
}