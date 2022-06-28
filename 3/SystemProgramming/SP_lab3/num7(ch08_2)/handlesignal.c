#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// 인터럽트키가 눌러지면 실행
void handler(int signo)
{
	printf("handler: signo=%d\n", signo);
}

int main()
{
	struct sigaction act;
	int i = 0;
	act.sa_handler = handler;
	sigfillset(&(act.sa_mask));

	// 시그널 핸들러에게 handler 함수 지정
	sigaction(SIGINT, &act, NULL);
	printf("SIGINT on\n");

	while(1) {
		sleep(1);
		printf("sleep for %d sec(s).\n", ++i);
	}
}

