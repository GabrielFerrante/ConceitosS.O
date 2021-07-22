/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Agregador de informações para visualização                                 #
#################################################################################
*/

#include "agregador_info.h"

using namespace std;

AgregadorInfo::AgregadorInfo(CPU *cpu_, MMU *mmu_, MemoriaVirtual *mem_virtual_, MemoriaFisica *mem_fisica_) : cpu{cpu_},
                                                                                                               mmu{mmu_}, mem_virtual{mem_virtual_}, mem_fisica{mem_fisica_} {}

void AgregadorInfo::cpu_contador_instrucoes()
{
    cout << "### CPU - Contador de instrução: " << cpu->contador_instrucao << " ###" << endl
         << endl;
}

void AgregadorInfo::cpu_instrucao_atual()
{
    cout << "### CPU - Última instrução executada ###" << endl
         << endl;

    auto inst = cpu->instrucao_atual;

    cout << " - Processo: " << inst.processo << endl;
    cout << " - Tipo: " << inst.tipo << endl;
    cout << " - Endereço/Tamanho: " << inst.pos << endl
         << endl;
}

void AgregadorInfo::cpu_tabela_processos()
{
    cout << "### CPU - Tabela de processos ###" << endl
         << endl;

    for (auto p : cpu->tb_processos)
    {
        cout << " - ID: " << p->id;
        cout << " - Estado: " << p->estado;
        cout << " - Em disco: " << p->em_disco;
        cout << " - Páginas Alocadas: ";

        for (auto pg : p->tb_paginas)
        {
            cout << pg << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void AgregadorInfo::mem_virtual_espaco_enderecamento()
{
    cout << "### Memória Virtual - Espaço de Endereçamento ###" << endl
         << endl;

    int numero_pagina = 0;
    for (auto p : mem_virtual->espaco_enderecamento)
    {
        cout << "Página nº.: " << numero_pagina << endl;
        cout << "Alocada: " << p.alocada;
        cout << " - Modificada: " << p.modificada;
        cout << " - Referenciada: " << p.referenciada << endl;
        cout << "Última referência na instrução nº.: " << p.ultima_referencia << endl
             << endl;
        numero_pagina++;
    }
}

void AgregadorInfo::mmu_mapeamento()
{
    cout << "### MMU - Mapeamento entre Páginas e Quadros ###" << endl
         << endl;

    for (auto m = mmu->tb_paginas->mapeamento.begin(); m != mmu->tb_paginas->mapeamento.end(); m++)
    {
        int num_pagina = m->first;
        QuadroMapeamento &entry = m->second;

        cout << "Página nº.: " << num_pagina;
        cout << " - Quadro nº.: " << entry.numero_quadro;
        cout << " - Presente: " << entry.presente << endl;
    }
    cout << endl;
}

void AgregadorInfo::mmu_contador_page_faults() {
       cout << "### MMU - Contador de page faults: " << mmu->page_fault_counter << " ###" << endl
         << endl; 
}

void AgregadorInfo::simulador_info()
{
    cout << endl
         << "*** DEBUG - INÍCIO ***" << endl
         << endl;
    cpu_contador_instrucoes();
    cpu_instrucao_atual();
    cpu_tabela_processos();
    mem_virtual_espaco_enderecamento();
    mmu_mapeamento();
    mmu_contador_page_faults();
    cout << "*** DEBUG - FIM ***" << endl
         << endl;
}