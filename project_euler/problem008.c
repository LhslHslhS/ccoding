#include  <stdio.h>
int main () {
	long int a;
	long int b;
	long int c;
	long int p;
	int flag = 0;

	for ( a = 1; a < 333; ++a ) {
		for ( b = 1; b < 666; ++b ) {
			if (1000 * (a + b) == a * b + 500000) {
				c = 1000 - (a + b);
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}

	printf("%ld\n", a);
	printf("%ld\n", b);
	printf("%ld\n", c);

	printf("%ld\n", a*b*c);
	return 0;
}