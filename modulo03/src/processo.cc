/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Representação do processo                                                  #
#################################################################################
*/

#include "processo.h"

using namespace std;

Processo::Processo(string id, string estado, int alloc, int n_min_paginas) : id{id}, estado{estado}, alocacao_minima{alloc}, qtde_minima_paginas{n_min_paginas} {}

void Processo::trocar_estado(string e)
{
    this->estado = e;
}

string Processo::get_estado_atual()
{
    return this->estado;
}

void Processo::set_tabela_paginas(vector<int> tb)
{
    this->tb_paginas = tb;
};

// Número da página base
int Processo::get_pagina_base() {
    return tb_paginas[0];
}