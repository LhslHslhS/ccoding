#include <stdio.h>

int main ( int argc, char const *argv[] ) {

	char string[100] = "%d Hello";
	int k = 10;

	printf(string, k);
	
	return 0;
}