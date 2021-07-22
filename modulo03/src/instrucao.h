/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Formato da instrução e tipos de instruções                                 #
#################################################################################
*/

#ifndef INSTRUCAO_H
#define INSTRUCAO_H

#include <string>

// Tipos de instruções possíveis
enum class TipoInstrucao { C, R, W, P, I };

// Impressão do tipo de instrução
std::ostream &operator<<(std::ostream &os, const TipoInstrucao &tipo);

// Formato de uma instrução
struct Instrucao
{
    // Identificador do processo
    std::string processo;
    // Tipo de instrução
    TipoInstrucao tipo;
    // Tamanho/posição de memória
    std::string pos;
};

#endif