/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Simulador de CPU                                                           #
#################################################################################
*/

#include <iostream>
#include <cmath>
#include <regex>
#include "cpu.h"

using namespace std;

CPU::CPU(MMU *mmu, TrocaProcesso *s) : mmu{mmu}, swapper{s} {}

CPU::~CPU()
{
    delete mmu;
    delete swapper;
    for (auto p : tb_processos)
    {
        delete p;
    }
}

void CPU::executar_instrucao(const Instrucao &cmd)
{
    this->instrucao_atual = cmd;
    TipoInstrucao tipo_instrucao = instrucao_atual.tipo;

    switch (tipo_instrucao)
    {
    case TipoInstrucao::C:
        criar_processo();
        break;
    case TipoInstrucao::I:
        executar_instrucao_cpu();
        break;
    case TipoInstrucao::P:
        executar_instrucao_io();
        break;
    case TipoInstrucao::R:
        executar_leitura();
        break;
    case TipoInstrucao::W:
        executar_escrita();
        break;
    default:
        cout << "Erro. Instrução inválida." << endl;
        exit(1);
    }

    this->contador_instrucao++;
    mmu->atualizar_lista_paginas_presentes();
}

void CPU::criar_processo()
{
    cout << "[Criando Processo " << instrucao_atual.processo << "]" << endl;

    int tamanho_alocacao = atoi(instrucao_atual.pos.c_str());
    int qtd_paginas_necessarias = ceil((float)tamanho_alocacao * 1024 / mmu->mem_virtual->tamanho_pagina);

    Processo *novo_processo = new Processo{instrucao_atual.processo, "NOVO", tamanho_alocacao, qtd_paginas_necessarias};

    // Alocar memória virtual para o novo processo - Checando necessidade de swapping e/ou compactação de memória
    if (!processo_em_memoria(instrucao_atual.processo))
    {
        alocar_processo_na_memoria(novo_processo);
    }

    novo_processo->trocar_estado("PRONTO");
    tb_processos.push_back(novo_processo);
}

void CPU::executar_instrucao_cpu()
{
    cout << "[" << instrucao_atual.processo << "] Instrução CPU" << endl;

    int addr_instrucao = parse_endereco(instrucao_atual.pos);

    Processo *proc = pesquisar_tabela_processos(instrucao_atual.processo);

    // Verifica se processo foi alocado anteriormente
    if (proc == nullptr)
    {
        cout << "Erro. Acesso inválido. Processo não foi criado anteriormente." << endl;
        exit(1);
    }

    if (!processo_em_memoria(instrucao_atual.processo))
    {
        alocar_processo_na_memoria(proc);
    }

    proc->trocar_estado("EXECUTANDO");

    // Processo em memória. Executar instrução de leitura de posíção de memória
    mmu->ler_endereco(addr_instrucao, proc, contador_instrucao);

    // Executar instrucao lida na posição de memória informada.
    executar_instrucao_cpu_lida(addr_instrucao);

    proc->trocar_estado("PRONTO");
}

void CPU::executar_instrucao_io()
{
    cout << "[" << instrucao_atual.processo << "] Instrução IO" << endl;

    int addr_instrucao = parse_endereco(instrucao_atual.pos);

    Processo *proc = pesquisar_tabela_processos(instrucao_atual.processo);

    // Verifica se processo foi alocado anteriormente
    if (proc == nullptr)
    {
        cout << "Erro. Acesso inválido. Processo não foi criado anteriormente." << endl;
        exit(1);
    }

    if (!processo_em_memoria(instrucao_atual.processo))
    {
        alocar_processo_na_memoria(proc);
    }

    proc->trocar_estado("EXECUTANDO");

    // Processo em memória. Executar instrução de leitura de posíção de memória
    mmu->ler_endereco(addr_instrucao, proc, contador_instrucao);

    // Executar instrucao lida na posição de memória informada.
    executar_instrucao_io_lida(addr_instrucao);

    proc->trocar_estado("PRONTO");
}

