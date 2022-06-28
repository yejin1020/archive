#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void main(int argc, char*argv[])
{
	void *handle;
	int (*add)(int,int), (*divi)(int,int),(*sub)(int,int),(*multi)(int,int);
	char *error;

	handle = dlopen("./lib/liboperation.so",RTLD_LAZY);
	if(!handle)
	{
		fputs(dlerror(), stderr);
		exit(1);

	}

	add = dlsym(handle,"add");
	if((error = dlerror()) != NULL)
	{
		fprintf(stderr, "%s", error);
		exit(1);
	}

	sub = dlsym(handle,"sub");
	if((error = dlerror()) != NULL)
	{
		fprintf(stderr, "%s", error);
		exit(1);
	}
	
	multi = dlsym(handle,"multi");
	if((error = dlerror()) != NULL)
	{
		fprintf(stderr, "%s", error);
		exit(1);
	}

	divi = dlsym(handle,"divi");
	if((error = dlerror()) != NULL)
	{
		fprintf(stderr, "%s", error);
		exit(1);
	}

	printf("add(%d,%d) = %d\n",atoi(argv[1]),atoi(argv[2]),(*add)(atoi(argv[1]),atoi(argv[2])));
	printf("sub(%d,%d) = %d\n",atoi(argv[1]),atoi(argv[2]),(*sub)(atoi(argv[1]),atoi(argv[2])));
	printf("multi(%d,%d) = %d\n",atoi(argv[1]),atoi(argv[2]),(*multi)(atoi(argv[1]),atoi(argv[2])));
	printf("divi(%d,%d) = %d\n",atoi(argv[1]),atoi(argv[2]),(*divi)(atoi(argv[1]),atoi(argv[2])));
	
	dlclose(handle);
}
