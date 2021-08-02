#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Test cases: 5!! = 15; 10!! = 3840;

// HERE: DEFINE THE RECURSIVE DOUBLE-FACTORIAL FUNCTION
int double_factorial(int n) {
	if (n < 0) return 0; //Base
	if (n <= 1) return 1; //Base
	return n * double_factorial(n - 2); //Recursive call
}

int main() {
	int n;
	int res; //res doesn't have to be of type int.
	printf("Please enter a number:\n");
	scanf("%d", &n);

	// HERE: CALL THE DOUBLE-FACTORIAL FUNCTION WITH THE INPUT ARGUMENT, AND STORE THE RESULT IN THE VARIABLE "res"
	res = double_factorial(n);
	
	printf("%d!! = %d", n, res); // NOTE: IF YOU CHANGE THE TYPE OF RES - CHANGE THE SPECIAL CHARACTHER SPECIFIER (%) ACCORDINGLY

	return 0;
}