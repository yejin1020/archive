#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "my_perror.h"

int main(int argc, char* argv[])
{
	FILE *f;

	if(argc < 2){
		printf("usuage : perror_use nofilename\n");
		exit(1);
	}

	if( (f = fopen(argv[1],"r" )) == NULL ){
		my_perror("fopen");
		//my_perror(NULL);	
		exit(1);
	}

	printf("open a file  \"%s\".\n",argv[1]);

	fclose(f);
}
