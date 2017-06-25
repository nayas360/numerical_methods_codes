#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int n) {
	if ( n == 0 )
		return 0;
	else if ( n == 1 )
		return 1;
	else
		return ( Fibonacci(n-1) + Fibonacci(n-2) );
}

void print_usage() {
	printf("usage: print_fib <n>\n");
}

int main(int argc, char const **argv) {
	//skip over program name
	++argv;--argc;
	//@handle: no values condition
	if (argc == 0) {
		print_usage();
		return -1;
	}
	//print recursively
	for (int i = 0; i <= atoi(argv[0]); i++)
	{
		printf("%d ", Fibonacci(i));
	}
	printf("\n");
	return 0;
}