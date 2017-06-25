#include <stdio.h>
#include <stdlib.h>

float f(float x, float y){
	return ((x*x) + (y*y));
}

int main(int argc, char **argv){
	//skip program name
	argv++;argc--;

	// invalid input set
	if (argc != 4){
		printf("usage: print_euler x0 y0 xn h\n");
		return -1;
	}
	float x = atof(argv[0]), y = atof(argv[1]), n = atof(argv[2]), h = atof(argv[3]);
	for(; x < n; x+=h){
		y += h*(f(x,y));
	}
	printf("result : %f\n",y);
	return 0;
}