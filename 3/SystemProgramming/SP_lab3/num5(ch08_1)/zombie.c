#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;
	
	if ((pid = fork()) < 0) {
		perror("folk");
		exit(1);
	}
	else if (pid == 0) /* child */
		exit(0);

	//parent
	sleep(4);
	system("ps -o pid,ppid,state,tty,command");
	exit(0);
}
