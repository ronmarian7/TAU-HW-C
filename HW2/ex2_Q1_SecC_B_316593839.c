#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Test cases: 5!! = 15; 10!! = 3840;

// HERE: DEFINE THE RECURSIVE FACTORIAL FUNCTION
long long  factorial(long long n) {
	if (n < 0) return 0; //Base
	if (n <= 1) return 1; //Base
	return n * factorial(n - 1); // Recursive call
}
// HERE: DEFINE THE (TAIL) RECURSIVE DOUBLE-FACTORIAL FUNCTION
long long f_function(int n, long long sum, int stat) {
	if (n <= 1) return sum; // Base
	if (stat == 0) return f_function(n - 1, sum / factorial(n - 1), 1); // if stat = 0 then the sum is divided by (n-1)! and change stat to 1 
	return f_function(n - 1, sum * factorial(n - 1), 0); // if stat = 1 then the sum is multiplied by (n-1)! and change stat to 0 
}

int main() {
	int n;
	long long res; //res doesn't have to be of type int.
	printf("Please enter a number:\n");
	scanf("%d", &n);
	// HERE: CALL THE DOUBLE-FACTORIAL FUNCTION WITH THE INPUT ARGUMENT, AND STORE THE RESULT IN THE VARIABLE "res"
	res = f_function(n, factorial(n), 0);
	printf("%d!! = %lli", n, res); // NOTE: IF YOU CHANGE THE TYPE OF RES - CHANGE THE SPECIAL CHARACTHER SPECIFIER (%) ACCORDINGLY

	return 0;
}