#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main () {

	int h = 0;
	int P, C;

	while(h == 0)
	{
		srand(time(NULL));

		char z[100];

		gets(z);

		if ( strcmp( z, "가위") == 0 ) {
			P = 0;
			printf("사람: 가위 ");
		} else if ( strcmp(z, "바위") == 0 ) {
			P = 1;
			printf("사람: 바위 ");
		} else if ( strcmp(z, "보") == 0 ) {
			P = 2;
			printf("사람: 보 ");
		} else {
			printf("기권 요청 처리중...\n");
			continue;
		}

		C = rand() % 3;

		if (C == 0) {
			printf("컴퓨터: 가위\n");
		}
		if (C == 1) {
			printf("컴퓨터: 바위\n");
		}
		if (C == 2) {
			printf("컴퓨터: 보\n");
		}

		if ( P == C ) {
			printf("비김!!\n");
		} else if ( (P - C) % 3 == 1) {
			printf("사용자 승리\n컴퓨터: 한판더! 한판더!\n");
		} else if ( (P - C + 3) % 3 == 2) {
			printf("사용자 lose...\n컴퓨터: 포기해\n");
		}



	}

	return 0;

}
