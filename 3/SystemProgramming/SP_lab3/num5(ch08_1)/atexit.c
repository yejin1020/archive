#include <stdlib.h>
#include <stdio.h>

void exitfunc2(void)
{
	printf("This is exit function 2.\n");
}

void exitfunc1(void)
{
	printf("This is exit function 1.\n");
}

int main()
{
	atexit(exitfunc1);
	atexit(exitfunc2);
	
	printf("This is main function.\n");
}

