#include <stdio.h>
#include <stdlib.h>

void upsample(float a[], float b[], int aCount, int upRate) {
	b[0] = a[0];
	for ( int i = 1; i < aCount; ++i ) {
		b[i * upRate] = a[i];
		for ( int p = 1; p < upRate; ++p ) {
			b[((i-1)*upRate) + p] = ( p * b[i * upRate] + (upRate - p) * (b[(i-1) * upRate]) ) / upRate;
		}
	}
}

void downsample(float b[], float a[], int bCount, int downRate) {
	for ( int i = 0; i < bCount / downRate; ++i ) {
		a[i] = b[i * downRate];
	}
}

int main() {
	
	float a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int upRate = 7;
	int downRate = 5;
	int aCount = 10;
	int bCount = aCount * upRate;
	int cCount = bCount / downRate;
	
	float *b = (float *) malloc(aCount * upRate * sizeof(float));


	float *c = (float *) malloc(bCount * downRate * sizeof(float));

	upsample(a, b, aCount, upRate);
	downsample(b, c, bCount, downRate);

	for ( int i = 0; i < aCount; ++i ) {
		printf("%.2f ", a[i]);
		for ( int j = 0;  j< upRate - 1; ++j ) {
			printf("     " );
		}
	}

	printf("\n");

	for ( int i = 0; i < bCount; ++i ) {
		printf("%.2f ", b[i]);
	}

	printf("\n");

	for ( int i = 0; i < cCount; ++i ) {
		printf("%.2f ", c[i]);
		for ( int j = 0;  j < downRate - 1; ++j ) {
			printf("     " );
		}
	}



	return 0;
	
}
