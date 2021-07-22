/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Executando o simulador                                                     #
#################################################################################
*/

#include <iostream>
#include "simulador.h"
#include "opcoes_simulador.h"
#include "parser_instrucao.h"

using namespace std;

int main(int argc, char **argv)
{
    OpcoesSimulador *opcoes = OpcoesSimulador::tratarOpcoes(argc, argv);

    // Parsing do arquivo de instruções
    ParserInstrucao ps{opcoes->finput};
    vector<Instrucao> cmds = ps.get_instrucoes();

    // Instânciando simulador
    Simulador sim{opcoes, cmds};

    // Executar 1 passo da simulação (1 instrução)
    //sim.executar_1_passo();

    // Executar todas as instruções
    sim.executar();

    // Finalizar simulador
    sim.finalizar();

    return EXIT_SUCCESS;
}