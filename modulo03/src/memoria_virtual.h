/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Simulador da memória virtual                                               #
#################################################################################
*/

#ifndef MEMORIA_VIRTUAL_H
#define MEMORIA_VIRTUAL_H

#include <vector>

class Pagina
{

public:
    // Especificar o tamanho da página em kbytes
    Pagina(int tam);
    // Página alocada para um processo?
    bool alocada = false;
    // Página modificada/suja (dirty)?
    bool modificada = false;
    // Página foi referenciada?
    bool referenciada = false;
    // Qual a última instrução que fez referência a esta página?
    int ultima_referencia = 0;

private:
    // Tamanho da página em kbytes
    int tamanho;
};

class MemoriaVirtual
{
public:
    // Especificar o tamanho da memória virtual em kbytes e o número de páginas
    MemoriaVirtual(int tam_mem, int tam_pagina);
    // Alocar n_paginas
    int alocar(int n_paginas);
    // Quantidade de páginas
    int num_paginas;
    // Tamanho da página em kbytes
    int tamanho_pagina;
     // Quantidade de páginas livres
    int total_paginas_livres();
    // Espaço de endereçamento virtual
    std::vector<Pagina> espaco_enderecamento;
    // Procura por n páginas sequenciais livres na memória e retorna o número da inicial.
    int procurar_n_paginas_sequenciais_livres(int n);

private:
    // Tamanho da memória virtual em kbytes
    int tamanho;

    // Consolidar alocação de memória
    void consolidar_alocacao(int n, int pagina_inicial);
    // Verificar se existem n páginas livres
    bool existe_n_paginas_livres(int n);
};

#endif
