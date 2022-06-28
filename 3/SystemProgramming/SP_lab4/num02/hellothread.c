/* writepshm.c */
/* POSIX shared memory example */
#include <sys/types.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
/* hellothreads.c */
/* pthread argument passing example */
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_THREADS 3
/* 쓰레드 생성 */
void *hello_thread (void *arg)
{
printf("Thread %d: Hello, World!\n", arg);
return arg;
}
int main()
{
pthread_t tid[NUM_THREADS];
int i, status;
for (i = 0; i <NUM_THREADS; i++) {
status = pthread_create (&tid[i], NULL, hello_thread, (int *) i);
if (status != 0) {
fprintf (stderr, "Create thread%d: %d", i, status);
exit (1);
}
}
pthread_exit (NULL);
}


