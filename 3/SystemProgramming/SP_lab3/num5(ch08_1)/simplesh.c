/* simplesh.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int getargs(char *cmd, char **argv)
{
        int narg = 0;
       
	 while (*cmd) {
		//조건문 안의 문자가 나오면 문자열을 자른다
                if (*cmd == ' ' || *cmd == '\t' || *cmd == '\n')
                {	// 문자열을 널로 구분
		        *cmd = '\0';
			cmd ++;
		}
                else {
			//자른 문자열의 시작 주소를 arvg 배열에 넣는다
                        argv[narg++] = cmd++;
                        while (*cmd != '\0' && *cmd != ' ' && *cmd != '\t' && *cmd != '\n')
                                cmd++;
                }
        }
        argv[narg] = NULL;
        return narg;
}

int main()
{
	char buf[256];
	char *argv[50];
	int narg;
	pid_t pid;
int i = 0;
	while (1) {
		
		printf("shell> ");
		fgets(buf,sizeof(buf),stdin);
		narg = getargs(buf, argv);

		pid = fork();

		if( pid == 0 ){
			printf("%d",i++);
			execvp(argv[0], argv);
		}else if ( pid >  0 ){
printf("%d",i++);
			wait((int*)0);}
		else
			perror("fork error");

	}
}

