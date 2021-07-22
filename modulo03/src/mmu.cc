/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Simulador da unidade de gerenciamento de memória                           #
#################################################################################
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include "mmu.h"
#include "troca_pagina_relogio.h"

using namespace std;

MMU::MMU(MemoriaFisica *mfisica, MemoriaVirtual *mvirtual, TrocaPagina *sub_pagina) : mem_fisica{mfisica}, mem_virtual{mvirtual}, subst_pagina{sub_pagina}
{
    this->tb_paginas = new TabelaPaginasMMU((*mvirtual).num_paginas, (*mfisica).num_quadros);
}

MMU::~MMU()
{
    delete mem_fisica;
    delete mem_virtual;
    delete tb_paginas;
    delete subst_pagina;
}

vector<int> *MMU::alocar(int n_paginas_necessarias)
{
    vector<int> *paginas_alocadas = new vector<int>{};

    int pagina_inicial = mem_virtual->alocar(n_paginas_necessarias);

    if (pagina_inicial != -1)
    {
        // Lista de paginas alocadas para o processo
        for (auto i = 0; i < n_paginas_necessarias; i++)
        {
            paginas_alocadas->push_back(pagina_inicial + i);
        }
    }

    return paginas_alocadas;
}

void MMU::ler_endereco(int addr, Processo *proc, int contador_instrucao)
{
    // Número da página sendo acessada - Deslocamento a partir do registrador base.
    int numero_pagina = addr / mem_virtual->tamanho_pagina + proc->get_pagina_base();

    // Verificar se a página acessada é permitida para o processo
    if (!check_acesso_valido_processo(proc, addr))
    {
        // Acesso inválido
        cout << "Erro. Tentativa de acesso inválido à memória. Processo: " << proc->id << " " << endl;
        exit(1);
    }

    // Página virtual
    Pagina &pg = mem_virtual->espaco_enderecamento[numero_pagina];

    // Verificar se página está presente, caso contrário gera falta de página (page fault)
    if (!check_pagina_presente(numero_pagina))
    {
        // Page fault
        cout << "PAGE FAULT. Chamando rotina de tratamento." << endl;
        tratar_page_fault(numero_pagina);
    }

    // Página referenciada (leitura)
    pg.referenciada = true;
    pg.ultima_referencia = contador_instrucao;

    // Número do quadro na memória física
    int num_quadro = tb_paginas->get_quadro(numero_pagina);

    // deslocamento (resto da divisão)
    int addr_deslocamento = addr % mem_virtual->tamanho_pagina;

    // Ler endereço físico
    int addr_fisico = num_quadro * mem_fisica->tamanho_quadro + addr_deslocamento;

    cout << "Mapeamento de endereço - Virtual: " << addr << " Físico: " << addr_fisico << endl;

    ler_endereco_fisico(addr_fisico);
}

// Checa se processo tem permissão par acessar o endereço solicitado
bool MMU::check_acesso_valido_processo(Processo *proc, int addr)
{
    int total_de_paginas_alocadas = proc->tb_paginas.size();

    int addr_limite = mem_virtual->tamanho_pagina * total_de_paginas_alocadas - 1;

    if (addr <= addr_limite)
    {
        return true;
    }

    return false;
}

// Check se a página está mapeada na memória física
bool MMU::check_pagina_presente(int pg)
{
    int num_quadro = tb_paginas->get_quadro(pg);

    if (num_quadro != -1)
    {
        return true;
    }

    return false;
}

// Tratamento para falta de página
void MMU::tratar_page_fault(int pg)
{
    // Contador de falta de páginas
    page_fault_counter++;

    //### Tratamento de page fault ###

    // Existe memória física disponível?
    int num_quadro = get_quadro_livre();

    if (num_quadro == -1)
    {
        // Não existe. É preciso substituir uma página

        // Passar lista de páginas presentes para o trocador de páginas
        auto num_pagina_vitima = subst_pagina->run(paginas_presentes);

        Pagina &pg_vitima = mem_virtual->espaco_enderecamento[num_pagina_vitima];

        if (pg_vitima.modificada)
        {
            salvar_pagina_no_disco(num_pagina_vitima);
            pg_vitima.modificada = false;
        }
        tb_paginas->desmapear(num_pagina_vitima);
        num_quadro = get_quadro_livre();
    }

    tb_paginas->mapear(pg, num_quadro);
}

// Leitura de endereço físico
void MMU::ler_endereco_fisico(int addr)
{
    mem_fisica->ler_endereco(addr);
}

// Busca por quadro livre - First-fit
int MMU::get_quadro_livre()
{
    int num_quadro_livre = -1;

    // Pesquisa qual quadro está mapeado
    // true -> em uso
    // false -> livre
    bool bitmap_quadros_ocupados[mem_fisica->num_quadros];

    for (int i = 0; i < mem_fisica->num_quadros; i++)
    {
        bitmap_quadros_ocupados[i] = false;
    }

    for (int i = 0; i < mem_virtual->num_paginas; ++i)
    {
        int quadro = tb_paginas->get_quadro(i);

        if (quadro != -1)
        {
            // quadro em uso
            bitmap_quadros_ocupados[quadro] = true;
        }
    }

    for (int n = 0; n < mem_fisica->num_quadros; n++)
    {
        if (!bitmap_quadros_ocupados[n])
        {
            // Quadro não alocado encontrado.
            num_quadro_livre = n;
            break;
        }
    }

    return num_quadro_livre;
}

