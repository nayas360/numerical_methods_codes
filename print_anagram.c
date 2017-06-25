// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>

//global count var
int cnt = 0;

/* Function to swap values at two pointers */
void swap(char *x, char *y) {
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int r) {
	int i;
	if (l == r) {
		printf("%s\n", a);
		cnt++;
	}
	else {
		for (i = l; i <= r; i++) {
			swap((a+l), (a+i));
			permute(a, l+1, r);
			swap((a+l), (a+i)); //backtrack
		}
	}
}

void print_usage() {
	printf("usage: print_anagram <n>\n");
}

/* Driver program to test above functions */
int main(int argc, char *argv[]) {
	//skip over program name
	++argv;--argc;
	//@handle: no values condition
	if (argc == 0) {
		print_usage();
		return -1;
	}
	permute(argv[0], 0, strlen(argv[0]) - 1);
	printf("Total permutations: %d\n", cnt);
	return 0;
}