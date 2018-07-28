#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int GAME = 0;

int playerCoin[2] = {1110, 1116};

int factory[10][4] = {{0, 1, 0, 1}, 
					  {0, 0, 0, 1},
					  {0, 0, 0, 1},
					  {0, 0, 0, 1},
					  {0, 0, 0, 1},
					  {0, 1, 1, 1},
					  {0, 0, 1, 1},
					  {0, 0, 1, 1},
					  {0, 0, 1, 1},
					  {0, 0, 1, 1}};

int turn = 0;

int input;

int ramdomNumber;

int stock[5][2] = {{1, 50},
				   {3, 50},
				   {5, 50},
				   {10, 50},
				   {25, 50}};

int disaster[3] = {0, 0, 3};

int number;

int betting;

int price = 1;

int first;

void dobak(){
	printf("베팅할 돈을 정해주십시오.\n");
	usleep(500000);
	scanf("%d", &betting );
	if (betting > playerCoin[turn]) {
		printf("돈이 부족합니다.\n");
		usleep(500000);
		printf("lobby로 이동합니다.\n");
		usleep(500000);
		printf("loading");
		usleep(500000);
		printf("." );
		usleep(500000);
		printf("." );
		usleep(500000);
		printf(".\n" );
		return;

	}
	playerCoin[turn] -= betting;
	printf("베팅금이 빠져나갔습니다.\n");
	usleep(500000);
	first = betting;
	price = first;
	if (playerCoin[turn] < 5)
	{
		printf("돈이 부족합니다.\n");
		return;
	}
	printf("돈이 빠져나갑니다.\n");
	usleep(500000);
	playerCoin[turn] -= 5;
	do
	{
		printf("숫자를 정해주십시오.\n");
		usleep(500000);
		printf("0      or      1\n");
		usleep(500000);
		scanf("%d", &number);
		printf("결정되었습니다.\n");
		usleep(500000);
		printf("랜덤 숫자가 정해집니다.\n");
		usleep(500000);
		ramdomNumber = rand() % 2;
		printf("랜덤 숫자: %d \n",ramdomNumber );
		usleep(500000);
		if (number == ramdomNumber)
		{
			GAME = 1; 
			printf("일치합니다.\n");
			usleep(500000);
			printf("가격이 2배 되었습니다.\n");
			price *= 2;
			printf("현재 가격: %d \n", price);
			usleep(500000);
			
		}
	} while (number == ramdomNumber);
	printf("입금 중입니다.\n");
	printf("총: %d\n", price - first);
	usleep(500000);
	playerCoin[turn] += price - first; 
	printf("입금이 완료되었습니다.\n");
	usleep(500000);
	price = 0;
};


void jusik(){};
void UpOrDown(){
	printf("살 떡상/떡락아이템을 정해주십시오.\n");
	usleep(500000);
	printf("1. 떡상 아이템\n");
	printf("2. 떡락 아이템\n");
	
};
void jaeang(){};
void gongguck(){};

void getInput(){
	
	if (turn == 0) {
		printf("Turn: Player H\n");
	}else if (turn == 1) {
		printf("Turn: Player C\n");
	}
	printf("Player H: %d\n", playerCoin[0]);
	printf("Player A: %d\n", playerCoin[1]);
	printf("----------------------------------------\n");
	printf("1. 도박 5금\n");
	printf("2. 주식 \n");
	printf("3. 떡상 / 떡락\n");
	printf("4. 재앙\n");
	printf("5. 공격\n");
	printf("----------------------------------------\n");
	scanf("%d", &input);
	if (input == 1)
	{
		dobak();
	}else if (input == 2)
	{
		jusik();
	}else if (input == 3)
	{
		UpOrDown();		
	}else if(input == 4)
	{
		jaeang();
	}else if (input == 5)
	{
		gongguck();
	}
	turn = 1 - turn;
	usleep(500000);
	printf("턴이 바뀝니다.\n" );
	return;
	
};

int main()
{
	srand(time(NULL));
	int x;
	do {
		getInput();
	} while (GAME == 0);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	char alphabets[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	printf("게임이 충돌했습니다.\n");
	printf("오류 코드: ");
	for (int i = 0; i < 10; ++i) {

		x = rand() % 62;
		printf("%c", alphabets[x] );
	}
	printf("\n");
	
	
	printf("자세히 www.factoryGame.com/error?g=");
	for (int i = 0; i < 10; ++i) {

		x = rand() % 62;
		printf("%c", alphabets[x] );
	}
	printf("\n");



	


	return 0;
}