// Salvar página no disco
void MMU::salvar_pagina_no_disco(int pg_vitima)
{
    cout << "Salvando página nº " << pg_vitima << endl;
}

// Páginas presentes
void MMU::atualizar_lista_paginas_presentes()
{
    paginas_presentes.clear();

    vector<int> numeros_paginas_presentes = tb_paginas->get_numeros_paginas_presentes();

    for (auto pg_num : numeros_paginas_presentes)
    {
        Pagina &pg = mem_virtual->espaco_enderecamento[pg_num];
        paginas_presentes.insert(pair<int, Pagina &>(pg_num, pg));
    }
}

void MMU::gravar_no_endereco(int addr, Processo *proc, int contador_instrucao)
{

    // Número da página sendo acessada - Deslocamento a partir do registrador base.
    int numero_pagina = addr / mem_virtual->tamanho_pagina + proc->get_pagina_base();

    // Verificar se a página acessada é permitida para o processo
    if (!check_acesso_valido_processo(proc, addr))
    {
        // Acesso inválido
        cout << "Erro. Tentativa de acesso inválido à memória. Processo: " << proc->id << " " << endl;
    }

    // Página virtual
    Pagina &pg = mem_virtual->espaco_enderecamento[numero_pagina];

    // Verificar se página está presente, caso contrário gera falta de página (page fault)
    if (!check_pagina_presente(numero_pagina))
    {
        // Page fault
        cout << "PAGE FAULT. Chamando rotina de tratamento." << endl;
        tratar_page_fault(numero_pagina);
    }

    // Página referenciada (escrita)
    pg.referenciada = true;
    pg.modificada = true;
    pg.ultima_referencia = contador_instrucao;

    // Número do quadro na memória física
    int num_quadro = tb_paginas->get_quadro(numero_pagina);

    // deslocamento (resto da divisão)
    int addr_deslocamento = addr % mem_virtual->tamanho_pagina;

    // Ler endereço físico
    int addr_fisico = num_quadro * mem_fisica->tamanho_quadro + addr_deslocamento;

    cout << "Mapeamento de endereço - Virtual: " << addr << " Físico: " << addr_fisico << endl;

    escrita_endereco_fisico(addr_fisico);
}

// Escritar de endereço físico
void MMU::escrita_endereco_fisico(int addr)
{
    mem_fisica->escrita_endereco(addr);
}

// Verificar necessidade de compactação caso seja necessário alocar n páginas
bool MMU::check_necessidade_compactacao(int n_paginas)
{
    int num_pagina = mem_virtual->procurar_n_paginas_sequenciais_livres(n_paginas);

    if (num_pagina == -1)
    {
        return true;
    }

    return false;
}

// Realizar compactação. Todas as páginas não alocadas estarão no início do vector
// Retorna o mapeamento para o novo espaço de endereçamento
map<int, int> MMU::compactacao()
{
    vector<Pagina> novo_espaco_enderecamento;

    // bitmap de alocação de págnas
    vector<pair<int, bool>> bitmap_alocacao{};

    // <endereco antigo, endereco novo>
    map<int, int> map_realocacao{};

    // Configurar bitmap
    for (int i = 0; i < mem_virtual->num_paginas; i++)
    {
        bitmap_alocacao.push_back(pair<int, bool>{i, mem_virtual->espaco_enderecamento[i].alocada});
    }

    // Ordenar bitmap alocação -> Páginas não alocadas ficam no início do espaço de endereçamento
    sort(bitmap_alocacao.begin(), bitmap_alocacao.end(), [](const pair<int, bool> &a, const pair<int, bool> &b)
         { return int(a.second) < int(b.second); });

    // Realocando páginas
    for (auto b = bitmap_alocacao.begin(); b != bitmap_alocacao.end(); b++)
    {
        Pagina pg = mem_virtual->espaco_enderecamento[b->first];
        novo_espaco_enderecamento.push_back(pg);
        map_realocacao.insert(pair<int, int>{b->first, novo_espaco_enderecamento.size() - 1});
    }

    // Consolidando compactação (assigment seguro. conteúdo de Pagina só de tipos primitivos)
    mem_virtual->espaco_enderecamento = novo_espaco_enderecamento;

    tb_paginas->remapear(map_realocacao);
    atualizar_lista_paginas_presentes();

    // Se o algoritmo de troca é o do relógio, é preciso acertar o ponteiro após a compactação
    if (dynamic_cast<TrocaPaginaRelogio *>(subst_pagina) != nullptr)
    {
        // Recupera subclasse do relógio
        auto relogio = dynamic_cast<TrocaPaginaRelogio *>(subst_pagina);
        // Ponteiro atual do relógio
        auto posicao_atual = relogio->recuperar_ponteiro_relogio();
        // Verifica onde está a página apontada anteriormente e qual sua nova posição
        auto map_it = map_realocacao.find(posicao_atual);
        // Ajusta o ponteiro do relógio
        relogio->ajustar_ponteiro_relogio(map_it->second);
    }

    return map_realocacao;
}
