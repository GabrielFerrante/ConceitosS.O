/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Parser para argumentos de entrada do programa Simulador                    #
#################################################################################
*/

#include "opcoes_simulador.h"

using namespace std;

OpcoesSimulador *OpcoesSimulador::tratarOpcoes(int argc, char **argv)
{
    OpcoesSimulador *opcoes_sim = new OpcoesSimulador();

    cxxopts::Options options("Simulador v1.0", "Simulador de gerenciamento de memória virtual com paginação.");

    options.add_options()
    ("d,debug", "Habilitar debug para mostrar valores das estruturas internas do simulador.", cxxopts::value<bool>()->default_value("false"))
    ("i,finput", "Arquivo com instruções para execução no simulador.", cxxopts::value<string>()->default_value("instrucoes.txt"))
    ("p,pgsize", "Tamanho da página em Kbytes.", cxxopts::value<int>()->default_value("4"))
    ("f,frsize", "Tamanho do quadro de página em Kbytes.", cxxopts::value<int>()->default_value("4"))
    ("m,mfsize", "Tamanho máximo da memória física em Kbytes.", cxxopts::value<int>()->default_value("32"))
    ("v,mvsize", "Tamanho máximo da memória virtual em Kbytes.", cxxopts::value<int>()->default_value("64"))
    ("a,trocapagina", "Algoritmo de troca de página. Opções: lru, random ou relogio.", cxxopts::value<string>()->default_value("lru"))
    ("s,trocaprocesso", "Algoritmo de swapping de processos para o disco. Opções: bestfit ou firstfit.", cxxopts::value<string>()->default_value("bestfit"))
    ("h,help", "Help.");

    // Parsing das opções informadas na linha de comando pelo usuário
    auto parsing_arg = options.parse(argc, argv);

    if (parsing_arg.count("help"))
    {
        cout << options.help() << endl;
        exit(0);
    }

    opcoes_sim->finput = parsing_arg["finput"].as<string>();
    opcoes_sim->mvsize = parsing_arg["mvsize"].as<int>();
    opcoes_sim->mfsize = parsing_arg["mfsize"].as<int>();
    opcoes_sim->pgsize = parsing_arg["pgsize"].as<int>();
    opcoes_sim->frsize = parsing_arg["frsize"].as<int>();
    opcoes_sim->debug = parsing_arg["debug"].as<bool>();

    string trocador_de_pagina = parsing_arg["trocapagina"].as<string>();

    if (trocador_de_pagina == "lru")
    {
        opcoes_sim->substituicao_pagina = new TrocaPaginaLRU();
    }
    else if (trocador_de_pagina == "random")
    {
        opcoes_sim->substituicao_pagina = new TrocaPaginaAleatoria();
    }
    else if (trocador_de_pagina == "relogio")
    {
        opcoes_sim->substituicao_pagina = new TrocaPaginaRelogio();
    }
    else
    {
        cout << "Erro. Algoritmo de troca de páginas informado não existe." << endl;
        exit(1);
    }

    string trocador_de_processo = parsing_arg["trocaprocesso"].as<string>();

    if (trocador_de_processo == "firstfit")
    {
        opcoes_sim->swapper = new TrocaProcessoFirstFit();
    }
    else if (trocador_de_processo == "bestfit")
    {
        opcoes_sim->swapper = new TrocaProcessoBestFit();
    }
    else
    {
        cout << "Erro. Algoritmo de swapping de processos informado não existe." << endl;
        exit(1);
    }

    return opcoes_sim;
}