#include <stdio.h>
#include <stdlib.h>

#include <linux/limits.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char** argv) {
	char* newPath;
	if (argc == 1) {
		chdir(getenv("HOME"));
	} else {
		char currentPath[PATH_MAX];
		newPath = getcwd(currentPath, PATH_MAX);

		strcat(newPath, "/");
		strcat(newPath, argv[1]);

		if (chdir(newPath) == -1) {
			newPath = getcwd(currentPath, PATH_MAX);
		} 
	}

	strcat(newPath, "\n");
	write(1, newPath, strlen(newPath));
   
	return 0;
}

