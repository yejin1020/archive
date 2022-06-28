#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

	sigset_t set1, set2;

	sigfillset(&set1);/* fill set1 */

	sigemptyset(&set2);
	sigaddset(&set2, SIGINT);/* set up set2 with just SIGINT */

	printf("Critical region start.\n");
	sigprocmask(SIG_BLOCK, &set1, NULL); /*block all signal*/
	sleep(5); // for 5 sec


	printf("Less critical region start.\n");
	sigprocmask(SIG_UNBLOCK, &set2, NULL); /*unblock SIGINT */
	sleep(5);

	printf("Non critical region start.\n");
	sigprocmask(SIG_UNBLOCK, &set1, NULL); /*unblock all */
	sleep(5);

}
