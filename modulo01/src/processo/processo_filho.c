#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
  pid_t pid = fork();

  if (pid == 0)
  {
    printf("Processo Filho => PPID: %d PID: %d\n", getppid(), getpid());
    exit(EXIT_SUCCESS);
  }
  else if (pid > 0)
  {
    printf("Processo Pai => PID: %d\n", getpid());
    printf("Esperando pelo fim do processo filho.\n");
    wait(NULL);
    printf("Processo filho finalizado.\n");
  }
  else
  {
    printf("Não foi possível criar um processo filho.\n");
  }

  return EXIT_SUCCESS;
}