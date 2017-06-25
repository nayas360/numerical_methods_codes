#include <stdio.h>
#include <stdlib.h>

void print_help(){
	printf("usage: print_simpson lb ub h");
}

// function to integrate over
float f(float x){
	return 1/(1+x);
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
		printf("error: only lb & ub given\n");
		print_help();
		return -2;
	}

	// get lb ub and h
	float lb = atof(argv[0]), ub = atof(argv[1]), h = atof(argv[2]);
	int n = (ub - lb) / h;
	if (n%2 == 1)
		n++;
	h = (ub - lb) / n;

	float so = 0,se = 0;
	for(int i = 1; i < n; ++i){
		if(i%2 == 1)
			so += f(lb + i * h);
		else
			se += f(lb + i * h);
	}

	printf("Result of final integration is %f\n", (h/3*(f(lb) + f(ub) + 4*so+2*se)));

	return 0;
}