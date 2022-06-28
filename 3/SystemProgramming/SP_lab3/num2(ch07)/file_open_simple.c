#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	ssize_t nread;
	char buf[1024];

	//파일을 읽기 전용으로 개방
	/* 파일 "data"를 읽기 위해 개방한다 */
	// 파일 기술자에서 열려진 파일의 위치 인덱스를 반환한다.
	fd = open("data", O_RDONLY);
	

	/* 데이터를 읽어들인다 */
	// 파일 티스크립트 번호, 저장할 번호, 한번에 읽어들일 크기
	nread = read(fd, buf, 1024);

	/* 파일을 폐쇄한다 */
	close(fd);
}
