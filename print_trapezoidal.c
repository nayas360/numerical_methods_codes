#include <stdio.h>
#include <stdlib.h>

void print_help(){
	printf("usage: print_simpson lb ub h");
}

// function to integrate over
float f(float x){
	return 1/(1+(x*x));
}

int main(int argc, char **argv){
	// skip program name
	argv++;argc--;

	// no input
	if(argc == 0){
		print_help();
		return -1;
	}
	// if only lb
	if(argc == 1){
		printf("error: only lb given\n");
		print_help();
		return -2;
	}
	// if till ub
	if(argc == 2){
		printf("error: strip size h is missing\n");
		print_help();
		return -2;
	}

	// get lb ub and h
	float lb = atof(argv[0]), ub = atof(argv[1]), h = atof(argv[2]);
	int n = (ub - lb) / h;

	float s = 0;
	for(int i = 1; i < n; ++i){
		s += f(lb + i * h);
	}

	printf("Result of final integration is %f\n", (h/2*(f(lb) + f(ub) + 2*s)));

	return 0;
}