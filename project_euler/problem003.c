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

long int solve( long int a, long int b ) {

	if ( a == b )
		return a;

	if ( a % b == 0 ) {
		printf("%ld\n", b);
		return solve(a/b, b+1);
	} else {
		return solve(a, b+1);
	}
}


int main () {

	long int number = 1001;

	long int s = solve(1001, 7);

	printf("%ld\n", s);
	 
	// for ( long int i = number / 71; i > 0; i-- ) {
	// 	if (number % i == 0) {

	// 		long int factor = i;
	// 		if ( isPrime( factor ) ) {
	// 			printf("%ld\n", factor);
	// 			break;
	// 		}
	// 	}
	// }
	
	return 0;
}