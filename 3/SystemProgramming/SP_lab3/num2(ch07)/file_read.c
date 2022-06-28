#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFSIZE 512 /* 읽혀질 덩어리의 크기 */

int main()
{
	char buffer[BUFSIZE];
	int filedes;
	ssize_t nread;
	long total = 0;

	/* “anotherfile” 을 읽기 전용으로 개방 */
	if ( (filedes = open ("creat_file", O_RDONLY) ) == -1)
	{
		printf ("error in opening anotherfile\n");
		exit (1);
	}

	/* EOF 까지 반복하라. EOF 는 복귀값 0 에 의해 표시된다 */
	while ( (nread = read (filedes, buffer, BUFSIZE) ) > 0)
		total += nread;
		/* total 을 증가시킨다 */
	

	printf ("total chars in creat_file: %ld\n", total);
	exit (0);
}
