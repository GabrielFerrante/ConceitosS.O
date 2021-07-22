# Chamadas de sistema e tempos de execução

## Tempo das chamadas

### Arquivo: ./output/strace/escrever_arquivo.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      354 |
| brk()                |                       22 |
| arch_prctl()         |                       22 |
| access()             |                       30 |
| openat()             |                       30 |
| fstat()              |                       23 |
| mmap()               |                       26 |
| close()              |                       21 |
| openat()             |                       29 |
| read()               |                       36 |
| pread64()            |                       23 |
| pread64()            |                       22 |
| pread64()            |                       22 |
| fstat()              |                       22 |
| mmap()               |                       24 |
| pread64()            |                       22 |
| pread64()            |                       22 |
| pread64()            |                       22 |
| mmap()               |                       26 |
| mprotect()           |                       28 |
| mmap()               |                       30 |
| mmap()               |                       26 |
| mmap()               |                       27 |
| mmap()               |                       27 |
| close()              |                       23 |
| arch_prctl()         |                       21 |
| mprotect()           |                       30 |
| mprotect()           |                       27 |
| mprotect()           |                       28 |
| munmap()             |                       39 |
| openat()             |                       69 |
| write()              |                       48 |
| fstat()              |                       23 |
| brk()                |                       21 |
| brk()                |                       24 |
| write()              |                      100 |
| close()              |                       29 |
| exit_group()         |                       29 |
| exit_group()         |                       29 |

### Arquivo: ./output/strace/info_processo.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      250 |
| brk()                |                       18 |
| arch_prctl()         |                       19 |
| access()             |                       25 |
| openat()             |                       24 |
| fstat()              |                       19 |
| mmap()               |                       21 |
| close()              |                       18 |
| openat()             |                       23 |
| read()               |                       19 |
| pread64()            |                       18 |
| pread64()            |                       18 |
| pread64()            |                       18 |
| fstat()              |                       18 |
| mmap()               |                       20 |
| pread64()            |                       19 |
| pread64()            |                       40 |
| pread64()            |                       19 |
| mmap()               |                       21 |
| mprotect()           |                       25 |
| mmap()               |                       24 |
| mmap()               |                       21 |
| mmap()               |                       22 |
| mmap()               |                       21 |
| close()              |                       18 |
| arch_prctl()         |                       18 |
| mprotect()           |                       24 |
| mprotect()           |                       22 |
| mprotect()           |                       21 |
| munmap()             |                       28 |
| getrusage()          |                       18 |
| fstat()              |                       17 |
| brk()                |                       16 |
| brk()                |                       18 |
| write()              |                       57 |
| exit_group()         |                       57 |
| exit_group()         |                       57 |

### Arquivo: ./output/strace/criar_diretorio.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      404 |
| brk()                |                       27 |
| arch_prctl()         |                       24 |
| access()             |                       33 |
| openat()             |                       32 |
| fstat()              |                       24 |
| mmap()               |                       28 |
| close()              |                       24 |
| openat()             |                       30 |
| read()               |                       25 |
| pread64()            |                       24 |
| pread64()            |                       25 |
| pread64()            |                       25 |
| fstat()              |                       23 |
| mmap()               |                       26 |
| pread64()            |                       24 |
| pread64()            |                       24 |
| pread64()            |                       24 |
| mmap()               |                       27 |
| mprotect()           |                       33 |
| mmap()               |                       33 |
| mmap()               |                       28 |
| mmap()               |                       29 |
| mmap()               |                       28 |
| close()              |                       23 |
| arch_prctl()         |                       41 |
| mprotect()           |                       31 |
| mprotect()           |                       29 |
| mprotect()           |                       30 |
| munmap()             |                       41 |
| stat()               |                       76 |
| mkdir()              |                       25 |
| exit_group()         |                       25 |
| exit_group()         |                       25 |

