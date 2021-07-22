# Exemplos do comando strace

## 1. Com Timestamp
```bash
strace -T -ttt -o ../output/strace/processo_filho_strace.out ./processo_filho
```

## 2. Estatísticas
```bash
strace -c -o ../output/strace/processo_filho_strace_stats.out ./processo_filho
```