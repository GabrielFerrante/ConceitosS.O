# Grupo 01 - Sistemas Operacionais

## Integrantes

- Aguimar Ribeiro Júnior
- Gabriel Souto Ferrante
- Fabíola Malta Fleury

### Módulo 02

**Produtor Consumidor**

O problema do Produtor e o Consumidor consiste em um conjunto de processos que compartilham um mesmo buffer. Os processos chamados produtores colocam informação no buffer. Os processos chamados consumidores retiram informação deste buffer. 

Trata-se de um problema clássico em sistemas operacionais, que busca exemplificar de forma clara, situações de impasses que ocorrem no gerenciamento de processos de um sistema operacional. É preciso se preocupar com acessos indevidos a certos recursos que são compartilhados entre os processos, e manter sincronismo entre os mesmos. 

Para controlarmos o acesso a essas variáveis e garantir o sincronismo nas operações, vamos utilizar semáforos. Em ciência da computação, semáforo é uma variável especial protegida (ou tipo abstrato de dados) que tem como função o controle de acesso a recursos compartilhados (por exemplo, um espaço de armazenamento) num ambiente multitarefa. Com as variáveis do tipo pthread_mutex_t da biblioteca pthreads - Posix, podemos controlar esses dados com toda segurança. 
Outro controle importante é a demanda de processamento, espera ociosa, que o programa irá gerar, pois quando um processo não está liberado para gravar ou ler, deve entrar em estado de espera para não consumir processamento, e deve ser avisado quando pode voltar a processar.



**O Problema**
O produtor insere em uma região: Ainda não houve consumo
O consumidor remove de uma região: Já foi consumida
Espera ociosa X Escalonamento do processo X Uso CPU

**A Solução**
Utilizar Exclusão mutua (semáforos)
Eliminar a espera ociosa:
Dormir (dow) /acordar (up) X Semáforos full/empty
Mutex (Mutual exclusion)


**Requisitos da Solução**

- O programa deve ter um buffer limitado, acessível a qualquer processo decorrente do processo principal;
- O programa deve ter uma fila apontando para o próximo endereço livre, a ser escrito;
- O programa deve ter uma fila apontando para o próximo endereço ocupado, a ser lido e liberado;
- O programa deve controlar as seções críticas (Compartilhamento de memória), para que não haja acessos indevidos.
- O programa deve ter a capacidade de colocar um processo em modo de espera;
- O programa deve ter a capacidade de controlar quando um processo está em espera, para poder "chamar" o mesmo;
- O programa deve controlar quantos endereços estão livres e quantos endereços estão ocupados.
Recursos para desenvolver a solução

A solução do problema deve utilizar a biblioteca pthreads, a qual possibilita a programação de forma concorrente com as funções de: controle de threads, criação de threads, suspensão de threads, execução e controle de exclusão mútua por semáforos binários, para controle da seção crítica. 

Site para Consulta

http://www.yolinux.com/TUTORIALS/LinuxTutorialPosixThreads.html


