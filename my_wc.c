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

	while (currentReadByte > 0) {
		for (int i = 0; i < currentReadByte; i++) {
			if (isspace(buffer[i]) && !isspace(buffer[i+1])) {
				wordCount++;
			}
			if (buffer[i] == '\n') {
				lineCount++;
			}
		}
		byteCount += currentReadByte;
		currentReadByte = read(fd, buffer, NAME_MAX);
	}

	close(fd);

	char* printedString = ("%i %i %i %s \n", lineCount, wordCount, byteCount, argv[1]);
	write(1, printedString, strlen(printedString));
	return 0;
}