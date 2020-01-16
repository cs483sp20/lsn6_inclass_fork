#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {

	pid_t pid;

	pid = fork();

	if (pid < 0) {  // error
		printf("Error creating child\n");
	} else if (pid == 0 ) {// child
        sleep(5); //enter sleep state for 5 seconds
		printf("I am the child, pid returned is %d.\n",pid);
		fflush(stdout);  // tell the os to immediately dump IO to the console
	} else { // parent
		printf("I am the parent, the pid returned is %d.\n",pid);
		printf("Parent waiting for child.\n");
        fflush(stdout);
		sleep(10);
		wait(NULL);
		printf("Child complete.\n");
	}
	return 0;
}
