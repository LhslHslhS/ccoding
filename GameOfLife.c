#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int coin = 1000000;
int day = 1;
char nickname[100];
int count[3] = { 0, 0, 0 };
int price[3] = { 100000, 200000, 500000 };
char name[3][100] = { "사성주식", "LPG주식", "microhard" };
int input;
int j, k;


void getInput() {

	int asset = coin + count[0]*price[0] + count[1]*price[1] + count[2]*price[2];

	printf("자본:%d\t전재산:%d\n", coin, asset);

	for ( int i = 0; i < 3; ++i ) {
		printf("%d.%s\t%d개\t%d원\n", i + 1, name[i], count[i], price[i] );
	}

	printf("-----------------------------------\n");
	printf("1.주식 매입\n");
	printf("2.주식 판매\n");
	printf("3.잠자기\n");
	printf("-----------------------------------\n");

	scanf("%d", &input );

	switch (input) {
		case 1:
			printf("매입 주식을 설정 하여주세용. 개수 설정\n");
			scanf("%d %d", &j, &k );
			count[j-1] += k;
			coin -= k * price[j-1];

			getInput();
			break;

		case 2:
			printf("판매 주식을 설정 하여주세용. 개수 설정\n");
			scanf("%d %d", &j, &k );
			count[j-1] -= k;
			coin += k * price[j-1];

			getInput();
			break;

		default:
			break;
	}

	day++;

	price[0] += rand() % 40000 - 20000;
	price[1] += rand() % 80000 - 40000;
	price[2] += rand() % 120000 - 60000;

	getInput();

}

int main() {

	printf("이름을 적어 주세용.\n");
	scanf("%s", nickname );

	srand(time(NULL));

	while(0==0) {

		getInput();

	}

	return(0);
}
