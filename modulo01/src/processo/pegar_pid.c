#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	printf("PID deste processo %d\n", getpid());
	return EXIT_SUCCESS;
}