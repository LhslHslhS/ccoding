#include <stdio.h>
#include <math.h>

int isPrime (long int number) {

	for ( int i = 2; i <= sqrt(number); ++i ) {
		if (number % i == 0)
		{
			return 0;
		}
	}
	
	return 1;
}


int main () {

	long long int sum = 0;
	for ( long long int i = 2; i < 2000000; ++i ) {
		if (isPrime(i)) {
			printf("%lld\n", i);
			sum += i;
		}
	}
	printf("%lld\n", sum);
	
	return 0;
}