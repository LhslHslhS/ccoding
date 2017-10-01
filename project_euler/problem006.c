#include <stdio.h>
int main () {
	long int ps = 0;
	for ( long int i = 0; i < 101; ++i ) {
		ps += i * i;
	}
	long int psw = 0;
	for ( long int i = 0; i < 101; ++i ) {
		psw += i;
	}
	psw *= psw;
	long int psl = psw - ps;
	printf("%ld\n", psl );
	return 0;
}