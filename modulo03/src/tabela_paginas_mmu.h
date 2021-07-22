
/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Representação da tabela de páginas da MMU utilizada para mapeamento        #
#    da memória virtual para a memória física.                                  #
#################################################################################
*/

#ifndef TABELA_DE_PAGINAS_MMU_H
#define TABELA_DE_PAGINAS_MMU_H

#include <map>

typedef struct QuadroMapeamento
{
    // Número do quadro
    int numero_quadro;
    // Flag que controla se o quadro está presente.
    bool presente;
} QuadroMapeamento;

class TabelaPaginasMMU
{
public:
    // Inicializa tabela para mapeamento entre páginas e quadros
    TabelaPaginasMMU(int num_paginas, int num_quadros);
    // Retonar o número do quadro apontado pela página número num_pagina
    int get_quadro(int num_pagina);
    // Mapear a página número num_pagina para o quadro número num_quadro
    void mapear(int num_pagina, int num_quadro);
    // Desfazer o mapeamento da página
    void desmapear(int num_pagina);
    // Recriar a tabela de mapeamento
    void remapear(std::map<int, int> novo_mapeamento);
    // Retornar o número de páginas presentes na memória
    std::vector<int> get_numeros_paginas_presentes();
    // Mapeamento entre número de página e QuadroMapeamento (número do quadro e se está presente ou não na memória)
    std::map<int, QuadroMapeamento> mapeamento;

private:
    // Quantidade de páginas
    int n_paginas;
    // Quantidade de quadros
    int n_quadros;

    // Inicializar o mapeamento
    void criar(void);
};

#endif