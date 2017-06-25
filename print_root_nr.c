#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_help(){
	printf("print_root_bisection a b\n");
}

float f(float x){
	return ((x*x) + x - 7);
}

float g(float x){
	return ((2*x) + 1);
}

int main(int argc,char ** argv){
	//skip prigram name
	argv++;argc--;

	//no input
	if (argc == 0){
		print_help();
		return -1;
	}

	//only a given
	if (argc == 1){
		printf("error: value of b not given\n");
		print_help();
		return -2;
	}
	
	float a = atof(argv[0]),b = atof(argv[1]);

	// interval error
	if(f(a) * f(b) > 0){
		printf("error: given interval is invalid\n");
		print_help();
		return -3;
	}

	do{
		b = a;
		a -= (f(a)/g(a));
	} while(fabs(b-a) > 0.0001);

	printf("root = %f\n", a);

	return 0;
}