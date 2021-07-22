/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Simulador de CPU                                                           #
#################################################################################
*/

#ifndef CPU_H
#define CPU_H

#include <string>
#include <vector>
#include <map>
#include "mmu.h"
#include "instrucao.h"
#include "processo.h"
#include "troca_processo.h"
#include "processo.h"

class CPU
{
public:
    // Inicializar CPU com apontamentos para a MMU e para o algoritmo de swapping escolhido.
    CPU(MMU *mmu, TrocaProcesso *s);
    // Destrutor
    ~CPU();
    // Executar instrução cmd informada.
    void executar_instrucao(const Instrucao &cmd);

private:
    // Apontamento para a MMU
    MMU *mmu;
    // Algoritmo de swapping de processos para disco
    TrocaProcesso *swapper;
    // Tabela de processos
    std::vector<Processo *> tb_processos;
    // Instrução atual em/para execução
    Instrucao instrucao_atual;
    // Número da instrução atual
    int contador_instrucao = 0;
    // Pesquisar por processo com identificador id na tabela de processos
    Processo *pesquisar_tabela_processos(std::string id);

    // Criar novo processo
    void criar_processo();
    // Executar instrução de CPU
    void executar_instrucao_cpu();
    // Executar instrução de IO
    void executar_instrucao_io();
    // Executar instrução de leitura
    void executar_leitura();
    // Executar instrução de escrita
    void executar_escrita();
    // Verificar se o processo id está na memória
    bool processo_em_memoria(std::string id);
    // Alocar processo na memória
    void alocar_processo_na_memoria(Processo *proc);
    // Parsing do endereço binário informado na instrução
    int parse_endereco(std::string addr);
    // Executar a instrução de CPU lida do endereço addr_instrucao
    void executar_instrucao_cpu_lida(int addr_instrucao);
    // Executar a instrução de IO lida do endereço addr_instrucao
    void executar_instrucao_io_lida(int addr_instrucao);
    // Corrigir tabela de páginas dos processos de acordo com o novo enderecamento informado
    void corrigir_tabela_paginas_processos(std::map<int, int> novo_enderecamento);

    // Permitir que a classe AgregadorInfo tenha acesso às instruturas internas na MMU
    friend class AgregadorInfo;
};

#endif