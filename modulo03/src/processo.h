/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Representação do processo                                                  #
#################################################################################
*/

#ifndef PROCESSO_H
#define PROCESSO_H

#include <string>
#include <vector>

typedef std::vector<int> paginas_alocadas;

class Processo
{
public:
    // Novo processo id com estado, quantidade de memória necessária em kbytes e número mínimo de páginas para alocação
    Processo(std::string id, std::string estado, int alloc, int n_min_paginas);
    // Mantem os números das páginas alocadas para o processo
    paginas_alocadas tb_paginas;
    // Troca o estado do processo
    void trocar_estado(std::string e);
    // Retorna o estado atual do processo
    std::string get_estado_atual();
    // Configurar a tabela de páginas do processo
    void set_tabela_paginas(paginas_alocadas tb);
    // Retornar o número da página base associada ao processo
    int get_pagina_base();
    // Indica se o processo está em disco (causado pelo swapper)
    bool em_disco = true;
    // Alocação mínima necessária em kbytes
    int alocacao_minima;
    // Quantidade mínima de páginas necessárias
    int qtde_minima_paginas;
    // Identificador do processo
    std::string id;
    // Estado do processo - novo, pronto, suspenso, executando, bloqueado
    std::string estado;
};

#endif