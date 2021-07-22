# Grupo 01 - Sistemas Operacionais

## Integrantes

- Aguimar Ribeiro Júnior
- Gabriel Souto Ferrante
- Fabíola Malta Fleury

### Módulo 03

Desenvolver um simulador  de gerenciamento de memória virtual com paginação.

**Requisitos**
 Processos são submetidos e sua execução simulada, por meio de uma série de referências a memória. 
Essas referências podem ser de leitura ou de gravação em um endereço virtual memória.
O simulador deve ler em arquivo(s) as informações sobre a "vida" do processo, contendo para cada processo, o tamanho de sua imagem e uma sequência de operações de acesso à memória principal que o respectivo processo realiza. 
O simulador também deve conter as seguintes opções de configuração de mecanismos associados à memória virtual:
- Tamanho das páginas e quadros de página
- Tamanho em bits do endereço lógico
- Tamanho da Memória física que deve ser múltiplo de tamanho da moldura (quadro)
- Tamanho máximo da memória secundária
- Tamanho da imagem de cada processo a ser executado
O gerenciador de memória deve utilizar um algoritmo de substituição de páginas, para alocar um quadro (moldura) a uma página não residente em memória em caso da memória princpal estar toda alocada.  
Os algoritmos a serem implementados:
Algoritmo de substituição de páginas LRU ou relógio. Bônus de 2 pontos para o grupo que desenvolver 2 ou mais algoritmos de substituição de páginas