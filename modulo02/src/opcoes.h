/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Parser para argumentos de entrada do programa Produtor/Consumidor          #
#################################################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <argp.h>

/* Estrutura que contém o valor dos parâmetros após o parsing. */
struct arguments
{
    int bsize, nprod, ncons, time, sprod, scons;
};

// Realizar o parser das opções informadas na linha de comando pelo usuário
struct arguments tratarOpcoes(int argc, char **argv);