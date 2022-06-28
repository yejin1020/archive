#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	char buf[256];
	int narg;
	pid_t pid;

	argv = argv +1;
	pid = fork();

	if( pid == 0 )
		execvp(argv[0], argv);
	else if ( pid >  0 )
		wait((int*)0);
	else
		perror("fork error");

	
}
