//
// Created by rios0rios0 on 08/03/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* for fork */
#include <sys/types.h> /* for pid_t */
#include <sys/wait.h> /* for wait */

int main() {
	/*Spawn a child to run the program.*/
	pid_t pid = fork();
	if (pid == 0) { /* child process */
		static char *argv[] = {"echo", "Foo is my name.", NULL};
		execv("/bin/echo", argv);
		exit(127); /* only if execv fails */
	} else { /* pid!=0; parent process */
		waitpid(pid, 0, 0); /* wait for child to exit */
	}
	return 0;
}