#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

#ifndef NDEBUG
#define my_assert(expr)\
	m_assert(#expr, expr, __FILE__, __LINE__)	
#else
#define my_assert(expr)
#endif

void m_assert( const char* expr_str,unsigned int expr, const char* file, int line)
{
	if( !expr)
	{
		printf("[my_asssert]\n");
		printf("Failed condition : %s\n",expr_str);
		printf("File: %s ,Line: %d\n",file,line);
		
		abort();
	}
}

void foo(int num)
{

	my_assert((num >= 0 ) && (num <= 100));
	printf("foo: num = %d\n", num);
}

int main (int argc, char *argv[])
{
	int num;

	if( argc < 2){
		printf("stderr, usage : asser_test aNumber\n( 0<= aNumber <= 100)\n");
		exit(1);
	}

	num = atoi(argv[1]);
	foo(num);
}


