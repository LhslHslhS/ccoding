#include <stdio.h>

int main () {

	int N = 1000;
	int sum = 0;

	for ( int i = 1; i < N; i++ ) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}

	printf("%d\n", sum);

	int h = 0;
	int f = 0;
	int q = 0;

	for ( int i = 0; i <= 1000 / 3; ++i ) {
		h += 3 * i;
	}
	for ( int g = 0; g <= 1000 / 5; ++g ) {
		f += 5  * g;
	}
	for ( int w = 0; w <= 1000 / 15; ++w ) {
		q += 3 * w;
	}
	int m = h + f - q;
	printf("%d\n",m );
	
	return 0;
}