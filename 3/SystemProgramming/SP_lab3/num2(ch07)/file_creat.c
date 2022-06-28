#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd; /* file descriptor */
	char *buf = "This is a test.";
	ssize_t cnt; /* write count */
	int flags = O_WRONLY | O_CREAT | O_TRUNC;	
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP |S_IROTH; /* == 0644 */
	
	if (argc < 2) {
		fprintf(stderr, "Usage: file_creat filename\n");
		exit(1);
	}

	if ( (fd = open(argv[1], flags, mode)) == -1 ){
		perror("open"); /* errno에 대응하는 메시지 출력됨 */
		exit(1);
	}
	
	//파일에 buf 내용을 입력하고 적은 바이트 값 반환 받는다.
	cnt = write(fd, buf, strlen(buf));
	printf("write count = %ld\n", cnt);
	
	close(fd);
}
