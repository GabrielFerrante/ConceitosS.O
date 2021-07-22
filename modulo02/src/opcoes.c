/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Parser para argumentos de entrada do programa Produtor/Consumidor          #
#################################################################################
*/

#include "opcoes.h"

/* Descrição dos argumentos obrigatórios - Não tem */
static char args_doc[] = "";

/* Versão do programa */
const char *argp_program_version = "produtor_consumidor 1.0.0";

/* Descrição do programa */
static char doc[] =
    "Produtor/Consumidor - Com utilização de threads e semáforos.";

/* Opções disponíveis */
static struct argp_option options[] = {
    {"bsize", 'b', "TAM", 0, "Tamanho do buffer (default: 15)"},
    {"nprod", 'p', "NUM", 0, "Número de produtores (default: 25)"},
    {"ncons", 'c', "NUM", 0, "Número de consumidores (default: 8)"},
    {"sprod", 's', "MSEG", 0, "Tempo sleep (milissegundos) dos produtores (para debug apenas) (default: 1000ms)"},
    {"scons", 'l', "MSEG", 0, "Tempo sleep (milissegundos) dos consumidores (para debug apenas) (default: 1000ms)"},
    {"time", 't', "SEG", 0, "Tempo máximo (segundos) de execução do programa (default: 30s)"},
    {0}};

/* Parsing de uma única opção. */
static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = state->input;

    switch (key)
    {
    case 'b':
        arguments->bsize = strtol(arg, NULL, 10);
        break;
    case 'p':
        arguments->nprod = strtol(arg, NULL, 10);
        break;
    case 'c':
        arguments->ncons = strtol(arg, NULL, 10);
        break;
    case 's':
        arguments->sprod = strtol(arg, NULL, 10);
        break;
    case 'l':
        arguments->scons = strtol(arg, NULL, 10);
        break;    
    case 't':
        arguments->time = strtol(arg, NULL, 10);
        break;

    case ARGP_KEY_ARG:
        // Mais argumentos informados do que existem
        if (state->arg_num >= 7)
            argp_usage(state);
        break;

    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

// Realizar o parser das opções informadas na linha de comando pelo usuário
struct arguments tratarOpcoes(int argc, char **argv) {

    static struct argp argp = {options, parse_opt, args_doc, doc};

    struct arguments arguments;

    /* Valores default */
    arguments.bsize = 15;
    arguments.nprod = 25;
    arguments.ncons = 8;
    arguments.sprod = 1000;
    arguments.scons = 1000;
    arguments.time = 30;

    // Parsing das opções na linha de comando
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    printf("Parâmetros:\n \
    Tamanho do Buffer = %d\n \
    Número de Produtores = %d\n \
    Número de Consumidores = %d\n \
    Sleep para Produtores = %dms\n \
    Sleep para Consumidores = %dms\n \
    Tempo (máx) de execução = %ds\n\n", 
    arguments.bsize, arguments.nprod, arguments.ncons, arguments.sprod, arguments.scons, arguments.time);

    return arguments;
}