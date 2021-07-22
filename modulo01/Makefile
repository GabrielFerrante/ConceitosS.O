all: parte1 parte2

parte1: io mem proc

parte2: cpubound iobound

io:
	gcc -Wall -o bin/criar_diretorio src/es_arquivos/criar_diretorio.c
	gcc -Wall -o bin/escrever_arquivo src/es_arquivos/escrever_arquivo.c
	gcc -Wall -o bin/ler_entrada src/es_arquivos/ler_entrada.c

mem:
	gcc -Wall -o bin/alocacao_com_calloc src/memoria/alocacao_com_calloc.c
	gcc -Wall -o bin/alocacao_com_malloc src/memoria/alocacao_com_malloc.c
	gcc -Wall -o bin/redimensionar_alocacao src/memoria/redimensionar_alocacao.c

proc:
	gcc -Wall -o bin/info_processo src/processo/info_processo.c
	gcc -Wall -o bin/pegar_pid src/processo/pegar_pid.c
	gcc -Wall -o bin/processo_filho src/processo/processo_filho.c

cpubound:
	gcc -Wall -o bin/fibonacci src/cpu_bound/fibonacci.c
	gcc -Wall -o bin/multi_matrizes src/cpu_bound/multi_matrizes.c

iobound:
	gcc -Wall -o bin/manipula_arquivo src/io_bound/manipula_arquivo.c
	gcc -Wall -o bin/recebe_entradas src/io_bound/recebe_entradas.c

clean:
	rm -rf ./bin/*
	rm -rf ./output/strace/*
	rm -rf ./output/time/*

run: run1 run2

run1:
	strace -T -ttt -o ./output/strace/criar_diretorio.out ./bin/criar_diretorio
	strace -T -ttt -o ./output/strace/escrever_arquivo.out ./bin/escrever_arquivo
	strace -T -ttt -o ./output/strace/ler_entrada.out ./bin/ler_entrada
	strace -T -ttt -o ./output/strace/alocacao_com_calloc.out ./bin/alocacao_com_calloc
	strace -T -ttt -o ./output/strace/alocacao_com_malloc.out ./bin/alocacao_com_malloc
	strace -T -ttt -o ./output/strace/redimensionar_alocacao.out ./bin/redimensionar_alocacao
	strace -T -ttt -o ./output/strace/info_processo.out ./bin/info_processo
	strace -T -ttt -o ./output/strace/pegar_pid.out ./bin/pegar_pid
	strace -T -ttt -o ./output/strace/processo_filho.out ./bin/processo_filho

run2:
	/usr/bin/time -f 'Tempo total de execução: %e\nUso de CPU: %P\nTempo gasto em modo usuário: %U\nTempo gasto em modo kernel: %S\nTrocas de contexto voluntárias: %w\nTrocas de contexto involuntárias: %c' -o ./output/time/fibonacci_time.txt ./bin/fibonacci
	/usr/bin/time -f 'Tempo total de execução: %e\nUso de CPU: %P\nTempo gasto em modo usuário: %U\nTempo gasto em modo kernel: %S\nTrocas de contexto voluntárias: %w\nTrocas de contexto involuntárias: %c' -o ./output/time/multi_matrizes_time.txt ./bin/multi_matrizes
	/usr/bin/time -f 'Tempo total de execução: %e\nUso de CPU: %P\nTempo gasto em modo usuário: %U\nTempo gasto em modo kernel: %S\nTrocas de contexto voluntárias: %w\nTrocas de contexto involuntárias: %c' -o ./output/time/manipula_arquivo_time.txt ./bin/manipula_arquivo
	/usr/bin/time -f 'Tempo total de execução: %e\nUso de CPU: %P\nTempo gasto em modo usuário: %U\nTempo gasto em modo kernel: %S\nTrocas de contexto voluntárias: %w\nTrocas de contexto involuntárias: %c' -o ./output/time/recebe_entradas_time.txt ./bin/recebe_entradas

parse:
	python3 ./src/tempos_syscall.py > ./docs/Tempos_Chamadas.md