### Arquivo: ./output/strace/pegar_pidorio.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      270 |
| brk()                |                       18 |
| arch_prctl()         |                       17 |
| access()             |                       22 |
| openat()             |                       21 |
| fstat()              |                       17 |
| mmap()               |                       18 |
| close()              |                       16 |
| openat()             |                       20 |
| read()               |                       18 |
| pread64()            |                       17 |
| pread64()            |                       17 |
| pread64()            |                       17 |
| fstat()              |                       16 |
| mmap()               |                       18 |
| pread64()            |                       17 |
| pread64()            |                       16 |
| pread64()            |                       17 |
| mmap()               |                       19 |
| mprotect()           |                       25 |
| mmap()               |                       20 |
| mmap()               |                       19 |
| mmap()               |                       19 |
| mmap()               |                       18 |
| close()              |                       17 |
| arch_prctl()         |                       16 |
| mprotect()           |                       20 |
| mprotect()           |                       18 |
| mprotect()           |                       19 |
| munmap()             |                       24 |
| getpid()             |                       16 |
| fstat()              |                       17 |
| brk()                |                       12 |
| brk()                |                       17 |
| write()              |                       52 |
| exit_group()         |                       52 |
| exit_group()         |                       52 |

### Arquivo: ./output/strace/alocacao_com_malloc.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      272 |
| brk()                |                       21 |
| arch_prctl()         |                       20 |
| access()             |                       27 |
| openat()             |                       26 |
| fstat()              |                       21 |
| mmap()               |                       23 |
| close()              |                       20 |
| openat()             |                       25 |
| read()               |                       23 |
| pread64()            |                       21 |
| pread64()            |                       20 |
| pread64()            |                       20 |
| fstat()              |                       20 |
| mmap()               |                       21 |
| pread64()            |                       20 |
| pread64()            |                       20 |
| pread64()            |                       20 |
| mmap()               |                       22 |
| mprotect()           |                       27 |
| mmap()               |                       25 |
| mmap()               |                       23 |
| mmap()               |                       24 |
| mmap()               |                       23 |
| close()              |                       20 |
| arch_prctl()         |                       20 |
| mprotect()           |                      103 |
| mprotect()           |                       45 |
| mprotect()           |                       34 |
| munmap()             |                       41 |
| brk()                |                       24 |
| brk()                |                       23 |
| fstat()              |                       25 |
| write()              |                      203 |
| exit_group()         |                      203 |
| exit_group()         |                      203 |

### Arquivo: ./output/strace/processo_filho.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      311 |
| brk()                |                       45 |
| arch_prctl()         |                       23 |
| access()             |                       29 |
| openat()             |                       28 |
| fstat()              |                       19 |
| mmap()               |                       22 |
| close()              |                       18 |
| openat()             |                       22 |
| read()               |                       20 |
| pread64()            |                       18 |
| pread64()            |                       18 |
| pread64()            |                       18 |
| fstat()              |                       18 |
| mmap()               |                       19 |
| pread64()            |                       18 |
| pread64()            |                       18 |
| pread64()            |                       18 |
| mmap()               |                       20 |
| mprotect()           |                       24 |
| mmap()               |                       24 |
| mmap()               |                       21 |
| mmap()               |                       61 |
| mmap()               |                       27 |
| close()              |                       18 |
| arch_prctl()         |                       18 |
| mprotect()           |                       23 |
| mprotect()           |                       21 |
| mprotect()           |                       22 |
| munmap()             |                       30 |
| clone()              |                       85 |
| getpid()             |                       24 |
| fstat()              |                       24 |
| brk()                |                       21 |
| brk()                |                       23 |
| write()              |                       34 |
| write()              |                       28 |
| wait4()              |                      230 |
| wait4()              |                      230 |
| write()              |                       53 |
| exit_group()         |                       53 |
| exit_group()         |                       53 |

### Arquivo: ./output/strace/ler_entrada.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      266 |
| brk()                |                       16 |
| arch_prctl()         |                       16 |
| access()             |                       22 |
| openat()             |                       22 |
| fstat()              |                       16 |
| mmap()               |                       18 |
| close()              |                       15 |
| openat()             |                       20 |
| read()               |                       17 |
| pread64()            |                       16 |
| pread64()            |                       16 |
| pread64()            |                       16 |
| fstat()              |                       15 |
| mmap()               |                       18 |
| pread64()            |                       16 |
| pread64()            |                       15 |
| pread64()            |                       16 |
| mmap()               |                       25 |
| mprotect()           |                       24 |
| mmap()               |                       22 |
| mmap()               |                       19 |
| mmap()               |                       19 |
| mmap()               |                       42 |
| close()              |                       16 |
| arch_prctl()         |                       16 |
| mprotect()           |                       20 |
| mprotect()           |                       19 |
| mprotect()           |                       20 |
| munmap()             |                       27 |
| fstat()              |                       17 |
| brk()                |                       15 |
| brk()                |                       17 |
| fstat()              |                       15 |
| write()              |                       73 |
| read()               |                  2079035 |
| write()              |                      263 |
| lseek()              |                       82 |
| exit_group()         |                       82 |
| exit_group()         |                       82 |

