/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Parser de instruções                                                       #
#################################################################################
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <cstring>
#include "parser_instrucao.h"

using namespace std;

ParserInstrucao::ParserInstrucao(const string arq_instrucoes) : nome_arquivo_instrucoes{arq_instrucoes}
{
    this->executar_parser();
}

vector<Instrucao> ParserInstrucao::get_instrucoes()
{
    return this->lista_instrucoes;
}

int ParserInstrucao::total_instrucoes()
{
    return this->lista_instrucoes.size();
}

int ParserInstrucao::executar_parser()
{
    // Abrir arquivo com instruções para execução
    ifstream input_file(nome_arquivo_instrucoes);

    vector<string> lines;
    string linha;

    if (!input_file.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de instruções - '"
             << nome_arquivo_instrucoes << "'" << endl;
        return EXIT_FAILURE;
    }

    while (getline(input_file, linha))
    {
        Instrucao cmd = parsing(linha);
        this->lista_instrucoes.push_back(cmd);
    }

    input_file.close();
    return EXIT_SUCCESS;
}

Instrucao ParserInstrucao::parsing(const string linha)
{
    stringstream ss(linha);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> tokens(begin, end);

    Instrucao cmd;

    // Processo
    cmd.processo = tokens[0];

    // Tipo de instrução
    cmd.tipo = _mapeamento_instrucao(tokens[1]);

    // Posição de acesso a memória ou tamanho em kb para alocação
    cmd.pos = tokens[2];

    return cmd;
}

// Mapeamento de stirng para tipo TipoInstrucao
TipoInstrucao ParserInstrucao::_mapeamento_instrucao(string tipo) {

    // Novo Procesos
    if(tipo == "C") 
        return TipoInstrucao::C;

    // Instrução de IO
    if(tipo == "I") 
        return TipoInstrucao::I;

    // Instrução de CPU
    if(tipo == "P") 
        return TipoInstrucao::P;

    // Leitura
    if(tipo == "R") 
        return TipoInstrucao::R;

    // Escrita
    if(tipo == "W") 
        return TipoInstrucao::W;  

     return TipoInstrucao{};
}
