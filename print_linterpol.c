#include <stdio.h>
#include <stdlib.h>

void print_help() {
	printf("usage: print_linterpol interpolation_point N [x_values] [y_values]\n");
}

int main(int argc, char **argv) {
	// skip program name
	argv++;argc--;

	// No input
	if (argc == 0){
		print_help();
		return -1;
	}
	// only interpolation point given
	if (argc == 1){
		printf("error: only interpolation_point given\n");
		print_help();
		return -2;
	}
	// size given but no values
	if (argc == 2){
		printf("error: array size given but array values of x and y are missing\n");
		print_help();
		return -3;
	}
	//get interpolation point
	float intP = atof(argv[0]);
	// skip interpolation point
	argv++;argc--;
	//get array size
	int n = atoi(argv[0]);
	// skip array size
	argv++;argc--;

	// Now the remaining values should be exactly 2ice of n
	if((n*2) != argc) {
		printf("error: the input values do not match the given size\n");
		print_help();
		return -4;
	}

	// malloc for x
	float *x = (float *) malloc(n * sizeof(float));
	// fill x
	for(int i = 0; i < n;++i)
		x[i] = atof(argv[i]);

	// malloc for y
	float *y = (float *) malloc(n * sizeof(float));
	//fill y
	for (int i = n; i < argc ; ++i)
		y[i - n] = atof(argv[i]);

	float sum = 0, term;
	for (int i = 0; i < n; i++){
		term = y[i];
		for (int j = 0; j < n; j++){
			if(j!=i)
				term *= ((intP - x[j]) / (x[i] - x[j]));
		}
		sum += term;
	}

	printf("Value of f(%f) = %f\n",intP, sum);

	return 0;
}