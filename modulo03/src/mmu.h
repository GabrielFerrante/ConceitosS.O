/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Simulador da unidade de gerenciamento de memória                           #
#################################################################################
*/

#ifndef MMU_H
#define MMU_H

#include <vector>
#include <map>
#include "mmu.h"
#include "memoria_fisica.h"
#include "memoria_virtual.h"
#include "tabela_paginas_mmu.h"
#include "processo.h"
#include "troca_pagina.h"

class MMU
{
public:
    // Inicializa MMU com apontamentos para a memória física, virtual e o algoritmo de substituição de páginas escolhido
    MMU(MemoriaFisica *mfisica, MemoriaVirtual *mvirtual, TrocaPagina *sub_pagina);
    // Destrutor
    ~MMU();
    // Ler endereço de memória virtual requisitado pelo processo especificado
    void ler_endereco(int addr, Processo *proc, int contador_instrucao);
    // Gravar endereço de memória virtual requisitado pelo processo especificado
    void gravar_no_endereco(int addr, Processo *proc, int contador_instrucao);
    // Atualizar lista de páginas presentes
    void atualizar_lista_paginas_presentes();
    // Alocar n_paginas_necessarias. Retorna uma lista com os números das páginas alocadas
    std::vector<int> *alocar(int n_paginas_necessarias);
    // Verifica necessidade de compactação
    bool check_necessidade_compactacao(int n_paginas);
    // Realizar compactação de memória. As páginas livres são reposicionadas para o início do espaço de endereçamento.
    std::map<int, int> compactacao();
    // Apontador para a memória virtual
    MemoriaVirtual *mem_virtual;

private:
    // Contador de falhas de página (pages fault)
    int page_fault_counter = 0;
    // Apontador para a memória física
    MemoriaFisica *mem_fisica;
    // Tabela contendo o mapeamento entre páginas e frames
    TabelaPaginasMMU *tb_paginas;
    // Algoritmo de substituição de páginas
    TrocaPagina *subst_pagina;
    // Tabela de páginas presentes
    std::map<int, Pagina &> paginas_presentes;
    // Verificar se o acesso à página requisitado pelo processo é válido
    bool check_acesso_valido_processo(Processo *proc, int num_pagina);
    // Verificar se a página de número pg está presente
    bool check_pagina_presente(int pg);
    // Ler endereço físico addr
    void ler_endereco_fisico(int addr);
    // Escrever no endereço addr
    void escrita_endereco_fisico(int addr);
    // Rotina responsável pelo tratamento de page fault (falha de página)
    void tratar_page_fault(int pg);
    // Retornar o número do próximo quadro livre, se disponível
    int get_quadro_livre();
    // Salvar página número num_pagina no disco
    void salvar_pagina_no_disco(int num_pagina);

    // Permitir que a classe AgregadorInfo tenha acesso às instruturas internas na MMU
    friend class AgregadorInfo;
};

#endif