### Arquivo: ./output/strace/alocacao_com_calloc.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      354 |
| brk()                |                       26 |
| arch_prctl()         |                       48 |
| access()             |                       39 |
| openat()             |                       26 |
| fstat()              |                       20 |
| mmap()               |                       22 |
| close()              |                       19 |
| openat()             |                       25 |
| read()               |                       21 |
| pread64()            |                       20 |
| pread64()            |                       19 |
| pread64()            |                       19 |
| fstat()              |                       19 |
| mmap()               |                       21 |
| pread64()            |                       20 |
| pread64()            |                       20 |
| pread64()            |                       20 |
| mmap()               |                       22 |
| mprotect()           |                       25 |
| mmap()               |                       26 |
| mmap()               |                       23 |
| mmap()               |                       24 |
| mmap()               |                       23 |
| close()              |                       19 |
| arch_prctl()         |                       20 |
| mprotect()           |                       25 |
| mprotect()           |                       24 |
| mprotect()           |                       25 |
| munmap()             |                       33 |
| brk()                |                       20 |
| brk()                |                       21 |
| exit_group()         |                       21 |
| exit_group()         |                       21 |

### Arquivo: ./output/strace/redimensionar_alocacao.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      488 |
| brk()                |                       28 |
| arch_prctl()         |                       27 |
| access()             |                       40 |
| openat()             |                       40 |
| fstat()              |                       29 |
| mmap()               |                       32 |
| close()              |                       27 |
| openat()             |                       36 |
| read()               |                       30 |
| pread64()            |                       28 |
| pread64()            |                       46 |
| pread64()            |                       29 |
| fstat()              |                       27 |
| mmap()               |                       30 |
| pread64()            |                       29 |
| pread64()            |                       27 |
| pread64()            |                       27 |
| mmap()               |                       32 |
| mprotect()           |                       37 |
| mmap()               |                       40 |
| mmap()               |                       34 |
| mmap()               |                       35 |
| mmap()               |                       34 |
| close()              |                       29 |
| arch_prctl()         |                       27 |
| mprotect()           |                       60 |
| mprotect()           |                       22 |
| mprotect()           |                       23 |
| munmap()             |                       30 |
| brk()                |                       18 |
| brk()                |                       19 |
| fstat()              |                       19 |
| write()              |                       25 |
| write()              |                       80 |
| write()              |                       28 |
| write()              |                       27 |
| write()              |                       27 |
| write()              |                       26 |
| write()              |                       27 |
| write()              |                       57 |
| write()              |                       46 |
| write()              |                       27 |
| write()              |                       26 |
| write()              |                       27 |
| write()              |                       25 |
| write()              |                       26 |
| write()              |                       25 |
| write()              |                       58 |
| write()              |                       45 |
| write()              |                       26 |
| write()              |                       26 |
| write()              |                       26 |
| write()              |                       26 |
| write()              |                       26 |
| write()              |                       26 |
| write()              |                       25 |
| write()              |                       26 |
| write()              |                       25 |
| write()              |                       26 |
| write()              |                       25 |
| write()              |                       26 |
| write()              |                       23 |
| exit_group()         |                       23 |
| exit_group()         |                       23 |

