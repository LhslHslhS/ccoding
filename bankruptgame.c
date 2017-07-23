#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	long long coin;
	char name[20];
	int object;
	int factoryIndex;
	int count[3];
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

int price[3] = { 1000, 2000, 5000 };
char name[3][100] = { "사성주식", "LPG주식", "microhard" };
int input;
int warning = 0;

int j, k, l;

int percent[3] = {0 , 0 , 0};

Player HyunseoPlayer = {30000 , "Hyunseo", 0, 0, { 0, 0, 0 }};
Player ChanhoPlayer  = {30000, "Chanho ", 0, 0, { 0, 0, 0 }};

Player players[2] = { HyunseoPlayer, ChanhoPlayer };

Country country1 = {"화합", 150, 80, 10};
Country country2 = {"평화", 100, 60, 40};
Country country3 = {"핵", 70, 40, 80};
Country country4 = {"멸망", 50, 20, 100};

Country countries[4] = { country1, country2, country3, country4 };

Factory factories[2][10];

// Functions
int main();
void squareGame();
void casinoGame();
void raffleGame();
void tradingGame();
void changeturn();

void stockGame();
void factoryGame();
void marketGame();

void stockChange() {
	  price[0] += rand() % 5000 - 2500;
	  price[1] += rand() % 8000 - 4000;
	  price[2] += rand() % 12000 - 6000;
	  for ( int i = 0; i < 3; ++i ) {
	  	if (price[i] < 0 )
	  	{
	  		price[i] = price[i] * (-1);
	  	}
	  	if(price[i] < 750){
	  		price[i] += 750;
	  	}
	  }

}

void changeturn(){
	
	printf("턴이 바뀝니다.\n");
	for ( int x = 0; x < players[turn].factoryIndex; ++x ) {
		  players[turn].coin += factories[turn][x].money;
	}
	stockChange();
	turn = 1 - turn;
	if (players[turn].coin < 0 )
	{
		printf("%s님 이승리 하셨습니다.\n", players[1-turn].name);
		return 0;
	}
	main();
}

void stockGame(){
	printf("자본:%lld원\n", players[turn].coin);
	printf("------------------------------------\n");
	printf("1.사성주식: %d 		%d개\n" , price[0], players[turn].count[0]);
	printf("2.LPG주식: %d 		%d개\n",price[1], players[turn].count[1]);
	printf("3.microhard주식: %d 		%d개\n",price[2], players[turn].count[2]);
	printf("-----------------------------------\n");
	printf("1.주식 매입\n");
	printf("2.주식 판매\n");
	printf("-----------------------------------\n");

	scanf("%d", &input );


	switch (input) {
		case 1:

			printf("매입 주식을 설정 하여주세용. 개수 설정\n");
			scanf("%d %d", &j, &k );

			if ( k * price[j-1] > players[turn].coin) {
				printf("프로그램: 주식 한개를 파십시오.\n      안 그러면 쫓겨납니다...\n");
				break;
			}

			players[turn].count[j-1] += k;
			players[turn].coin -= k * price[j-1];
			printf("완료되었습니다.\n");
			

			break;

		case 2:
			printf("판매 주식을 설정 하여주세용. 개수 설정\n");
			scanf("%d %d", &j, &k );


			if ( k > players[turn].count[j-1])
			{
				printf("프로그램: 사기 치지마 \n      경찰에 신고한다\n");
				break;
			}

			players[turn].count[j-1] -= k;
			players[turn].coin += k * price[j-1];
			

			
			break;
		}
}

void factoryGame() {
	int factorySell;
	int factorySell2;
	printf("공장을 파시겠습니까?\n판다: 1\n안판다: 2\n");
	scanf("%d", &factorySell);
	if (factorySell == 1)
	{
		printf("뭘 파시겠습니까?\n");
		if (players[turn].factoryIndex == 0)
		{
			printf("공장이 없습니다.\n");
			squareGame();
		}
		for ( int x = 0; x < players[turn].factoryIndex; ++x )
			printf("이름:%d 레벨:%d 업그레이드 비용:%d\n", factories[turn][x].index, factories[turn][x].level, factories[turn][x].moneyForUpgrade );
		scanf("%d",&factorySell2 );
		players[turn].coin += factories[turn][factorySell2].level * 100000;
		players[turn].factoryIndex -= 1;
	}else{
		squareGame();
	}
}

