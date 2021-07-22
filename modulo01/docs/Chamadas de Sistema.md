# Chamadas de sistema (p. 38 Tanenbaum)


## Gerenciamento de processos

| Chamada                               | Descrição                                       |
|---------------------------------------|-------------------------------------------------|
| pid = fork( )                         | Cria um processo filho idêntico ao pai          |
| pid = waitpid(pid, &statloc, options) | Espera que um processo filho seja concluído     |
| s = execve(name, argv, environp)      | Substitui a imagem do núcleo de um processo     |
| exit(status)                          | Conclui a execução do processo e devolve status |


## Gerenciamento de arquivos

| Chamada                               | Descrição                                         |
|---------------------------------------|---------------------------------------------------|
| fd = open(file, how, ...)             | Abre um arquivo para leitura, escrita ou ambos    |
| s = close(fd)                         | Fecha um arquivo aberto                           |
| n = read(fd, buffer, nbytes)          | Lê dados a partir de um arquivo em um buffer      |
| n = write(fd, buffer, nbytes)         | Escreve dados a partir de um buffer em um arquivo |
| position = lseek(fd, offset, whence)  | Move o ponteiro do arquivo                        |
| s = stat(name, &buf)                  | Obtém informações sobre um arquivo                |

## Gerenciamento do sistema de diretório e arquivo

| Chamada                         | Descrição                                          |
|---------------------------------|----------------------------------------------------|
| s = mkdir(name, mode)           | Cria um novo diretório                             |
| s = rmdir(name)                 | Remove um diretório vazio                          |
| s = link(name1, name2)          | Cria uma nova entrada, name2, apontando para name1 |
| s = unlink(name)                | Remove uma entrada de diretório                    |
| s = mount(special, name, flag)  | Monta um sistema de arquivos                       |
| s = umount(special)             | Desmonta um sistema de arquivos                    |


## Diversas

| Chamada                   | Descrição                                           |
|---------------------------|-----------------------------------------------------|
| s = chdir(dirname)        | Altera o diretório de trabalho                      |
| s = chmod(name, mode)     | Altera os bits de proteção de um arquivo            |
| s = kill(pid, signal)     | Envia um sinal para um processo                     |
| seconds = time(&seconds)  | Obtém o tempo decorrido desde 1o de janeiro de 1970 |


### Outras chamadas (além do livro)
- getrusage: Process Statistics
- getrlimit and setrlimit: Resource Limits
- nanosleep: High-Precision Sleeping

// Gerenciamento de memória

- The mlock Family: Locking Physical
Memory
- mprotect: Setting Memory Permissions



// arquivos

- access:Testing File Permissions
- sendfile: Fast Data Transfers