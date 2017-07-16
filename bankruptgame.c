#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int coin;
	char name[20];
	int object;
	char count[100];
} Player;

typedef struct {
	char name[20];
	int maximum;
	int successPercent;
	int percent;
} Country;

typedef struct {
	int index;
	int level;
	int money;
	int moneyForUpgrade;
} Factory;

int turn = 0;

int count[3] = { 0, 0, 0 };
int price[3] = { 1000, 2000, 5000 };
char name[3][100] = { "사성주식", "LPG주식", "microhard" };
int input;
int warning = 0;

int j, k, l;

int percent[3] = {0 , 0 , 0};

Player HyunseoPlayer = {30000000, "Hyunseo", 0};
Player ChanhoPlayer  = {30000, "Chanho", 0};

Player players[2] = { HyunseoPlayer, ChanhoPlayer };

Country country1 = {"화합", 150, 80, 10};
Country country2 = {"평화", 100, 60, 40};
Country country3 = {"핵", 70, 40, 80};
Country country4 = {"멸망", 50, 20, 100};

Country countries[4] = { country1, country2, country3, country4 };

Factory factories[2][10];

int factoryIndex[2] = { 0, 0 };

// Functions
int main();
void squareGame();
void casinoGame();
void realEstateGame();
void tradingGame();
void changeturn();

void stockGame();
void factoryGame();
void marketGame();

void changeturn(){
	turn = 1 - turn;
	printf("턴이 바뀝니다.\n");
	main();
}

void stockGame(){
	printf("-----------------------------------\n");
	printf("1.주식 매입\n");
	printf("2.주식 판매\n");
	printf("-----------------------------------\n");

	scanf("%d", &input );


	switch (input) {
		case 1:
			printf("자본:%d원\n", players[turn].coin);
			printf("------------------------------------\n");
			printf("1.사성주식: 1000 		%d개\n",count[0]);
			printf("2.LPG주식: 2000 		%d개\n",count[1]);
			printf("3.microhard주식: 5000 		%d개\n",count[2]);
			printf("매입 주식을 설정 하여주세용. 개수 설정\n");
			scanf("%d %d", &j, &k );

			if ( k * price[j-1] > players[turn].coin) {
				printf("프로그램: 주식 한개를 파십시오.\n      안 그러면 쫓겨납니다...\n");
				squareGame();
			}

			count[j-1] += k;
			players[turn].coin -= k * price[j-1];
			printf("완료되었습니다.\n");


			break;

		case 2:
			printf("판매 주식을 설정 하여주세용. 개수 설정\n");
			scanf("%d %d", &j, &k );


			if ( k > count[j-1])
			{
				printf("프로그램: 사기 치지마 \n      경찰에 신고한다\n");
				squareGame();
			}

			count[j-1] -= k;
			players[turn].coin += k * price[j-1];
			

			stockGame();
			break;
		}
}

void factoryGame() {

}

void marketGame() {
	int factory;
	printf("뭘 이용하시겠드습니까?\n");
	printf("1.공장사기 500000원\n");
	printf("2.공장업그레이드\n");
	scanf("%d",&factory );
	if (factory == 1)
	{
		if (players[turn].coin < 500000)
		{
			printf("돈이 부족합니다.\n");
			squareGame();
		}else{
			players[turn].coin -= 500000;
			printf("공장이름은 %d입니다.\n", factoryIndex[turn]);

			Factory tempFactory = { factoryIndex[turn], 1, 10000, 400000 };

			factories[turn][factoryIndex[turn]] = tempFactory;

			factoryIndex[turn]++;
			printf("처리 되었습니다.\n");
			
		}
	}else if (factory == 2)
	{
		int factoryUpgrade;
	
		printf("업그레이드할 공장을 골라주세요(공장이름을 써주세요)\n");
		for ( int x = 0; x < factoryIndex[turn]; ++x ) {
			printf("이름:%d 레벨:%d 업그레이드 비용:%d\n", factories[turn][x].index, factories[turn][x].level, factories[turn][x].moneyForUpgrade );
		}
		scanf("%d", &factoryUpgrade );
		if ( (0 > factoryUpgrade || factoryUpgrade > factoryIndex[turn])
			 || (players[turn].coin < factories[turn][factoryUpgrade].moneyForUpgrade) ) {
			printf("조건불충족\n");
			marketGame();
			return;
		}
		players[turn].coin -= factories[turn][factoryUpgrade].moneyForUpgrade;
		factories[turn][factoryUpgrade].level++;
		factories[turn][factoryUpgrade].money += 10000;
		printf("업그레이드 되었습니다\n");
	}
}

