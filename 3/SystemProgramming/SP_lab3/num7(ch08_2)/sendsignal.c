/* sendsignal.c */
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int i = 0;
void p_handler (int), c_handler (int);

int main()
{
	pid_t pid, ppid;
	struct sigaction act;

	pid = fork();
	if (pid == 0 ){
		act.sa_handler = c_handler; // 자식 시그널 처리 핸들러
		sigaction (SIGUSR1, &act, NULL);
		ppid = getppid(); /* get parent's process id. */

		while (1) {
			sleep (1);
			kill (ppid, SIGUSR1); // 부모에게 시그널 전달
			pause();
		}
	} 
	else if (pid > 0) {

		act.sa_handler = p_handler;// 부모 시그널 핸들러
		sigaction(SIGUSR1, &act, NULL);
		while (1) {
			pause();
			sleep (1);
			kill (pid, SIGUSR1); // 자식에게 시그널 전송
		}
	}
	 else
		perror ("Error");
}

void p_handler(int signo)
{
	printf("Parent handler: call %d times.\n", ++i);
}

void c_handler(int signo)
{
	printf("Child handler: call %d times.\n", ++i);
}
