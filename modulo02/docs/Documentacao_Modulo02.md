# Grupo 1 - Módulo 2 - SSC5723

[TOC]
## Integrantes

| Aluno(a)  | Número USP |
|----------------------| -------------|
| Aguimar Ribeiro Júnior | 11516281 |
| Fabíola Malta Fleury | 12501766 |
| Gabriel Souto Ferrante | 12620303 |

## Estrutura do Projeto

### Diretórios

![Estrutura de diretórios](img/dir_modulo2.png)

| Diretório  | Descrição |
|----------------------| -------------|
| ./bin             | Arquivos binários |
| ./docs             | Documentações |
| ./output            | Saída exemplo do programa Produtor/Consumidor |
| ./src             | Códigos-fonte |


### Descrição dos Arquivos de Códigos-Fonte

| Arquivo | Descrição |
|----------------------| -------------|
| fila.c | Implementação da estrutura de dados fila com lista encadeada. |
| buffer.c | Implementação de buffer com tamanho limitado utilizando a fila implementada. |
| buffer_test.c | Arquivo para testes do buffer implementado. |
| msleep.c | Implementação da função msleep(), equivalente a sleep(), porém o parâmetro é em milissegundos. |
| opcoes.c | Implementação dos parâmetros que são aceitos via linha de comando do Produtor/Consumidor. |
| produtor_consumidor.c | Implementação do Produtor/Consumidor utilizando semáforos. |

### Compilação e Execução

1. Compilação do programa Produtor/Consumidor

        make

2. Execução do programa

        make run
    
    ou

        ./bin/produtor_consumidor


### Configurações via Linha de Comando

Foi desenvolvida a possibilidade de passar configurações para o programa via linha de comando, são eles:

```
./bin/produtor_consumidor --help
Usage: produtor_consumidor [OPTION...] 
Produtor/Consumidor - Com utilização de threads e semáforos.

  -b, --bsize=TAM            Tamanho do buffer (default: 15)
  -c, --ncons=NUM            Número de consumidores (default: 8)
  -l, --scons=MSEG           Tempo sleep (milissegundos) dos consumidores (para
                             debug apenas) (default: 1000)
  -p, --nprod=NUM            Número de produtores (default: 25)
  -s, --sprod=MSEG           Tempo sleep (milissegundos) dos produtores (para
                             debug apenas) (default: 1000)
  -t, --time=SEG             Tempo máximo (segundos) de execução do programa
                             (default: 30)
  -?, --help                 Give this help list
      --usage                Give a short usage message
  -V, --version              Print program version

Mandatory or optional arguments to long options are also mandatory or optional
```

Os valores de configuração default para os parâmetros são:

| Parâmetro  | Valor |
|----------------------| -------------|
| -b, --bsize             | 15 |
| -c, --ncons            | 8 |
| -l, --scons            | 1000 |
| -p, --nprod            | 25 |
| -s, --sprod | 1000 |
| -t, --time | 30 |

## Exemplo de saída

```
./bin/produtor_consumidor -b 5 -p 3 -c 5 -t 10 -s 500 -l 500
```

<pre>
Parâmetros:
     Tamanho do Buffer = 5
     Número de Produtores = 3
     Número de Consumidores = 5
     Sleep para Produtores = 500ms
     Sleep para Consumidores = 500ms
     Tempo (máx) de execução = 10s

[Produtor ID: 140037734598400] Item produzido: 1

Tamanho do Buffer: 5 
Slots disponíveis: 4 
Slots ocupados: 1 

[Produtor ID: 140037734598400] Item produzido: 2

Tamanho do Buffer: 5 
Slots disponíveis: 3 
Slots ocupados: 2 

[Produtor ID: 140037734598400] Item produzido: 3

Tamanho do Buffer: 5 
Slots disponíveis: 2 
Slots ocupados: 3 

[Produtor ID: 140037726205696] Item produzido: 4

Tamanho do Buffer: 5 
Slots disponíveis: 1 
Slots ocupados: 4 

[Consumidor ID: 140037709420288] Item consumido: 1

Tamanho do Buffer: 5 
Slots disponíveis: 2 
Slots ocupados: 3 

[Produtor ID: 140037717812992] Item produzido: 5

Tamanho do Buffer: 5 
Slots disponíveis: 1 
Slots ocupados: 4 

[Consumidor ID: 140037610010368] Item consumido: 2

Tamanho do Buffer: 5 
Slots disponíveis: 2 
Slots ocupados: 3 

[Consumidor ID: 140037601617664] Item consumido: 3

Tamanho do Buffer: 5 
Slots disponíveis: 3 
Slots ocupados: 2 

[Consumidor ID: 140037701027584] Item consumido: 4

Tamanho do Buffer: 5 
Slots disponíveis: 4 
Slots ocupados: 1 

[Produtor ID: 140037734598400] Item produzido: 6

Tamanho do Buffer: 5 
Slots disponíveis: 3 
Slots ocupados: 2 

[Produtor ID: 140037734598400] Item produzido: 7

Tamanho do Buffer: 5 
Slots disponíveis: 2 
Slots ocupados: 3 

[Produtor ID: 140037726205696] Item produzido: 8

Tamanho do Buffer: 5 
Slots disponíveis: 1 
Slots ocupados: 4 

[Produtor ID: 140037717812992] Item produzido: 9

Tamanho do Buffer: 5 
Slots disponíveis: 0 
Slots ocupados: 5 

[Consumidor ID: 140037692634880] Item consumido: 5

Tamanho do Buffer: 5 
Slots disponíveis: 1 
Slots ocupados: 4 

[Consumidor ID: 140037709420288] Item consumido: 6

Tamanho do Buffer: 5 
Slots disponíveis: 2 
Slots ocupados: 3 

[Produtor ID: 140037726205696] Item produzido: 10

Tamanho do Buffer: 5 
Slots disponíveis: 1 
Slots ocupados: 4 

[Consumidor ID: 140037601617664] Item consumido: 7

Tamanho do Buffer: 5 
Slots disponíveis: 2 
Slots ocupados: 3 

[Consumidor ID: 140037701027584] Item consumido: 8

Tamanho do Buffer: 5 
Slots disponíveis: 3 
Slots ocupados: 2 

[Produtor ID: 140037734598400] Item produzido: 11

Tamanho do Buffer: 5 
Slots disponíveis: 2 
Slots ocupados: 3 

[Consumidor ID: 140037610010368] Item consumido: 9

Tamanho do Buffer: 5 
Slots disponíveis: 3 
Slots ocupados: 2 
</pre>