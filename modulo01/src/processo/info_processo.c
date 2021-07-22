#include <sys/resource.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int who = RUSAGE_SELF;
    struct rusage usage;

    getrusage(who, &usage);

    printf("Uso de memória = %ld\n", usage.ru_maxrss);

    return EXIT_SUCCESS;
}
