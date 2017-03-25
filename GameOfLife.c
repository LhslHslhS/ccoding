#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long coin = 1000000;
int day = 1;
char nickname[100];
int count[3] = { 0, 0, 0 };
unsigned long price[3] = { 100000, 200000, 500000 };
char name[3][100] = { "사성주식", "LPG주식", "microhard" };
int input;
int j, k,l;
// int friend1 = 1000000;
// int friend2 = 1000000;
// int friend3 = 1000000;
unsigned long friendCoin[3] = { 1000000, 1000000, 1000000 };
unsigned long borrowCoin[3] = {0, 0, 0};
unsigned long borrow = 0;

void getInput() {

	unsigned long asset = coin + count[0]*price[0] + count[1]*price[1] + count[2]*price[2];

	printf("자본:%11ld원\t전재산: %11ld원\n", coin, asset);

	for ( int i = 0; i < 3; ++i ) {
		printf("%d.%s\t%11d개\t%11ld원\n", i + 1, name[i], count[i], price[i] );
	}


	printf("--------------day: %03d-------------\n", day);
	printf("1.주식 매입\n");
	printf("2.주식 판매\n");
	printf("3.돈꾸기\n");
	printf("4.돈갚기\n");
	printf("5.잠자기\n");
	printf("-----------------------------------\n");

	scanf("%d", &input );

	switch (input) {
		case 1:
			printf("매입 주식을 설정 하여주세용. 개수 설정\n");
			scanf("%d %d", &j, &k );

			if ( k * price[j-1] > coin) {
				printf("프로그램: 주식 한개를 파십시오.\n      안 그러면 쫓겨납니다...\n");
				getInput();
			}

			count[j-1] += k;
			coin -= k * price[j-1];

			getInput();
			break;

		case 2:
			printf("판매 주식을 설정 하여주세용. 개수 설정\n");
			scanf("%d %d", &j, &k );


			if ( k > count[j-1])
			{
				printf("프로그램: 사기 치지마 \n      경찰에 신고한다\n");
				getInput();
			}

			count[j-1] -= k;
			coin += k * price[j-1];

			getInput();
			break;

		case 3:
			printf("빌릴친구를 선택하십시오\n");
			printf("친구1 (전재산:%ld)\n", friendCoin[0]);
			printf("친구2 (전재산:%ld)\n", friendCoin[1]);
			printf("친구3 (전재산:%ld)\n", friendCoin[2]);
			scanf("%d", &l );

			if ( !(l == 1 || l == 2 || l == 3) ) {
				printf("너에겐 더 이상의 친구가 없단다...\n");
				getInput();
			}

			printf("(빌릴돈을 미리정하자)\n");
			scanf("%ld", &borrow );
			if (borrow > friendCoin[l-1]) {
				printf("친구: 잘가 나한텐 너무 큰돈이야)\n");
				getInput();
				break;
			}

			printf("나:돈좀 꿔줘\n친구%d:왜?\n나:파산위기여서 그래\n친구%d:얼마?\n나:%ld원만...", l, l, borrow);

			if (rand() % 2 == 1) {
				printf("미안...                  잘됐다.큭큭\n");          
				getInput();
				break;
			}
			
			printf("알겠어\n");
			coin += borrow;
			friendCoin[l-1] -=	borrow;	

			borrowCoin[l-1] += borrow;

			break;

		case 4:

			break;

		case 5:

			printf("----------------------------------\n");
			printf("|                                |\n");
			printf("|           ------|              |\n");
			printf("|           |t    |              |\n");
			printf("|           |  ------|           |\n");
			printf("|           |--| a   |           |\n");
			printf("|              |    x|           |\n");     
			printf("|              |------           |\n");
			printf("|          pay a tax             |\n");
			printf("|                                |\n");
			printf("|         tax:200000won          |\n");
			printf("|                                |\n");
			printf("|                                |\n");
			printf("|                                |\n");
			printf("----------------------------------\n");

			coin -= 200000;
			
			break;

         default:
			break;
	}

	day++;

	for ( int i = 0; i < 3; ++i ) {
		price[i] += rand() % (10 * price[i]) - price[i];
		if (price[i] == 0)
		{
			price[i]++;
		}
	}

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