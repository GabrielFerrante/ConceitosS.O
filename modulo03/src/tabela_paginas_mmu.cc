
/**
#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Gerenciamento de memória virtual com paginação                             #
#    Representação da tabela de páginas da MMU utilizada para mapeamento        #
#    da memória virtual para a memória física.                                  #
#################################################################################
*/

#include <iostream>
#include <vector>
#include "tabela_paginas_mmu.h"

using namespace std;

TabelaPaginasMMU::TabelaPaginasMMU(int num_paginas, int num_quadros) : n_paginas{num_paginas}, n_quadros{num_quadros}
{
  criar();
}

void TabelaPaginasMMU::criar(void)
{
  for (auto i = 0; i < n_paginas; i++)
  {
    QuadroMapeamento nova{-1, false};
    mapeamento.insert(pair<int, QuadroMapeamento>(i, nova));
  }
}

// Retorna o mapeamento correspondente
int TabelaPaginasMMU::get_quadro(int num_pagina)
{
  int quadro = -1;

  auto map_it = mapeamento.find(num_pagina);

  if (map_it == mapeamento.end())
  {
    cout << "Erro. Mapeamento de página inválido." << endl;
    exit(1);
  }

  auto &entrada_tabela = map_it->second;

  if (entrada_tabela.presente)
  {
    quadro = entrada_tabela.numero_quadro;
  }

  return quadro;
}

// Cria o mapeamento da página virtual indicada para a página física;
void TabelaPaginasMMU::mapear(int num_pagina, int num_quadro)
{
  auto map_it = mapeamento.find(num_pagina);

  auto &entrada_tabela = map_it->second;

  entrada_tabela.numero_quadro = num_quadro;
  entrada_tabela.presente = true;
}

// Desmapear página virtual
void TabelaPaginasMMU::desmapear(int num_pagina)
{
  auto map_it = mapeamento.find(num_pagina);

  auto &entrada_tabela = map_it->second;

  entrada_tabela.numero_quadro = -1;
  entrada_tabela.presente = false;
}

// Mapa de páginas presentes. Índice é o número da página
vector<int> TabelaPaginasMMU::get_numeros_paginas_presentes()
{

  vector<int> paginas_presentes;

  for (auto i = mapeamento.begin(); i != mapeamento.end(); i++)
  {

    int num_pagina = i->first;
    QuadroMapeamento &entry = i->second;

    if (entry.presente)
    {
      paginas_presentes.push_back(num_pagina);
    }
  }

  return paginas_presentes;
}

// Remapear tabela de páginas na MMU
void TabelaPaginasMMU::remapear(map<int, int> novo_mapeamento)
{
    map<int, QuadroMapeamento> remapeamento{};

      for(auto b = novo_mapeamento.begin(); b != novo_mapeamento.end(); b++) {
        QuadroMapeamento qmap = mapeamento[b->first];
        remapeamento.insert(pair<int, QuadroMapeamento>{b->second, qmap});
    }

  this->mapeamento = remapeamento;
}