void marketGame() {
	int factory;
	printf("뭘 이용하시겠습니까?\n");
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
			printf("공장이름은 %d입니다.\n", players[turn].factoryIndex);

			Factory tempFactory = { players[turn].factoryIndex, 1, 10000, 400000 };

			factories[turn][players[turn].factoryIndex] = tempFactory;

			players[turn].factoryIndex++;
			printf("처리 되었습니다.\n");
			
		}
	}else if (factory == 2)
	{
		int factoryUpgrade;
	
		printf("업그레이드할 공장을 골라주세요(공장이름을 써주세요)\n");
		for ( int x = 0; x < players[turn].factoryIndex; ++x ) {
			printf("이름:%d 레벨:%d 업그레이드 비용:%d\n", factories[turn][x].index, factories[turn][x].level, factories[turn][x].moneyForUpgrade );
		}
		scanf("%d", &factoryUpgrade );
		if ( (0 > factoryUpgrade || factoryUpgrade > players[turn].factoryIndex)
			 || (players[turn].coin < factories[turn][factoryUpgrade].moneyForUpgrade) ) {
			printf("조건불충족\n");
			squareGame();
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

	
	printf("돈: %lld\n", players[turn].coin);
	printf("            |------------|           \n");
	printf("            |            |           \n");
	printf("            |   stock    |           \n");
	printf("            |     w      |           \n");
	printf("------------|            |------------\n");
	printf("|                        |||||||||||||\n");
	printf("|                        |||||||||||||\n");
	printf("|  Factory      choose   |||nothing|||\n");
	printf("|     a        %s   ||||||d||||||\n",players[turn].name);
	printf("|                        |||||||||||||\n");
	printf("------------|            |------------\n");
	printf("            |            |           \n");
	printf("            |   market   |           \n");
	printf("            |      s     |           \n");
	printf("            |------------|           \n");

	
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

	printf("카지노시작!\n");
	int casinoplayer = rand() % 2;
	int sign = rand() % 2;
	int money = rand() % 100000;
	if (casinoplayer == turn)
	{
		printf("나\n");
		if (sign == 1) {
			printf("+\n");
			players[turn].coin += money;
			printf("%d\n",money );
		}else{
			printf("-\n");
			players[turn].coin -= money;
			printf("%d\n",money );
		}
	}else{
		printf("상대방\n");
		if (sign == 1) {
			printf("+\n");
			players[1 - turn].coin += money;
			printf("%d\n",money );
		}else{
			printf("-\n");
			players[1 - turn].coin -= money;
			printf("%d\n",money );
		}
	}

} 
void raffleGame() {
	int rafflecoin;
	printf("가격를 적어주십시오.\n");
	scanf("%d",&rafflecoin);
	if (10 * rafflecoin > players[turn].coin)
	{
		printf("돈 부족 \n");
		raffleGame();
	}else{
		players[turn].coin -= rafflecoin * 5;
		int money = rand() % 10;
		players[turn].coin += rafflecoin * money;
		printf("결제 되었습니다. 이익:%d\n", rafflecoin * 5 - (10-money) * rafflecoin );
		}
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

		printf("현재 재산: %lld원\n",players[turn].coin );
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
		players[turn].object -= inputObjectCount;

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
		if (success == 1)
		{
			printf("무역의 성공으로\n" );
		}else{
			printf("무역의 실패로\n");
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

	srand(time(NULL));
	printf("돈: %lld\n", players[turn].coin);
	printf("            |------------|           \n");
	printf("            |            |           \n");
	printf("            |   square   |           \n");
	printf("            |      w     |           \n");
	printf("------------|            |------------\n");
	printf("|                                    |\n");
	printf("|                                    |\n");
	printf("|  casino       choose      trading  |\n");
	printf("|     a        %s         d     |\n",players[turn].name);
	printf("|                                    |\n");
	printf("------------|            |------------\n");
	printf("            |            |           \n");
	printf("            |   raffle   |           \n");
	printf("            |      s     |           \n");
	printf("            |------------|           \n");
	scanf("%s", inputStart );
	
	if (inputStart[0] == 'w')
	{
		squareGame();
	}else if (inputStart[0] == 'a')
	{
		casinoGame();
	}else if (inputStart[0] == 's')
	{
	 	raffleGame();
	}else if (inputStart[0] == 'd')
	{
	 	tradingGame();
	}else{
	 	main();
	}

	changeturn();
	
}