# Exemplos do comando time usando /usr/bin/time

## 1. 
```bash
/usr/bin/time -f 'Tempo total de execução: %e segundos\nUso de CPU: %P\nTempo gasto em modo usuário: %U\nTempo gasto em modo kernel: %S\nTrocas de contexto voluntárias: %w\nTrocas de contexto involuntárias: %c' -o arquivo_output.txt ./arquivo_para_executar
```