### Arquivo: ./output/strace/processo/processo_filho_strace.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      215 |
| brk()                |                       27 |
| arch_prctl()         |                       76 |
| access()             |                       12 |
| openat()             |                        8 |
| stat()               |                        5 |
| openat()             |                        6 |
| stat()               |                        5 |
| openat()             |                        5 |
| stat()               |                        5 |
| openat()             |                        5 |
| stat()               |                        5 |
| openat()             |                        5 |
| stat()               |                        5 |
| openat()             |                        5 |
| stat()               |                        5 |
| openat()             |                       19 |
| stat()               |                        5 |
| openat()             |                        6 |
| stat()               |                        7 |
| openat()             |                        9 |
| fstat()              |                        6 |
| mmap()               |                        8 |
| close()              |                        5 |
| openat()             |                        7 |
| read()               |                       19 |
| pread64()            |                        5 |
| pread64()            |                        5 |
| pread64()            |                       39 |
| fstat()              |                       84 |
| mmap()               |                       12 |
| pread64()            |                       12 |
| pread64()            |                        6 |
| pread64()            |                       24 |
| mmap()               |                        8 |
| mprotect()           |                       26 |
| mmap()               |                        9 |
| mmap()               |                        7 |
| mmap()               |                        7 |
| mmap()               |                        6 |
| close()              |                        4 |
| arch_prctl()         |                        4 |
| mprotect()           |                        6 |
| mprotect()           |                        6 |
| mprotect()           |                       26 |
| munmap()             |                       12 |
| clone()              |                       67 |
| getpid()             |                        7 |
| fstat()              |                       27 |
| brk()                |                        8 |
| brk()                |                        8 |
| brk()                |                        7 |
| write()              |                        8 |
| write()              |                        6 |
| wait4()              |                        8 |
| write()              |                        6 |
| exit_group()         |                        6 |
| exit_group()         |                        6 |

### Arquivo: ./output/strace/processo/info_processo_strace.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      688 |
| brk()                |                       38 |
| access()             |                      239 |
| access()             |                       49 |
| openat()             |                       44 |
| fstat()              |                       33 |
| mmap()               |                       71 |
| close()              |                       25 |
| access()             |                       33 |
| openat()             |                       39 |
| read()               |                       29 |
| fstat()              |                       27 |
| mmap()               |                       40 |
| mmap()               |                       44 |
| mprotect()           |                       57 |
| mmap()               |                       44 |
| mmap()               |                       34 |
| close()              |                       25 |
| arch_prctl()         |                       26 |
| mprotect()           |                       40 |
| mprotect()           |                       42 |
| mprotect()           |                       70 |
| munmap()             |                      114 |
| getrusage()          |                       54 |
| exit_group()         |                       54 |
| exit_group()         |                       54 |

### Arquivo: ./output/strace/processo/pegar_pid_strace.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      446 |
| brk()                |                       12 |
| arch_prctl()         |                       13 |
| access()             |                       20 |
| openat()             |                       17 |
| fstat()              |                       11 |
| mmap()               |                       16 |
| close()              |                        9 |
| openat()             |                       17 |
| read()               |                       10 |
| pread64()            |                       10 |
| pread64()            |                      124 |
| pread64()            |                       26 |
| fstat()              |                       11 |
| mmap()               |                       14 |
| pread64()            |                       10 |
| pread64()            |                       11 |
| pread64()            |                       24 |
| mmap()               |                       16 |
| mprotect()           |                       18 |
| mmap()               |                       20 |
| mmap()               |                       14 |
| mmap()               |                       15 |
| mmap()               |                       47 |
| close()              |                       11 |
| arch_prctl()         |                        9 |
| mprotect()           |                       17 |
| mprotect()           |                       13 |
| mprotect()           |                       15 |
| munmap()             |                       28 |
| getpid()             |                        9 |
| fstat()              |                       12 |
| brk()                |                        9 |
| brk()                |                       11 |
| write()              |                       23 |
| exit_group()         |                       23 |
| exit_group()         |                       23 |

