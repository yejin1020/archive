#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int alarm_flag = 0;

void alarm_handler(int sig)
{
	printf("Received a alarm signal.\n");
	alarm_flag = 1;
}

int main()
{

	struct sigaction act;
	act.sa_handler = alarm_handler;// 알람 시그널 핸들러 설정
	sigaction(SIGALRM, &act, NULL);

	alarm (5);/* Turn alarm on.*/ // 5초 뒤에 알람 핸들러 실행

	pause(); /* pause */

	if (alarm_flag)
		printf("Passed a 5 secs.\n");
	
}
