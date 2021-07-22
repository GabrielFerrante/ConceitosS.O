#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    for (int i = 0; i < 100000; i++)
    {
        char text[]={"texto a ser escrito no arquivo\n"};
        int fp = open ("nomedoarquivo.txt", O_RDWR|O_CREAT, 0777);
        pwrite(fp, text, strlen(text), 14);
        close (fp);
        remove("nomedoarquivo.txt");
    }
    

}