### Arquivo: ./output/strace/memoria/redimensionar_alocacao_strace.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      303 |
| brk()                |                        8 |
| arch_prctl()         |                       11 |
| access()             |                       48 |
| openat()             |                       22 |
| fstat()              |                       11 |
| mmap()               |                       12 |
| close()              |                        7 |
| openat()             |                       14 |
| read()               |                       41 |
| pread64()            |                       10 |
| pread64()            |                        8 |
| pread64()            |                       11 |
| fstat()              |                      155 |
| mmap()               |                       17 |
| pread64()            |                       11 |
| pread64()            |                       13 |
| pread64()            |                       11 |
| mmap()               |                       16 |
| mprotect()           |                       23 |
| mmap()               |                       23 |
| mmap()               |                       18 |
| mmap()               |                       17 |
| mmap()               |                      179 |
| close()              |                       11 |
| arch_prctl()         |                       11 |
| mprotect()           |                       16 |
| mprotect()           |                       13 |
| mprotect()           |                       26 |
| munmap()             |                       28 |
| brk()                |                        9 |
| brk()                |                       11 |
| fstat()              |                       12 |
| write()              |                       25 |
| write()              |                       12 |
| write()              |                       19 |
| write()              |                       25 |
| write()              |                      170 |
| write()              |                       20 |
| write()              |                       20 |
| write()              |                      418 |
| write()              |                       18 |
| write()              |                     2049 |
| write()              |                      170 |
| write()              |                      155 |
| write()              |                       26 |
| write()              |                      492 |
| write()              |                       42 |
| write()              |                      211 |
| write()              |                      126 |
| write()              |                      225 |
| write()              |                       31 |
| write()              |                       53 |
| write()              |                       16 |
| write()              |                       19 |
| write()              |                       91 |
| write()              |                      105 |
| write()              |                       23 |
| write()              |                       20 |
| write()              |                       18 |
| write()              |                      238 |
| write()              |                      261 |
| write()              |                      167 |
| exit_group()         |                      167 |
| exit_group()         |                      167 |

### Arquivo: ./output/strace/memoria/alocacao_memoria_2_strace.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      570 |
| brk()                |                       29 |
| access()             |                       44 |
| access()             |                       37 |
| openat()             |                       39 |
| fstat()              |                       25 |
| mmap()               |                       33 |
| close()              |                       23 |
| access()             |                       33 |
| openat()             |                       39 |
| read()               |                       27 |
| fstat()              |                       24 |
| mmap()               |                       30 |
| mmap()               |                       34 |
| mprotect()           |                       45 |
| mmap()               |                       43 |
| mmap()               |                       41 |
| close()              |                       23 |
| arch_prctl()         |                       24 |
| mprotect()           |                       38 |
| mprotect()           |                       30 |
| mprotect()           |                       34 |
| munmap()             |                       74 |
| brk()                |                       26 |
| brk()                |                       27 |
| exit_group()         |                       27 |
| exit_group()         |                       27 |

### Arquivo: ./output/strace/memoria/alocacao_memoria_strace.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      161 |
| brk()                |                        6 |
| arch_prctl()         |                        6 |
| access()             |                        9 |
| openat()             |                       22 |
| stat()               |                        6 |
| openat()             |                        7 |
| stat()               |                        6 |
| openat()             |                        6 |
| stat()               |                        6 |
| openat()             |                        6 |
| stat()               |                        6 |
| openat()             |                        6 |
| stat()               |                        6 |
| openat()             |                        6 |
| stat()               |                        6 |
| openat()             |                        6 |
| stat()               |                        6 |
| openat()             |                        6 |
| stat()               |                        6 |
| openat()             |                        8 |
| fstat()              |                        6 |
| mmap()               |                        7 |
| close()              |                        6 |
| openat()             |                       10 |
| read()               |                        6 |
| pread64()            |                        5 |
| pread64()            |                       18 |
| pread64()            |                        5 |
| fstat()              |                        6 |
| mmap()               |                       22 |
| pread64()            |                        6 |
| pread64()            |                        8 |
| pread64()            |                        7 |
| mmap()               |                        8 |
| mprotect()           |                       23 |
| mmap()               |                       10 |
| mmap()               |                        7 |
| mmap()               |                        8 |
| mmap()               |                        7 |
| close()              |                        5 |
| arch_prctl()         |                        5 |
| mprotect()           |                        7 |
| mprotect()           |                        7 |
| mprotect()           |                        7 |
| munmap()             |                       10 |
| brk()                |                        6 |
| brk()                |                        6 |
| fstat()              |                        6 |
| write()              |                       40 |
| exit_group()         |                       40 |
| exit_group()         |                       40 |

