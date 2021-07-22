/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Agregador de informações para visualização                                 #
#################################################################################
*/

#ifndef INFO_H
#define INFO_H

#include <iostream>
#include "cpu.h"
#include "mmu.h"
#include "memoria_virtual.h"
#include "memoria_fisica.h"

class AgregadorInfo
{
public:
    AgregadorInfo(CPU *cpu_, MMU* mmu_, MemoriaVirtual* mem_virtual_, MemoriaFisica* mem_fisica_);
    void cpu_contador_instrucoes();
    void cpu_instrucao_atual();
    void cpu_tabela_processos();
    void mem_virtual_espaco_enderecamento();
    void mmu_mapeamento();
    void mmu_contador_page_faults();
    void simulador_info();
    

private:
    CPU *cpu;
    MMU *mmu;
    MemoriaVirtual* mem_virtual;
    MemoriaFisica* mem_fisica;
};




#endif