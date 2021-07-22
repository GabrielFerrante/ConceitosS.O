/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Simulador                                                                  #
#################################################################################
*/

#include <iostream>
#include "simulador.h"

using namespace std;

void preparar();
void executar();
void executar1Passo();
void finalizar();

Simulador::Simulador(OpcoesSimulador *opcoes, vector<Instrucao> cmds)
{
    cout << "##### SIMULAÇÃO - INÍCIO #####" << endl << endl;

    this->opcoes = opcoes;
    this->cmds = cmds;

    mem_fisica = new MemoriaFisica(opcoes->mfsize, opcoes->frsize);
    mem_virtual = new MemoriaVirtual(opcoes->mvsize, opcoes->pgsize);
    mmu = new MMU(mem_fisica, mem_virtual, opcoes->substituicao_pagina);
    cpu = new CPU(mmu, opcoes->swapper);
    info = new AgregadorInfo(cpu, mmu, mem_virtual, mem_fisica);
}

Simulador::~Simulador()
{
    delete cpu;
    delete opcoes;
    delete info;
}

void Simulador::executar_1_passo()
{
    cpu->executar_instrucao(cmds[contador_instrucao]);
    contador_instrucao++;

    if (opcoes->debug) {
        info->simulador_info();
    }
}

void Simulador::executar()
{
    while (contador_instrucao < cmds.size())
    {
        executar_1_passo();
    }
}

void Simulador::finalizar()
{
    cout << "##### SIMULAÇÃO - FIM #####" << endl << endl;
}