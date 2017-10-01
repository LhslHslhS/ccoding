#include <stdio.h>

int isPalindrome (int number) {

	int a = 0;
	int n = number;
	int b;

	while (n) {
		b = n % 10;
		a = a * 10 + b;
		n = n / 10;
	}

	return number == a;
}

int main () {


	for ( int i = 900; i < 1000; ++i ) {
		for ( int j = 900; j < 1000; ++j ) {
			if (isPalindrome(i * j)) {
				printf("%d * %d = %d, %d\n", i, j, i * j, isPalindrome(i * j));
			}
		}
	}

	
	return 0;
}