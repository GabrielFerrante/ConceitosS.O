
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{

  //abrir arquivo para escrita somente, criar se não existir, truncar o comprimento para 0
  int fd = open("./output/teste.txt", O_WRONLY | O_CREAT | O_TRUNC);
  // Se o retorno do arquivo for -1
  if (fd < 0)
  {
    perror("r1");
    exit(1);
  }

  //Operação de escrita, retorna o número de bytes escritos
  /*retorna 0 ao chegar ao final do arquivo
    retorna -1 em caso de erro
    return -1 na interrupção do sinal*/
  //Parametros de write - descritor do arquivo, o buffer de conteudo, o tamanho do buffer
  int sz = write(fd, "Disciplina de sistemas operacionais\n", strlen("Disciplina de sistemas operacionais\n"));

  printf("Chamada de escrita(%d, \"Disciplina de sistemas operacionais\\n\", %zu). Retornou %d\n", fd, strlen("Disciplina de sistemas operacionais\n"), sz);

  //Fechando arquivo
  close(fd);
}