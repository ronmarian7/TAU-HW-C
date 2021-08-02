#include <stdio.h>
void printSorted(int num) {
    if (num == -1) {
        printf("This is not a 3-digit number!\n");
        return;
    }
    printf("The sorted number is: %03d\n", num);
}

int main() {
	printf("Plese enter a 3-digit number:\n");
	int num = 0, totalsum = 0, num1 = 0, num2 = 0, num3 = 0;
	scanf_s("%d", &num);
	if (100 > num || num > 999) {
		totalsum = -1;
	}
	else {
		num1 = (num / 100) % 10;
		num2 = (num / 10) % 10;
		num3 = (num) % 10;
		if (num1 <= num2 & num1 <= num3) {
			if (num2 <= num3) totalsum = num1 * 100 + num2 * 10 + num3;
			else {
				totalsum = num1 * 100 + num3 * 10 + num2;
			}
		}
		if (num2 <= num1 & num2 <= num3) {
			if (num1 <= num3) totalsum = num2 * 100 + num1 * 10 + num3;
			else {
				totalsum = num2 * 100 + num3 * 10 + num1;
			}
		}
		if (num3 <= num1 & num3 <= num1) {
			if (num1 <= num2) totalsum = num3 * 100 + num1 * 10 + num2;
			else {
				totalsum = num3 * 100 + num2 * 10 + num1;
			}
		}
		
		
	}
	printSorted(totalsum);
    return 0;
}


