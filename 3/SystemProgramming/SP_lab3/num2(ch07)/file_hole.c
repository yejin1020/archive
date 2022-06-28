#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

const char *endstring = ".";

int main(int argc, char *argv[])
{
	int fd; /* file descriptor */
	off_t hole_size;
	off_t size;

	if (argc < 3) {
		fprintf(stderr, "Usage: file_hole filename size\n");
		exit(1);
	}

	if ( (fd = open(argv[1], O_RDWR)) == -1 ){
		perror("open"); /* errno에 대응하는 메시지 출력됨 */
		exit(1);
	}

	size = lseek(fd, 0, SEEK_END);
	printf("Before : %s\'s size = %ld\n", argv[1], size);

	hole_size = atoi(argv[2]);

	lseek(fd, hole_size, SEEK_END); /* 오프셋이 파일 크기를 초과하는 경우 */
	write(fd, endstring, 1); /* write()가 있어야만 NULL 문자로 채운다. */

	size = lseek(fd, 0, SEEK_END);
	printf("After : %s\'s size = %ld\n", argv[1], size);

	close(fd);
}

