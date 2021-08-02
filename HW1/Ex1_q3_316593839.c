#include <stdio.h>

void printSum(int sum) {
    if (sum == -1) {
        printf("The number you entered is not positive!\n");
        return;
    }
    printf("The number of handshakes: %d\n", sum);
}

int main() {
	int num, sum = 0, i;
    printf("Please enter the number of people in the room:\n");
	scanf_s("%d", &num);
	i = num - 1;
	if (num <= 0) sum = -1;
	else 
	{
		for (i; i != 0; i--) {
			sum += i;
		}
	}
	printSum(sum);
    return 0;
}
