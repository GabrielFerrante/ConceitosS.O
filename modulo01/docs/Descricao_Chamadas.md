## Descrição das chamadas

| Chamada de sistema   | Declaração (unistd.h)    | Descrição   |
|----------------------| -------------|-------------|
| access()             | ```int access(const char *pathname, int mode);``` | Verifica se o processo em execução tem acesso ao arquivo informado. |
| arch_prctl()         | ``` int arch_prctl(int code, unsigned long addr); int arch_prctl(int code, unsigned long *addr);``` | Configurações de estado de processo ou thread  específicos de arquitetura, por exemplo, x86-64.    |
| brk()                | ```int brk(void *addr);```  | Troca o local do *program break (PB)*, que define onde o seguimento de dados do processo termina. Incrementar o PB tem o efeito de alocar memória para o processo e decrementá-lo desaloca memória.           |
| clone()              |  ```int clone(int (*fn)(void *), void *stack, int flags, void *arg, ... /* pid_t *parent_tid, void *tls, pid_t *child_tid */ );``` | Cria um processo filho.                                                |
| close()              | ```int close(int fd);```  | Fecha o descritor de arquivo informado.                                         |
| execve()             | ```int execve(const char *pathname, char *const argv[], char *const envp[]);```  | Executa o programa informado pelo pathname.                                                   |
| exit_group()         | ```void exit_group(int status);```  | Termina todas as threads de um processo. Não somente a thread que fez a chamada.            |
| fstat()              | ```int fstat(int fd, struct stat *statbuf);``` | Retorna informações sobre o arquivo referenciado pelo descritor de arquivo informado. |
| getpid()             | ```pid_t getpid(void); ``` | Retorna o ID do processo que fez a chamada.                            |
| getrusage()          | ```int getrusage(int who, struct rusage *usage);```  | Retorna informações sobre os recursos utilizados (user cpu, system cpu, memória, trocas de contexto voluntárias e involuntárias, etc.). Pode ser do próprio processo que fez a chamada, de processos filhos ou de alguma outra thread.            |
| lseek()              | ```off_t lseek(int fd, off_t offset, int whence);```  | Reposiciona o ponteiro dentro do arquivo apontado pelo descritor oara leitura ou escrita.        |
| mkdir()              | ```int mkdir(const char *pathname, mode_t mode); ``` | Tenta criar um diretório dentro do pathname informado.                     |
| mmap()               | ```void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);```  | Mapeia arquivos ou dispositivos na memória.                            |
| mprotect()           | ```int mprotect(void *addr, size_t len, int prot);```  | Protege uma região de memória a partir do endereço e tamanho informados.            |
| munmap()             | ```int munmap(void *addr, size_t length);```  | Remove o mapeamentos da memória a partir do endereço e tamanho informados. Acessos subsequentes a esse espaço de endereçamento serão considerados como acessos inválidos de memória.            |
| openat()             | ```int openat(int dirfd, const char *pathname, int flags); int openat(int dirfd, const char *pathname, int flags, mode_t mode);```  | Abre o arquivo especificado relativo ao descritor de arquivo informado ou ao diretório corrente do processo em execução.           |
| pread64()            | ```ssize_t pread(int fd, void *buf, size_t count, off_t offset);```  | Lê de um descritor de arquivo a partir do offset informado.         |
| read()               | ```ssize_t read(int fd, void *buf, size_t count);```  | Lê de um descritor de arquivo.                                          |
| stat()               | ```int stat(const char *pathname, struct stat *statbuf);```  | Retorna informações sobre o arquivo refenciado pelo pathname informado.       |
| wait4()              | ```pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage);```  | Suspende a execução da thread atual até que o processo filho especificado mude de estado. E quando retorna, traz informações sobre o processo filho.```            |
| write()              | ```ssize_t write(int fd, const void *buf, size_t count);```  | Escreve em um descritor de arquivo.                                     |



**Fonte:** Seção 2 do utilitário *man* do linux (Exemplo: *man 2 wait4*)