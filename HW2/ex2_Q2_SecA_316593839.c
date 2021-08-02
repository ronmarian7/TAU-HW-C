#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// NOTE: Since <math.h> is included, you can use sqrt() to calculate the square-root of a number.

// HERE: DEFINE THE RECURSIVE FUNCTION THAT CALCULATES THE VALUE OF THE EXPRESSION GIVEN IN THE HW
double sum_series(double n){
	if (n <= 0) return 0; //Base
	if (n <= 1) return 1; //Base
	return sqrt(n + sum_series(n-1)); 
}
int main() {
	int n;
	double res;
	printf("Please enter a number:\n");
	scanf("%d", &n);

	// HERE: CALL THE FUNCTION DEFINED ABOVE WITH THE INPUT ARGUMENT, AND STORE THE RESULT IN THE VARIABLE "res"
	res = sum_series(n); 
	printf("Result = %lf", res);
	return 0;
}