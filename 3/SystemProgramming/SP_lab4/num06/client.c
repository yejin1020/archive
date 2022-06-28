#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <termios.h>
#include <fcntl.h>

#define BUF_LEN 1024
#define IP "127.0.0.1"  //연결하려는 서버의 IP
#define PORT 5600       //연결하려는 서버의 PORT

pthread_t thread;
pthread_mutex_t mutex;

void *thread_main(void * my_fd)  /* read thread */
{	
	
	char buf[BUF_LEN];
	while(1)
	{
		pthread_mutex_lock (&mutex);
		memset(buf, 0, sizeof(buf));
		read(*(int *)my_fd, buf, BUF_LEN);
		printf("\n msg : %s\n",buf);
		pthread_mutex_unlock (&mutex);
	}
}


int main(int argc, char* argv[])
{

	char buf[BUF_LEN];
	struct sockaddr_in serv_addr;
	int my_fd;
	int len, msg_size;

	if((my_fd = socket(AF_INET, SOCK_STREAM, 0)) <0)
	{
		printf("my socket error\n");
		return -1;
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(IP);
	serv_addr.sin_port = htons(PORT);

	//connect 
	if(connect(my_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("connect error\n");
		return -1;
	}

	pthread_create(&thread, NULL, &thread_main, &my_fd);

	while(1)
	{
		fgets(buf,sizeof(buf),stdin);
		msg_size = strlen(buf)+1;

		if((write(my_fd, buf, msg_size))<0)
		{
		    printf("write error\n");
		    return -1;
		}
	}
}

