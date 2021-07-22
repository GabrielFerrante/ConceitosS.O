/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Parser de instruções                                                       #
#################################################################################
*/

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "instrucao.h"

class ParserInstrucao
{
public:
    // Recebe como entrada o arquivo contendo diversas instruções
    ParserInstrucao(const std::string arq_instrucoes);
    // Retornar as instruções após parsing do arquivo
    std::vector<Instrucao> get_instrucoes();
    // Total de instruções
    int total_instrucoes();

private:
    std::string nome_arquivo_instrucoes;
    std::vector<Instrucao> lista_instrucoes;

    int executar_parser();
    Instrucao parsing(const std::string linha);
    TipoInstrucao _mapeamento_instrucao(std::string tipo);
};

#endif