#include <stdio.h>
#include <termios.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>


int main(void)
{
	int fd;
	int nread, cnt=0, errcnt=0;
	char ch;
	char *text1[] = { "The magic thing is that you can change it.\n",
	  			"This is typing test program.\n",
				"System programming lab3\n"};
	time_t starttime,endtime;
	double elapsedtime;
	struct termios init_attr, new_attr;

	fd = open(ttyname(fileno(stdin)), O_RDWR);
	tcgetattr(fd, &init_attr);
	new_attr = init_attr;
	new_attr.c_lflag &= ~ICANON;
	new_attr.c_lflag &= ~ECHO; /* ~(ECHO | ECHOE | ECHOK |ECHONL); */
	new_attr.c_cc[VMIN] = 1;
	new_attr.c_cc[VTIME] = 0;

	if (tcsetattr(fd, TCSANOW, &new_attr) != 0) {
		fprintf(stderr, "터미널 속성을 설정할 수 없음.\n");
	}
	printf("타자 연습 프로그램.\n");
	
	time(&starttime); // 시작 시간

	for(int i = 0 ; i <3 ; i++){

		printf("\n%s",text1[i]);
		cnt = 0;

		while ((nread=read(fd, &ch, 1)) > 0 && ch != '\n' ) {
		 	
		
			//입력 문자가 타자 연습 문장과 같다면 입력문자, 다르면 * .
			if (ch == text1[i][cnt++])
			{
	
				write(fd, &ch, 1);
			
		        }
			else {
				write(fd, "*", 1);
				errcnt++;
			}
	
		}
	}

	time(&endtime); //종료 시간

	printf("\n타이핑 오류의 횟수는 %d\n", errcnt);
	tcsetattr(fd, TCSANOW, &init_attr);
	
	elapsedtime = difftime(endtime,starttime);
	// 타수 계산 = (전체 타자수 ) / (경과 시간 (초) / 60 )
	printf("\n평균 분당 타자수 %f %f\n",cnt/(elapsedtime/60),elapsedtime);  
	close(fd);
}
