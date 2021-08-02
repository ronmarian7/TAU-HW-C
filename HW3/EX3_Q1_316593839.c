#include <stdio.h>
#define SIZE 5

int or_gate(int a, int b)
{
	return ((a + b) - (a * b)); // The OR equation 
}

void read_mat(int mat[][SIZE])
{
	char one_d_arr[SIZE * SIZE + 1] = { 0 }; //1D array
	int i = 0, n, m;
	int c = 0;

	fgets(one_d_arr, SIZE * SIZE + 1, stdin); //Getting the input in one line
	fseek(stdin, 0, SEEK_END); // Cleaning the extra chars over the cap

	for (m = 0; m < SIZE; m++)
	{
		for (n = 0; n < SIZE; n++)
		{
			if (one_d_arr[m * SIZE + n] == '\0') return;; // If the char is '\n' from enter or '\0' fro, end of str the exit the func 
			if (one_d_arr[m * SIZE + n] == '\n') return;;
			if (one_d_arr[m * SIZE + n] != 48) mat[m][n] = 1; // If the char is not '0' the put 1 in the matrix
		}

	}
}

void mult_mat(int mat1[][SIZE], int mat2[][SIZE], int result_mat[][SIZE])
{
	int i, j, k, sum = 0, temp = 0;
	for (i = 0; i < SIZE; i++)
	{
		sum = 0;
		for (j = 0; j < SIZE; j++)
		{
			sum = 0;
			for (k = 0; k < SIZE; k++)
			{
				temp = mat1[i][k] * mat2[k][j]; // AND between the 2 elements
				sum = or_gate(sum, temp); // OR between the sums
			}
			result_mat[i][j] = sum;
		}
	}
}

void print_mat(int mat[][SIZE])
{
	//Please use the "%3d" format to print for uniformity.
	int n, m;
	for (m = 0; m < SIZE; m++) {
		for (n = 0; n < SIZE; n++) {
			printf("%3d", mat[m][n]);
		}
		printf("\n");
	}
}

int main()
{
	int mat1[SIZE][SIZE] = { 0 };
	int mat2[SIZE][SIZE] = { 0 };
	int result_mat[SIZE][SIZE] = { 0 };
	int i = 0, n, m;
	int c = 0;
	printf("Please Enter Values For Matrix 1\n");
	// Your function call here..
	read_mat(mat1);
	printf("Please Enter Values For Matrix 2\n");
	// Your function call here..
	read_mat(mat2);

	// Do the multiplication magic..
	mult_mat(mat1, mat2, result_mat);
	printf("The First Matrix Is :- \n");
	// Your function call here..
	print_mat(mat1);
	printf("The Second Matrix Is :- \n");
	// Your function call here..
	print_mat(mat2);
	printf("The Resultant Matrix Is :- \n");
	// Your function call here..
	print_mat(result_mat);

	return 0;
}