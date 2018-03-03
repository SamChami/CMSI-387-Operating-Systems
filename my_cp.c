#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <fcntl.h>

int main(int argc, char **argv){
    char buffer[1024];
    int files[2];
    ssize_t count;

    files[0] = open(argv[1], O_RDONLY);
    files[1] = open(argv[2], O_RDWR | O_CREAT, 0666);

    if (files[1] == -1) {
        char fileName[1024];
        strcat(fileName, argv[2]);
        if ( fileName[strlen(fileName)-1] != '/' ) { 
           strcat(fileName, "/");
        }
        char* file = strrchr(argv[1], '/');
        strcat(fileName, file + 1);
        close(files[1]);
        files[1] = open(fileName, O_RDWR | O_CREAT, 0666);
    }

    while ((count = read(files[0], buffer, sizeof(buffer))) != 0) {
        write(files[1], buffer, count);
    }

    close(files[0]);
    close(files[1]);
    return 0;
}