#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void my_perror(char *str){

	if (str == NULL)
		fprintf(stderr,"%s\n", strerror(errno));
	else
		fprintf(stderr, "%s: %s\n", str, strerror(errno) );
}

