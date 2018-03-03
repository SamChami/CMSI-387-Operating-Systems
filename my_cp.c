#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <fcntl.h>

int main(int argc, char **argv)
{
    char buffer[1024];
    int files[2];
    ssize_t count;

    /* Check for insufficient parameters */

    files[0] = open(argv[1], O_RDONLY);
    files[1] = open(argv[2], O_RDWR | O_CREAT, 0666);

    if (files[1] == -1) /* Check if file opened (permissions problems ...) */
    {
        char fileName[2048];
        strcat(fileName, argv[2]);
        if ( fileName[strlen(fileName)-1] != '/' ) { 
           strcat(fileName, "/");
        }

        printf("%s\n", fileName);
        files[1] = open(fileName, O_RDWR | O_CREAT, 0666);

        printf("NO\n");

  
    }

    while ((count = read(files[0], buffer, sizeof(buffer))) != 0) {
        write(files[1], buffer, count);
    }

    close(files[0]);
    close(files[1]);
    return 0;
}