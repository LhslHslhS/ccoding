#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

int main ( int argc, char const *argv[] ) {

	int N = 50;
 
 	int a[N][N];
 	int b[N][N];

 	float t = 0;

 	while(1) {

 		t = t + 0.01;

	 	for ( int x = 0; x < N; ++x ) {
	 		for ( int y = 0; y < N; ++y ) {
	 			if ( abs(y - (10*sin((float)x/6 + t) + 25)) < 2  ) 
	 			{
	 				a[x][y] = '*';
	 			} else
	 			{
	 				a[x][y] = '.';
	 			}
	 		}
	 	}

	 	for ( int x = 0; x < N; ++x ) {
	 		for ( int y = 0; y < N; ++y ) {
	 			b[x][y] = a[y][N-1-x];
	 		}
	 	}

	 	// if (t > 2)
	 	// {
	 		
	 	system("clear");

	 	for ( int x = 0; x < N; ++x ) {
	 		for ( int y = 0; y < N; ++y ) {
	 			printf("%c ", b[x][y]);
	 		}
	 		printf("\n");
	 	}

	 	// 	t = 0;
	 	// }

		sleep(0.16);

 	}


 	
 	return 0;
 } 