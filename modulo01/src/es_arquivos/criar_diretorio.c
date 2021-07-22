#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct stat st = {0};


int main()
{
    if (stat("/new/directory", &st) == -1) {
        mkdir("/new/directory", 0700);
    }
    return 0;
}