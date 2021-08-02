#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Test cases: 5!! = 15; 10!! = 3840;

// HERE: DEFINE THE RECURSIVE FACTORIAL FUNCTION
long long factorial(long long n) {
	if (n < 0) return 0; //Base
	if (n < 1) return 1; //Base
	return n * factorial(n - 1); //Recursive call
}
// HERE: DEFINE THE RECURSIVE DOUBLE-FACTORIAL FUNCTION
long long f_function(long long n) {
	if (n < 0) return 0; //Base
	if (n <= 1) return 1;//Base
	return factorial(n) / f_function(n - 1); // We needed to find f(n!, g(n)!!),
	//  g(n) = n-1, f(n) = n! / g(n)!! = n! / (n-1)!! and so on

}

int main() {
	int n;
	long long res; //res doesn't have to be of type int.
	printf("Please enter a number:\n");
	scanf("%d", &n);

	// HERE: CALL THE DOUBLE-FACTORIAL FUNCTION WITH THE INPUT ARGUMENT, AND STORE THE RESULT IN THE VARIABLE "res"
	res = f_function(n);
	printf("%d!! = %lli", n, res); // NOTE: IF YOU CHANGE THE TYPE OF RES - CHANGE THE SPECIAL CHARACTHER SPECIFIER (%) ACCORDINGLY

	return 0;
}