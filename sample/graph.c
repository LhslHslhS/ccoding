#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

int main ( int argc, char const *argv[] ) {

	int N = 10;
 	float y[10] = { 9, 6, 4, 2, 1, 1, 2, 4, 6, 9 };
 	char O[10][10];

 	for ( int i = 0; i < 10; ++i ) {
 		for ( int j = 0; j < 10; ++j ) {
 			O[N-1-j][i] = (y[i] == j) ? '*': ' ';
 		}
 	}

 	for ( int i = 0; i < 10; ++i ) {
 		for ( int j = 0; j < 10; ++j ) {
 			printf("%c ", O[i][j]);
 		}
 		printf("\n");
 	}

	for ( int i = 0; i < 10; ++i ) {
		for ( int j = 0; j < 10; ++j ) {
			if ( (i + j) % 2) {
				printf("\x1b[41m  \x1b[0m");
			} else {
				printf("\x1b[0m  \x1b[0m");
			}
		}
		printf("\n");
	}
 	
 	return 0;
 } 