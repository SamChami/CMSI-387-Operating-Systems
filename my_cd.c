#include <stdio.h>
#include <stdlib.h>

#include <linux/limits.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char** argv) {
	if (argc == 1) {
		chdir(getenv("HOME"));
	} else {
		char currentPath[PATH_MAX];
		char* newPath = getcwd(currentPath, PATH_MAX);

		strcat(newPath, "/");
		strcat(newPath, argv[1]);

		if (chdir(newPath) == -1) {
			printf("my_cd: %s: No such file or directory\n", argv[1]);
		}
	}

    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    fprintf(stdout, "Current working dir: %s\n", cwd);
	return 0;
}

