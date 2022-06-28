#include <stdio.h>
#include <stdlib.h>
#include "operationlib.h"

void main(int argc, char *argv[])
{
	printf("add(%d,%d) = %d\n",atoi(argv[1]),atoi(argv[2]),add(atoi(argv[1]),atoi(argv[2])));
	printf("sub(%d,%d) = %d\n",atoi(argv[1]),atoi(argv[2]),sub(atoi(argv[1]),atoi(argv[2])));
	printf("multi(%d,%d) = %d\n",atoi(argv[1]),atoi(argv[2]),multi(atoi(argv[1]),atoi(argv[2])));
	printf("divi(%d,%d) = %d\n",atoi(argv[1]),atoi(argv[2]),divi(atoi(argv[1]),atoi(argv[2])));
}
