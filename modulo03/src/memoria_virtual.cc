/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Simulador da memória virtual                                               #
#################################################################################
*/

#include <iostream>
#include <algorithm>
#include "memoria_virtual.h"

using namespace std;

// Tamanho da página em kbytes
Pagina::Pagina(int tam)
{
    this->tamanho = tam * 1024;
}

MemoriaVirtual::MemoriaVirtual(int tam_mem, int tam_pagina)
{
    if (tam_mem % tam_pagina != 0)
    {
        cout << "Erro: Tamanho da memória virtual precisa ser um múltiplo do tamanho da página." << endl;
        exit(1);
    }

    // Tamanho da memória virtual em bytes
    tamanho = tam_mem * 1024;

    // Tamanho da página em bytes
    tamanho_pagina = tam_pagina * 1024;

    // Número de páginas
    num_paginas = tamanho / tamanho_pagina;

    // Pre alocação do vector do espaco de endereçamento
    espaco_enderecamento.reserve(num_paginas);

    // Criando espaco de endereçamento
    for (auto i = 0; i < num_paginas; i++)
    {
        espaco_enderecamento.push_back(Pagina{tam_pagina});
    }
}

// Alocar n paginas - first fit
int MemoriaVirtual::alocar(int n)
{
    int pagina_inicial = -1;

    if (n > num_paginas)
    {
        cout << "Erro: Alocação de páginas requisitadas maior do que a memória virtual disponível." << endl;
        exit(1);
    }

    // Existem n páginas para alocar?
    if (existe_n_paginas_livres(n))
    {
        // Buscar endereço do início das n páginas sequenciais
        pagina_inicial = procurar_n_paginas_sequenciais_livres(n);
        

        consolidar_alocacao(n, pagina_inicial);
    }

    return pagina_inicial;
}

// Consolida a alocação de n páginas continuas a partir de pagina_inicial
void MemoriaVirtual::consolidar_alocacao(int n, int pagina_inicial)
{
    for (auto i = pagina_inicial; i < n; i++)
    {
        espaco_enderecamento[i].alocada = true;
    }
}

int MemoriaVirtual::total_paginas_livres()
{
    int total_nao_alocadas = 0;

    for (auto p = espaco_enderecamento.begin(); p != espaco_enderecamento.end(); p++)
    {
        if (!p->alocada)
        {
            total_nao_alocadas++;
        }
    }

    return total_nao_alocadas;
}

bool MemoriaVirtual::existe_n_paginas_livres(int n)
{
    return total_paginas_livres() >= n;
}

int MemoriaVirtual::procurar_n_paginas_sequenciais_livres(int n)
{
    int pagina_inicial = -1;
    int contador_livres = 0;
    vector<Pagina>::iterator ref_inicial_bloco_livre;

    for (auto p = espaco_enderecamento.begin(); p != espaco_enderecamento.end(); p++)
    {
        if (!p->alocada)
        {
            // Página não alocada. Controlar contagem

            if (contador_livres == 0)
            {
                ref_inicial_bloco_livre = p;
            }

            contador_livres++;

            if (contador_livres >= n)
            {
                // Sequencia de n paginas livres já encontrada
                pagina_inicial = distance(espaco_enderecamento.begin(), ref_inicial_bloco_livre);

                return pagina_inicial;
            }
        }
        else
        {
            // Página alocada. Zera a contagem de páginas livres em sequência
            contador_livres = 0;
        }
    }

    return pagina_inicial;
}
