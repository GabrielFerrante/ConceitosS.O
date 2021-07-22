/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Algoritmo LRU e troca de páginas                                           #
#################################################################################
*/

#include <iostream>
#include <iterator>
#include "troca_pagina_lru.h"

using namespace std;

// Troca de páginas LRU
int TrocaPaginaLRU::run(map<int, Pagina &> paginas_presentes)
{
    cout << "[Troca de Página LRU executando...]" << endl;

    int numero_pagina = -1;
    int menor_contador = -1;

    for (auto it = paginas_presentes.cbegin(); it != paginas_presentes.cend(); it++)
    {
        auto pagina = it->second;

        if (menor_contador == -1 || pagina.ultima_referencia < menor_contador)
        {
            menor_contador = pagina.ultima_referencia;
            numero_pagina = it->first;
        }
    }

    return numero_pagina;
}