void squareGame() {
	char inputSquare[10];

	printf("이동할지역을 선택해주세요.\n");
	printf("w:주식\na:공장\ns:상점\nd:추후 공개예정\n");
	scanf("%s", inputSquare);

	if (inputSquare[0] == 'w')
	{
		stockGame();
	}else if (inputSquare[0] == 'a')
	{
		factoryGame();
	}else if (inputSquare[0] == 's')
	{
		marketGame();
	}else if (inputSquare[0] == 'd')
	{
		printf("아\n무\n것\n도\n없\n음\n");
		squareGame();
	}else{
		squareGame();
	}



}



void casinoGame() {

} 
void realEstateGame() {

}
void tradingGame() {
	int success = 0;
	int inputSelect;
	int inputCountrySelect;
	int inputObjectCount;
	int inpatObjectCount;

	printf("무역을 하시겠습니까? 1을 누르세요.\n");
	printf("물건을 사시겠습니까? 2를 누르세요.\n");
	scanf("%d",&inputSelect );
	if (inputSelect == 1){

		printf("현재 재산: %d원\n",players[turn].coin );
		printf("현재 물건개수: %d개\n",players[turn].object);
		printf("나라1: %2s국 최대수출개수: %3d개 성공확률: %d%% 이익: %3d%%\n", country1.name, country1.maximum, country1.successPercent, country1.percent);
		printf("나라2: %2s국 최대수출개수: %3d개 성공확률: %d%% 이익: %3d%%\n", country2.name, country2.maximum, country2.successPercent, country2.percent);
		printf("나라3: %2s  국 최대수출개수: %3d개 성공확률: %d%% 이익: %3d%%\n", country3.name, country3.maximum, country3.successPercent, country3.percent);
		printf("나라4: %2s국 최대수출개수: %3d개 성공확률: %d%% 이익: %3d%%\n", country4.name, country4.maximum, country4.successPercent, country4.percent);
		printf("수출국을 골라주세요.\n");
		scanf("%d",&inputCountrySelect);

		printf("물건개수를 정해주세요.\n");
		scanf("%d",&inputObjectCount );

		if ( (inputObjectCount > players[turn].object && inputObjectCount > countries[inputCountrySelect - 1].maximum)
			 || (inputCountrySelect > 4 || inputCountrySelect < 1) )
		{
			printf("안녕히가세요\n");
			tradingGame();
			return;
		}

		if (inputCountrySelect == 1){
			if (rand() % 5 == 0)
			{
				success = 0;
			}
		}else if (inputCountrySelect == 2){
			if (rand() % 5 < 2)
			{
				success = 0;
			}
		}else if (inputCountrySelect == 3){
			if (rand() % 5 < 2)
			{
				success = 1;
			}
		}else if (inputCountrySelect == 4){
			if (rand() % 5 == 0)
			{
				success = 1;
			}
		}
		players[turn].coin += success * countries[inputCountrySelect - 1].successPercent * inputObjectCount * 1000;
		printf("결제가 끝났습니다.\n");
	}else{
		printf("물건개수를 정해주세요. 개당 천원\n");
		scanf("%d",&inpatObjectCount );
		if (inpatObjectCount * 1000 > players[turn].coin)
		{
			printf("안녕히가세요\n");
			tradingGame();
			return;
		}else{
			players[turn].object += inpatObjectCount;
			players[turn].coin -= inpatObjectCount * 1000;
		}
	}

}

int main () {

	char inputStart[10];

	printf("이동할지역을 선택해주세요.\n");
	printf("w:광장\na:도박장\ns:부동산\nd:무역\n" );
	scanf("%s", inputStart );
	
	if (inputStart[0] == 'w')
	{
		squareGame();
	}else if (inputStart[0] == 'a')
	{
		casinoGame();
	}else if (inputStart[0] == 's')
	{
		realEstateGame();
	}else if (inputStart[0] == 'd')
	{
		tradingGame();
	}else{
		main();
	}

	changeturn();
	
}