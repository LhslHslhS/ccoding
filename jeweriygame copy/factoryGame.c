#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playerCoin[2] = {0, 0};

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

int jusik[5][2] = {{1, 50},
				   {3, 50},
				   {5, 50},
				   {10, 50},
				   {25, 50}};

int jaeang[3] = {0, 0, 3};

int number;

int price = 1;

void dobak(){
	if (playerCoin[turn] < 15)
	{
		printf("돈이 부족합니다.\n");
	}
	printf("돈이 빠져나갑니다.\n");
	sleep(100);
	playerCoin -= 15;
	do
	{
		printf("숫자를 정해주십시오.\n");
		sleep(100);
		printf("0      or      1\n");
		sleep(100);
		printf("결정되었습니다.\n");
		sleep(100);
		scanf("%d", number);
		printf("랜덤 숫자가 정해집니다.\n");
		sleep(100);
		int ramdomNumber = rand() % 2;
		printf("랜덤 숫자: %d \n",ramdomNumber );
		sleep(100);
		if (number = ramdomNumber)
		{
			printf("일치합니다.\n");
			sleep(100);
			printf("가격이 2배 되었습니다.\n");
			price *= 2;
			printf("현재 가격: %d \n", price);
			sleep(100);
		}
	} while (number = ramdomNumber);
	printf("입금 중입니다.\n");
	sleep(100);
	playerCoin[turn] += price; 
	printf("입금이 완료되었습니다.\n");
	sleep(100);

};

void jusik(){};
void UpOrDown(){
	printf("살 떡상/떡락아이템을 정해주십시오.\n");
	sleep(100);
	printf("1. 떡상 아이템\n");
	printf("2. 떡락 아이템\n");
	
};
void jaeang(){};
void gongguck(){};

void getInput(){
	int input;
	printf("----------------------------------------\n");
	printf("1. 도박 15금\n");
	printf("2. 주식 \n");
	printf("3. 떡상 / 떡락\n");
	printf("4. 재앙\n");
	printf("5. 공격\n");
	printf("----------------------------------------\n");
	scanf("%d", input);
	if (input == 1)
	{
		dobak();
		break;
	}else if (input == 2)
	{
		jusik();
		break;
	}else if (input == 3)
	{
		UpOrDown();		
		break;
	}else if(input == 4)
	{
		jaeang();
		break;
	}else if (input == 5)
	{
		gongguck();
		break;
	}
};

int main()
{
	getInput();
	return 0;
}