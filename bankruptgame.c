#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int coin;
	char name[20];
	int object;
} Player;

typedef struct {
	char name[20];
	int maximum;
	int successPercent;
	int percent;
} Country;

int turn = 0;

Player HyunseoPlayer = {30000, "Hyunseo", 0};
Player ChanhoPlayer  = {30000, "Chanho", 0};

Player players[2] = { HyunseoPlayer, ChanhoPlayer };

Country country1 = {"화합", 150, 80, 10};
Country country2 = {"평화", 100, 60, 40};
Country country3 = {"핵", 70, 40, 80};
Country country4 = {"멸망", 50, 20, 100};

Country countries[4] = { country1, country2, country3, country4 };

void squareGame() {

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

	tradingGame();
}