void CPU::executar_leitura()
{
    cout << "[" << instrucao_atual.processo << "] Leitura" << endl;

    int addr_leitura = parse_endereco(instrucao_atual.pos);

    Processo *proc = pesquisar_tabela_processos(instrucao_atual.processo);

    // Verifica se processo foi alocado anteriormente
    if (proc == nullptr)
    {
        cout << "Erro. Acesso inválido. Processo não foi criado anteriormente." << endl;
        exit(1);
    }

    if (!processo_em_memoria(instrucao_atual.processo))
    {
        alocar_processo_na_memoria(proc);
    }

    proc->trocar_estado("EXECUTANDO");

    // Processo em memória. Executar instrução de leitura de posíção de memória
    mmu->ler_endereco(addr_leitura, proc, contador_instrucao);

    proc->trocar_estado("PRONTO");
}

void CPU::executar_escrita()
{
    cout << "[" << instrucao_atual.processo << "] Escrita" << endl;

    int addr_gravacao = parse_endereco(instrucao_atual.pos);

    Processo *proc = pesquisar_tabela_processos(instrucao_atual.processo);

    // Verifica se processo foi alocado anteriormente
    if (proc == nullptr)
    {
        cout << "Erro. Acesso inválido. Processo não foi criado anteriormente." << endl;
        exit(1);
    }

    if (!processo_em_memoria(instrucao_atual.processo))
    {
        alocar_processo_na_memoria(proc);
    }

    proc->trocar_estado("EXECUTANDO");

    // Processo em memória. Executar instrução de escrita na posíção de memória
    mmu->gravar_no_endereco(addr_gravacao, proc, contador_instrucao);

    proc->trocar_estado("PRONTO");
}

bool CPU::processo_em_memoria(string id)
{
    Processo *proc = pesquisar_tabela_processos(id);

    if (!proc || proc->em_disco)
    {
        return false;
    }

    return true;
}

void CPU::alocar_processo_na_memoria(Processo *proc)
{
    // Tem espaço livre na memória pra trazer o processo do disco?
    int total_paginas_livres = mmu->mem_virtual->total_paginas_livres();

    // swapping se necessário
    if (proc->qtde_minima_paginas > total_paginas_livres)
    {
        // swapping-out - Tirar processo da memória
        swapper->run(tb_processos, mmu->mem_virtual->espaco_enderecamento, total_paginas_livres - proc->qtde_minima_paginas);
    }

    bool is_compactacao_necessaria = mmu->check_necessidade_compactacao(proc->qtde_minima_paginas);

    if (is_compactacao_necessaria)
    {
        // Realizar compactação da memória
        auto novo_enderecamento = mmu->compactacao();

        // Remapear tabela de páginas dos processos
        corrigir_tabela_paginas_processos(novo_enderecamento);
    }

    proc->set_tabela_paginas(*mmu->alocar(proc->qtde_minima_paginas));

    // swapping-in
    swapper->swap_in(proc);
}

Processo *CPU::pesquisar_tabela_processos(string id)
{
    for (auto p : tb_processos)
    {

        if (p->id == id)
        {
            return p;
        }
    }

    return nullptr;
}

int CPU::parse_endereco(string addr)
{
    string addr_bin = "";
    string regExprStr(R"(\((\d+)\))");
    regex rgx(regExprStr);
    smatch smatch;

    if (regex_search(addr, smatch, rgx))
    {
        addr_bin = smatch[1];
    }

    return atoi(addr_bin.c_str());
}

// Remapear os novos endereços das páginas alocadas dos processos
void CPU::corrigir_tabela_paginas_processos(map<int, int> novo_enderecamento)
{
    for (auto proc : tb_processos)
    {
        vector<int> novos_enderecos_paginas_alocadas{};

        for (auto pg : proc->tb_paginas)
        {
            novos_enderecos_paginas_alocadas.push_back(novo_enderecamento[pg]);
        }

        proc->tb_paginas.clear();
        proc->tb_paginas = novos_enderecos_paginas_alocadas;
    }
}

// Executar instrução de CPU lida
void CPU::executar_instrucao_cpu_lida(int addr_instrucao)
{
    cout << "Executando instrução de CPU indicada no endereço: " << addr_instrucao << endl;
}

// Executar instrução de IO lida
void CPU::executar_instrucao_io_lida(int addr_instrucao)
{
    cout << "Executando instrução de IO indicada no endereço: " << addr_instrucao << endl;
}