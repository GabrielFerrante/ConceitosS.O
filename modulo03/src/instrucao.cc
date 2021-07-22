/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Formato da instrução e tipos de instruções                                 #
#################################################################################
*/

#include <iostream>
#include "instrucao.h"

using namespace std;

std::ostream &operator<<(std::ostream &os, const TipoInstrucao &tipo)
{
    switch (tipo)
    {
    case TipoInstrucao::C:
        os << "Novo Processo";
        break;
    case TipoInstrucao::I:
        os << "Instrução de CPU";
        break;
    case TipoInstrucao::P:
        os << "Instrução de IO";
        break;
    case TipoInstrucao::R:
        os << "Leitura";
        break;
    case TipoInstrucao::W:
        os << "Gravação";
    }
    return os;
}