#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define BUFFER_SIZE 20
#define NUMITEMS 30
#define NUM_THREADS 3

typedef struct {
	int item[BUFFER_SIZE];
	int totalitems;
	int in, out;
	pthread_mutex_t mutex;
	pthread_cond_t full;
	pthread_cond_t empty;
} buffer_t;

buffer_t bb = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_COND_INITIALIZER,
	PTHREAD_COND_INITIALIZER};

/* 숫자 생산 */
int produce_item ()
{
	static int item = 0;
	
	item = (item+1) %100;
	sleep((unsigned long) (5.0*rand()/(RAND_MAX+1.0)));
	printf("produce_item: item=%d\n", item);
	return item;
}

/* 숫자 버퍼 삽입*/
int insert_item (int item)
{
	int status;
	status = pthread_mutex_lock (&bb.mutex);

	if (status != 0)
		return status;

	while (bb.totalitems >= BUFFER_SIZE && status == 0 )
		status = pthread_cond_wait (&bb.empty,&bb.mutex);

	if (status != 0) {
		pthread_mutex_unlock(&bb.mutex);
		return status;
	}

	bb.item[bb.in] = item;
	bb.in = (bb.in + 1) % BUFFER_SIZE;
	bb.totalitems++;

	if (status = pthread_cond_signal(&bb.full)) {
		pthread_mutex_unlock (&bb.mutex);
		return status;
	}

	return pthread_mutex_unlock (&bb.mutex);
}
/* 숫자 소비 */
void consume_item (int item)
{
	sleep((unsigned long) (5.0*rand()/(RAND_MAX+1.0)));
	printf("\t\tconsume_item: item=%d\n", item);
}

/* 숫자 버퍼 소비*/
int remove_item (int *temp)
{
	int status;
	status = pthread_mutex_lock (&bb.mutex);

	if (status != 0)
		return status;

	while (bb.totalitems <= 0 && status == 0)
		status = pthread_cond_wait (&bb.full, &bb.mutex);

	if (status != 0) {
		pthread_mutex_unlock(&bb.mutex);
		return status;
	}
	*temp = bb.item[bb.out];
	bb.out = (bb.out + 1) % BUFFER_SIZE;
	bb.totalitems--;

	if (status = pthread_cond_signal(&bb.empty)) {
		pthread_mutex_unlock (&bb.mutex);
		return status;
	}

	return pthread_mutex_unlock (&bb.mutex);

}

void * producer(void *arg)
{
	int item;
	while (1) {
		item = produce_item ();
		insert_item(item);
	}
}

void * consumer(void *arg)
{
	int item;
	while (1) {
		remove_item (&item);
		consume_item (item);
	}
}
int main ()
{
	int status;
	void *result;
	pthread_t producer_tid[NUM_THREADS];
	pthread_t consumer_tid[NUM_THREADS];
	int i;

	/* 생산자 쓰레드 생성 */
	for (i = 0; i < NUM_THREADS; i++) {

		status = pthread_create (&producer_tid[i],NULL,producer, NULL);

		if (status != 0) {
			fprintf (stderr, "Create producer thread %d: %d", i, status);
			exit (1);
		}
	}

	/* 소비자 쓰레드 생성 */
	for (i = 0; i < NUM_THREADS; i++) {

		status = pthread_create (&consumer_tid[i],NULL,consumer, NULL);

		if (status != 0) {
			fprintf (stderr, "Create consumer thread %d: %d", i, status);
			exit (1);
		}
	}

	/* 생산자 쓰레드 join */
	for (i = 0; i < NUM_THREADS; i++) {

		status = pthread_join (producer_tid[i],NULL);

		if (status != 0) {
			fprintf (stderr, "Join producer thread %d: %d", i, status);
			exit (1);
		}
	}
	
	/* 소비자 쓰레드 join */
	for (i = 0; i < NUM_THREADS; i++) {

		status = pthread_join (consumer_tid[i],NULL);


		if (status != 0) {
			fprintf (stderr, "Join consumer thread %d: %d", i, status);
			exit (1);
		}
	}



}
