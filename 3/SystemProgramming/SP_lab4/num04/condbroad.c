#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 50
#define NUMITEMS 30
#define NUM_THREADS 3

char message[BUFFER_SIZE];
int message_flag = -1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t server_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t broad_to_client = PTHREAD_COND_INITIALIZER;
pthread_cond_t request_to_server = PTHREAD_COND_INITIALIZER;

void request_message(int arg){

	
	fflush(stdin);
	printf("요청할 메세지 : ");
	scanf("%s", message);

	printf("client[%d] request message %s \n",arg,message);
	message_flag += 1;
	
	// 서버에게 방송 요청을 한다.
 	pthread_cond_signal(&request_to_server);
}



void *server(void *arg)
{
	while(1){
		//pthread_mutex_lock(&server_mutex);	

		pthread_cond_wait(&request_to_server, &mutex);
		
		// 클라인언트에게 방송을 한다
		pthread_cond_broadcast(&broad_to_client);
		message_flag = -1;

		pthread_mutex_unlock(&server_mutex);	
	}

}

void *client(void *arg){

	int status;
	int num = *(int *)arg;
	
	while(1){
		pthread_mutex_lock(&client_mutex);
		
		if( message_flag < 0)
			request_message(num);
		
		// 방송을 기다린다.
		pthread_cond_wait(&broad_to_client, &mutex);
			
		printf("client[%d] receive broadcast: %s \n",num,message);
		
		pthread_mutex_unlock(&client_mutex);
	}
}
	

int main(int argc, char *argv[]){

	int status,i;
	pthread_t server_tid;
	pthread_t client_tid[NUM_THREADS];
	

	/* 클라이언트 쓰레드 생성 */
	for(i = 0; i < NUM_THREADS; i++){

		status = pthread_create (&client_tid[i], NULL, client, &i);
		
		if (status != 0) {
			fprintf (stderr, "Create consumer thread %d: %d", i, status);
			exit (1);
		}
	}
	
	/* 서버 쓰레드 생성 */
	status = pthread_create (&server_tid, NULL, server, NULL);

	if (status != 0)
		perror ("Create server thread");

	/* 소비자 쓰레드 join */
	for (i = 0; i < NUM_THREADS; i++) {

		status = pthread_join (client_tid[i],NULL);


		if (status != 0) {
			fprintf (stderr, "Join client thread %d: %d", i, status);
			exit (1);
		}
	}
	
	/* 생산자 쓰레드 join */
	status = pthread_join (server_tid, NULL);
	if (status != 0)
		perror ("Join server thread");
	

}
