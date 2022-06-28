#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define MAX_READ 10

int main(int argc, char *argv[])
{

	int src_fd; /* source file descriptor */
	int dst_fd; /* destination file descriptor */
	char buf[MAX_READ];
	ssize_t rcnt; //read count
	ssize_t tot_cnt = 0; // total write count
	mode_t mode = S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH; // 0664

	if (argc < 3) {

		fprintf(stderr,"usuage : file_copy src_file dest_file\n");
		exit(1);
	}

	// 복사 내용을 저장할 파일 생성
	if( (dst_fd = creat(argv[2],mode)) == -1 ) {
		perror("dest open");
		exit(1);
	}
	
	// src_file -> dest_file
	while( (rcnt = read(src_fd,buf,MAX_READ)) > 0 ){
		tot_cnt += write(dst_fd,buf,rcnt);
	}

	printf("df");
	if(rcnt < 0){
		perror("read");
		exit(1);
	}

	
	printf("total write count = %ld\n", tot_cnt);
	close(src_fd);
	close(dst_fd);
}
