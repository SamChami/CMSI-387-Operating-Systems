#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

//Number of lines, Number of words, Number of bytes

int main(int argc, char** argv) {
	const int NAME_MAX = 1024;
	int fd = open(argv[1], O_RDONLY, 0000);
	char buffer[NAME_MAX];

	int currentReadByte = read(fd, buffer, NAME_MAX);
	int lineCount = 0; 
	int wordCount = 0;
	int byteCount = 0;

}