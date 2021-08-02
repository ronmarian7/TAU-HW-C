#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Test cases: 5!! = 15; 10!! = 3840;

// HERE: DEFINE THE (TAIL) RECURSIVE DOUBLE-FACTORIAL FUNCTION
int double_fact(int n ,int sum){
	if (n < 0) return 0; //Base
	if (n <= 1) return sum; // Base
	return double_fact(n - 2, n * sum); // Doing the same recursive call but now the calc is in sum
}

int main() {
	int n;
	int res; //res doesn't have to be of type int.
	printf("Please enter a number:\n");
	scanf("%d", &n);

	// HERE: CALL THE DOUBLE-FACTORIAL FUNCTION WITH THE INPUT ARGUMENT, AND STORE THE RESULT IN THE VARIABLE "res"
	res = double_fact(n, 1);
	
	printf("%d!! = %d", n, res); // NOTE: IF YOU CHANGE THE TYPE OF RES - CHANGE THE SPECIAL CHARACTHER SPECIFIER (%) ACCORDINGLY

	return 0;
}