### Arquivo: ./output/strace/es_arquivos/ler_entrada_strace.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      331 |
| brk()                |                      100 |
| arch_prctl()         |                        7 |
| access()             |                       16 |
| openat()             |                        9 |
| stat()               |                        6 |
| openat()             |                        7 |
| stat()               |                        6 |
| openat()             |                        6 |
| stat()               |                        5 |
| openat()             |                        6 |
| stat()               |                        5 |
| openat()             |                        5 |
| stat()               |                        5 |
| openat()             |                        5 |
| stat()               |                        5 |
| openat()             |                        6 |
| stat()               |                        5 |
| openat()             |                        6 |
| stat()               |                        6 |
| openat()             |                        7 |
| fstat()              |                        5 |
| mmap()               |                        7 |
| close()              |                        5 |
| openat()             |                        7 |
| read()               |                        6 |
| pread64()            |                        5 |
| pread64()            |                        5 |
| pread64()            |                        5 |
| fstat()              |                        5 |
| mmap()               |                        5 |
| pread64()            |                        5 |
| pread64()            |                        5 |
| pread64()            |                        5 |
| mmap()               |                        7 |
| mprotect()           |                       10 |
| mmap()               |                        9 |
| mmap()               |                        7 |
| mmap()               |                        8 |
| mmap()               |                        7 |
| close()              |                        5 |
| arch_prctl()         |                        5 |
| mprotect()           |                       17 |
| mprotect()           |                       10 |
| mprotect()           |                       10 |
| munmap()             |                       35 |
| fstat()              |                        7 |
| brk()                |                        6 |
| brk()                |                        7 |
| fstat()              |                        6 |
| write()              |                       10 |
| read()               |                  1965007 |
| write()              |                      102 |
| lseek()              |                       12 |
| exit_group()         |                       12 |
| exit_group()         |                       12 |

### Arquivo: ./output/strace/es_arquivos/criar_diretorio_strace.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      825 |
| brk()                |                      127 |
| access()             |                       85 |
| access()             |                      139 |
| openat()             |                       99 |
| fstat()              |                       32 |
| mmap()               |                      111 |
| close()              |                       31 |
| access()             |                       42 |
| openat()             |                      101 |
| read()               |                       28 |
| fstat()              |                       25 |
| mmap()               |                       29 |
| mmap()               |                       31 |
| mprotect()           |                       43 |
| mmap()               |                       39 |
| mmap()               |                       29 |
| close()              |                       20 |
| arch_prctl()         |                       20 |
| mprotect()           |                       35 |
| mprotect()           |                       28 |
| mprotect()           |                       32 |
| munmap()             |                       71 |
| stat()               |                       48 |
| mkdir()              |                       25 |
| exit_group()         |                       25 |
| exit_group()         |                       25 |

### Arquivo: ./output/strace/es_arquivos/write_file_strace.out

| Chamada de sistema   |   Tempo de execução (µs) |
|----------------------|--------------------------|
| execve()             |                      245 |
| brk()                |                        9 |
| arch_prctl()         |                        9 |
| access()             |                       14 |
| openat()             |                       13 |
| fstat()              |                        7 |
| mmap()               |                       10 |
| close()              |                       13 |
| openat()             |                       98 |
| read()               |                        7 |
| pread64()            |                      776 |
| pread64()            |                       12 |
| pread64()            |                        9 |
| fstat()              |                       12 |
| mmap()               |                       14 |
| pread64()            |                        9 |
| pread64()            |                        8 |
| pread64()            |                      101 |
| mmap()               |                      138 |
| mprotect()           |                       15 |
| mmap()               |                       15 |
| mmap()               |                       10 |
| mmap()               |                       11 |
| mmap()               |                       10 |
| close()              |                        7 |
| arch_prctl()         |                        6 |
| mprotect()           |                       10 |
| mprotect()           |                        9 |
| mprotect()           |                       11 |
| munmap()             |                       20 |
| openat()             |                      109 |
| write()              |                       43 |
| fstat()              |                       11 |
| brk()                |                     1565 |
| brk()                |                       12 |
| write()              |                       15 |
| close()              |                      219 |
| exit_group()         |                      219 |
| exit_group()         |                      219 |
