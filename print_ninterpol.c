#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage() {
	printf("usage: print_ninterpol x [values]\n");
	printf("Generate Newtons forward Interpolation point at x from [values]\n");
	printf("\twhere:\n\t\tx\t->\tpoint where to interpolate\n");
	printf("\t\t[values]\t->\tvalues of y where y=f(x)\n");
}

int main(int argc, char const **argv) {
	//skip over program name
	++argv;--argc;
	
	//@handle: no values condition
	if (argc == 0) {
		printf("error: value of x not given\n");
		print_usage();
		return -1;
	}
	//@handle: No interpolation point
	if (argc == 1) {
		printf("error: [values] not given\n");
		print_usage();
		return -2;
	}
	float u = atof(argv[0]) - 1.0;
	//skip over interpolation point
	++argv;--argc;

	//@handle: One input condition of values
	if (argc == 1) {
		printf("error: cannot construct a difference table from 1 value\n");
		print_usage();
		return -2;
	}

	//@handle: Character input condition
	/*for (int i = 0; i < argc; ++i)
	{
		int tmp = -1;
		sscanf(argv[i],"%d",&tmp);
		if(atoi(argv[i]) != tmp) {
			printf("error: [values] should be integers separated by spaces\n");
			print_usage();
			return -3;
		}
	}*/
		

	//initialise data matrix and set col0 to inputs from argv and rest to 0
	int **data_mat = (int **)malloc(argc * sizeof(int *)), max_chrs = 2;
	for (int i = 0; i < argc; ++i) { data_mat[i] = (int *)malloc(argc * sizeof(int)); }
	for (int colID = 0; colID < argc; ++colID) {
		for (int rowID = 0; rowID < argc; ++rowID) {
			if (colID == 0) {
				data_mat[rowID][0] = atoi(argv[rowID]);
				if (strlen(argv[rowID]) > max_chrs) { max_chrs = strlen(argv[rowID]); }
			} else if (colID != 0){
				data_mat[rowID][colID] = 0;
			}
		}
	}

	//compute the table
	for (int colID = 1; colID < argc; ++colID) {
		for (int rowID = 0; rowID < argc - 1; ++rowID) {
			data_mat[rowID][colID] = data_mat[rowID + 1][colID - 1] - data_mat[rowID][colID - 1];
		}
	}

	//print headers
	printf("x\ty\t^y\t");
	for (int i = 1; i < argc - 1; ++i) { printf("^%dy\t",i + 1); }
	printf("\n");
	//print separators
	for (int i = 0; i < argc + 1; ++i) {
		for (int j = 0; j < max_chrs + 1; ++j)
		{
			printf("_");
		}
		printf("\t");
	}
	printf("\n");

	//print the table
	for (int rowID = 0; rowID < argc; ++rowID) {
		printf("%d\t", rowID);
		for (int colID = 0; colID < argc - rowID; ++colID) {
			printf("%d\t", data_mat[rowID][colID]);
		}
		printf("\n");
	}

	// calculate Newtons interpolation point
	float s = 0, p = 1;
	for(int i = 1; i < argc; ++i){
		p = (p * (u - i + 1))/i;
		s += p * data_mat[0][i];
		//printf("product = %f\tsum = %f\n", p, s);
	}

	s += data_mat[0][0];
	//printf("product = %f\tsum = %f\n", p, s);

	printf("Value of f(%f) = %f\n", u + 1, s);

	return 0;
}