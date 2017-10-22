#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define W 56
#define H 26
#define MH 7

int GAME = 1;

char map[H][W+1];
char menu[MH][W+1];

int cursor = 0;

int turn = 0;
int tax = 0;


int maxTurn = 1000;

typedef struct {
	int x;
	int y;
	char name;
	int coin;
	int tax;
	char plant[2];
	char minerals[6];
	char Jewelry[10];
	int semiConductorSet;
	int wilding;
	int timer;
} Player;

typedef struct {
	int x;
	int y;
	char name[100];
	int plant;
	int grow;
	int owner;
	int growfast;
} Land;

typedef struct {
	int x;
	int y;
	char name[100];
	int plant;
	int grow;
	int owner;
	int growfast;
} Factory;

typedef struct {
	int x;
	int y;
	char name[100];
	int semiConductor;
	int semiConductorTime;
	int machines;
	int owner;
	int semiConductorMachine;
} ElectricFactory;

Player hyunseoPlayer = { 18, 40, 'H', 30000, 0,{ 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }, 0, 0, 0 };
Player chanhoPlayer = { 18, 41, 'C', 30000, 0,{ 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }, 0, 0, 0 };

Player players[2] = { hyunseoPlayer, chanhoPlayer };

Land land1 = { 7, 1, "land1", 0, 10, 2, 1 };
Land land2 = { 5, 1, "land2", 0, 10, 2, 1 };
Land land3 = { 5, 3, "land3", 0, 10, 2, 1 };
Land land4 = { 3, 3, "land4", 0, 10, 2, 1 };
Land land5 = { 3, 1, "land5", 0, 10, 2, 1 };

Land lands[5] = { land1, land2, land3, land4, land5 };

Factory factory1 = { 7, 8, "factory1", 0, 10, 2, 2 };
Factory factory2 = { 7, 12, "factory2", 0, 10, 2, 2 };
Factory factory3 = { 11, 8,  "factory3", 0, 10, 2, 2 };
Factory factory4 = { 11, 12, "factory4", 0, 10, 2, 2 };

Factory factories[4] = { factory1, factory2, factory3, factory4 };

ElectricFactory electricFactory1 = { 7, 4, "electricFactory1", 0, 0, 0, 2, 0 };
ElectricFactory electricFactory2 = { 11, 4, "electricFactory2", 0, 0, 0, 2, 0 };

ElectricFactory electricFactories[2] = { electricFactory1, electricFactory2 };

long long unsigned int prices[10] = {5000, 10000, 30000, 50000, 100000, 300000, 500000, 1000000, 3000000, 5000000};

void process();
void getInput();
void draw();
void playerInLand(int index);
void playerInRealEstate();
void playerInElectricFactory(int index);
void playerInFactory(int index);
void playerInWild();
void playerInCityHall();
void playerInJewelry();
void playerInCasino();


void playerInLand(int index){
	if (lands[index].owner == 1 - turn || lands[index].owner == 2)
	{
		printf("남의 땅입니다.\n");
	}else{
		int a;
		printf("1. 수확하기\n");
		printf("2. 심기\n");
		printf("3. 생성 가속하기 cost: 1000000\n");
		scanf("%d", &a);
		if (a == 1)
		{
			if (lands[index].grow == 10)
			{
				if (lands[index].plant == 0)
				{
					players[turn].plant[0] += 100;
					printf("성공적으로 수확하였습니다.\n");
					process();
				}else if (lands[index].plant == 1)
				{
					players[turn].plant[1] += 100;
					printf("성공적으로 수확하였습니다.\n");
					process();
				}
			}else if (lands[index].grow < 10)
			{
				printf("식물이 덜 자랐습니다.\n");
				playerInLand(index);
			}
		}else if (a == 2) {
			printf("1. 씨앗\n");
			printf("2. 감자\n");
			int b;
			scanf("%d", &b);
			if (players[turn].plant[b] < 1) {
				printf("심을 씨앗이 없습니다\n");
				playerInLand(index);
			} else if (players[turn].plant[b] >= 1) {
				lands[index].plant = b;
				printf("모두 심었습니다.\n");
				process();
			}
		}else if (a == 3)
		{
			if (players[turn].coin <	1000000)
				{
					printf("약을 살 돈이 없습니다.\n");
				}else{
					players[turn].coin -= 1000000;
					lands[index].growfast++;
					printf("약을 성공적으로 샀습니다.\n");
				}
		}
	}
}
void playerInElectricFactory(int index){
	if (electricFactories[index].owner == 1 - turn || electricFactories[index].owner == 2)
	{
		printf("남의 전기공장입니다.\n");
	}else{
		int a;
		printf("무엇을 하시겠습니까?\n");
		printf("1. 반도체 판매\n");
		printf("2. 공장 돌리기  반도체 세트X1\n");
		printf("3. 기계 구매\n");
		scanf("%d", &a);
		
		if (a == 1)
		{
			players[turn].coin += electricFactories[index].semiConductor * 408000;
			electricFactories[index].semiConductor = 0;
			printf("모두 판매하였습니다.\n");
		}else if (a == 2)
		{
			if (electricFactories[index].semiConductorMachine){
				players[turn].coin -= 1000000;
				players[turn].semiConductorSet += 10;
				if (players[ electricFactories[index].owner ].semiConductorSet > 0){
					if (electricFactories[index].semiConductorTime == 20){
						electricFactories[index].semiConductor++;
						players[ electricFactories[index].owner ].semiConductorSet--;
					}
				}
			}
		}else if (a == 3)
		{
			if (players[turn].coin < 1300000)
			{
				printf("돈이 부족합니다.\n");
			}else{
				players[turn].coin -= 1300000;
				electricFactories[index].semiConductorMachine += 1;
			}
		}

	}
}
void playerInFactory(int index){
	if (factories[index].owner == 1 - turn || factories[index].owner == 2)
	{
		printf("남의 공장입니다.\n");
	}else{
		int a;
		printf("1. 수확하기\n");
		printf("2. 심기\n");
		printf("3. 생성 가속하기 cost: 5000000\n");
		scanf("%d", &a);
		if (a == 1)
		{
			if (factories[index].grow == 10)
			{
				if (factories[index].plant == 0)
				{
					players[turn].plant[0] += 500;
					printf("성공적으로 수확하였습니다.\n");
					process();
				}else if (factories[index].plant == 1)
				{
					players[turn].plant[1] += 500;
					printf("성공적으로 수확하였습니다.\n");
					process();
				}
			}else if (factories[index].grow < 10)
			{
				printf("식물이 덜 자랐습니다.\n");
				playerInLand(index);
			}
		}else if (a == 2) {
			printf("1. 씨앗\n");
			printf("2. 감자\n");
			int b;
			scanf("%d", &b);
			if (players[turn].plant[b] < 5) {
				printf("심을 씨앗이 없습니다\n");
				playerInLand(index);
			} else if (players[turn].plant[b] >= 5) {
				factories[index].plant = b;
				printf("모두 심었습니다.\n");
				process();
			}
		}else if (a == 3)
		{
			if (players[turn].coin <	5000000)
				{
					printf("약을 살 돈이 없습니다.\n");
				}else{
					players[turn].coin -= 5000000;
					factories[index].growfast++;
					printf("약을 성공적으로 샀습니다.\n");
				}
		}
	}
}
void playerInRealEstate(){
	printf("무슨 땅을 사시겠습니까?\n");
	for ( int i = 0; i < 5; ++i ) {
		if (lands[i].owner == 0)
		{
			printf("%d번 땅 (주인: hyunseo)\n",i + 1 );
		}else if (lands[i].owner == 1)
		{
			printf("%d번 땅 (주인: chanho)\n",i + 1 );
		}else if (lands[i].owner == 2)
		{
			printf("%d번 땅 (주인: 없음)\n",i + 1 );
		}
	}
	for ( int i = 0; i < 2; ++i ) {
		if (electricFactories[i].owner == 0)
		{
			printf("%d번 전기공장 (주인: hyunseo)\n",i + 1 );
		}else if (electricFactories[i].owner == 1)
		{
			printf("%d번 전기공장 (주인: chanho)\n",i + 1 );
		}else if (electricFactories[i].owner == 2)
		{
			printf("%d번 전기공장 (주인: 없음)\n",i + 1 );
		}
	}
	for ( int i = 0; i < 4; ++i ) {
		if (factories[i].owner == 0)
		{
			printf("%d번 공장 (주인: hyunseo)\n",i + 1 );
		}else if (factories[i].owner == 1)
		{
			printf("%d번 공장 (주인: chanho)\n",i + 1 );
		}else if (factories[i].owner == 2)
		{
			printf("%d번 공장 (주인: 없음)\n",i + 1 );
		}
	}
	int i = 0;
	int o = 0; 
	printf("무엇을 사시겠습니까?\n");
	printf("1. 땅 (300000원)\n");
	printf("2. 공장 (2000000원)\n");
	printf("3. 전기공장 (30000000원)\n");
	scanf("%d", &i);
	printf("어떤 것을 사시겠습니까?\n");
	scanf("%d", &o);

	
	if (i == 1)
	{
		if (players[turn].coin < 300000)
		{
			printf("돈이 부족합니다.\n");
			getInput();
		}
		if (lands[o].owner == (1 - turn) || (lands[o].owner == turn))
		{
			printf("주인이 있습니다.\n" );
		}
		players[turn].coin -= 300000;
		lands[o].owner = turn;
		printf("결제완료 되었습니다.\n");
	}
	else if (i == 2)
	{
		if (players[turn].coin < 2000000)
		{
			printf("돈이 부족합니다.\n");
			getInput();
		}
		if (factories[o].owner == (1 - turn) || (factories[o].owner == turn))
		{
			printf("주인이 있습니다.\n" );
		}
		players[turn].coin -= 2000000;
		factories[o].owner = turn;
		printf("결제완료 되었습니다.\n");
	}
	else if (i == 3)
	{
		if (players[turn].coin < 30000000)
		{
			printf("돈이 부족합니다.\n");
			getInput();
		}
		if (electricFactories[o].owner == (1 - turn) || (electricFactories[o].owner == turn))
		{
			printf("주인이 있습니다.\n" );
		}
		players[turn].coin -= 30000000;
		electricFactories[o].owner = turn;
		printf("결제완료 되었습니다.\n");
	}
}
void playerInWild(){
	if (players[turn].coin < 15000)
	{
		printf("돈이 없습니다.\n");
		getInput();
	}
	players[turn].wilding = 1;
	int first;
	int thinkfirst;
	int second;
	int total = 0;
	int thinksecond;
	int percent;
	int minerals6 = 15 * 2500;
	int minerals5 = 15 * 2000;
	int minerals4 = 20 * 1000;
	int minerals3 = 30 * 250;
	int minerals2 = 64 * 125;
	int minerals1 = 300 * 5;
	int timer = players[turn].timer;
	for ( ; timer < 20; ) {
		percent = rand() % 3;
		first = rand() % 10;
		second = rand() % 10;
		printf("%d. 첫 번째 숫자를 적어주세요\n", timer + 1);
		scanf("%d", &thinkfirst);
		printf("%d. 두 번째 숫자를 적어주세요\n", timer + 1);
		scanf("%d", &thinksecond );
		if ( thinkfirst == first && thinksecond == second) {
			printf("에메랄드 입니다\n");
			total += minerals6;			
		} else if (thinkfirst == first ) {
			printf("다이아몬드 입니다\n");
			total += minerals5;
		} else if (thinksecond == second) {
			printf("금 입니다\n");
			total += minerals4;
		} else if (percent == 0) {
			printf("철 입니다\n");
			total += minerals3;
		} else if (percent == 1) {
			printf("석탄 입니다\n");
			total += minerals2;
		} else if (percent == 2) {
			printf("돌 입니다\n");
			total += minerals1;
		} 
		timer++;
		break;
	}
	players[turn].coin += total;
	printf("결제완료 되었습니다. 총: %d원\n", total);

	players[turn].timer = timer;
	
	if (players[turn].timer >= 20 ){	
		players[turn].wilding = 0;
		printf("야생시간이 끝났습니다.\n");
	}

}

void playerInCityHall(){
	if (tax == maxTurn){
		for ( int i = 0; i < 2; ++i ) {
			players[i].coin = players[i].coin / 20 * 19;
			printf("플레이어 %d 세금납부 완료\n",i + 1 );
			players[i].x = 22;
			players[i].y = 40;

		}
	}
	tax = 0;
}
void playerInJewelry(){
	
	
	printf("-----------------------------------\n" );
	printf("0.기념주화 가격: %llu\n",  prices[0] );
	printf("1.은 귀걸이 가격: %llu\n",  prices[1] );
	printf("2.금 팔찌 가격: %llu\n",  prices[2] );
	printf("3.다이아몬드 반지 가격: %llu\n", prices[3] );
	printf("4.에메랄드 목걸이 가격: %llu\n", prices[4] );
	printf("5.사파이어 머리핀 가격: %llu\n", prices[5] );
	printf("6.토파즈 브로치 가격: %llu\n", prices[6] );
	printf("7.루비 티아라 가격: %llu\n", prices[7] );
	printf("8.타파이트 트로피 가격: %llu\n",  prices[8] );
	printf("9.화려한 구슬 가격: %llu\n\n",  prices[9] );
	printf("-----------------------------------\n" );
	printf("무엇을 하시겠습니까?\n");
	printf("1. 사기\n");
	printf("2. 팔기\n");
	printf("-----------------------------------\n" );
	int z;
	int x;
	int y;
	scanf("%d", &z);
	if (z == 1)
	{
		printf("무엇을 사시겠습니까?\n");
		scanf("%d", &x);
		printf("몇개 사시겠습니까?\n");
		scanf("%d", &y);
		if (players[turn].coin < prices[x] * y)
		{
			printf("돈이 없어서 쫓겨났습니다.\n");
			playerInJewelry();
		}else{
			players[turn].coin -= prices[x] * y;
			players[turn].Jewelry[x] += y;
			printf("성공적 구매하였습니다.\n");
			getInput();
		}
	}else if (z == 2)
	{
		int u;
		int i;
		printf("무엇을 파시겠습니까?\n");
		scanf("%d", &u );
		printf("얼만큼 파시겠습니까?\n");
		scanf("%d", &i);
		if (players[turn].Jewelry[u] < i)
		{
			printf("보석이 부족합니다.\n");
			playerInJewelry();
		}else if (players[turn].Jewelry[u] >= i)
		{
			players[turn].coin += prices[u] * i;
			printf("성공적으로 판매하였습니다.\n");
			getInput();
		}
		
	}
}
void playerInCasino(){
	int x;
	int whoplayer = 0;
	int mc = 0;
	int sign = 1;
	printf("1. 나를 위한 도박\n");
	printf("2. 너만을 위한 도박\n");
	printf("3. 우리를 위한 도박\n");
	scanf("%d", &x);
	int casino[3] = { 5000, 300000, 100000 };
	if (players[turn].coin < casino[x - 1])
	{
		printf("돈을 준비해 오십시오...\n");
		getInput();
	}
		switch(x){
			case 1:
				players[turn].coin -= 50000;
				mc = rand() % 100000;
				whoplayer = turn;
				players[turn].coin += mc;
				break;
			case 2:
				players[turn].coin -= 200000;
				mc = rand() % 700000 - 300000;
				whoplayer = 1 - turn;
				players[1 - turn].coin += mc;
				break;
			case 3:
				players[turn].coin -= 100000;
				mc = rand() % 200000;
				whoplayer = rand() % 2;
				sign = ((float) (rand() % 2 - 0.5)) * 2;
				players[whoplayer].coin += sign * mc;
				break;
			default:
				break;
		}

		printf("%c의 돈이 %d만큼 추가되었습니다.\n",players[whoplayer].name , mc);
}
void setupMap () {
	memcpy( &map[0],  "||||||||||||||||||||||||||||||||||||||||||||||||||||||||", strlen("                                                        "));
	memcpy( &map[1],  "||||||||||||||||||||||||||||||||||||||||||||||||||||||||", strlen("                                                        "));
	memcpy( &map[2],  "||||||||||||||||||||||||||||||||        JJJJ        ||||", strlen("                                                        "));
	memcpy( &map[3],  "||||||||||||||||||||||||||||||||        YYYY        ||||", strlen("                                                        "));
	memcpy( &map[4],  "||||||||||||||||||||||||||||||||                    ||||", strlen("                                                        "));
	memcpy( &map[5],  "||||||||||||||||||||||||||||||||BBBBB   GGGGG   222 ||||", strlen("                                                        "));
	memcpy( &map[6],  "||||LLLL    LLLL||||||||||||||||BB  BB GG      22  2||||", strlen("                                                        "));
	memcpy( &map[7],  "||||5555    4444||||||||||||||||BBBBB  G   GGG    2 ||||", strlen("                                                        "));
	memcpy( &map[8],  "||||            ||||||||||||||||BB  BB GG    G  22  ||||", strlen("                                                        "));
	memcpy( &map[9],  "||||            ||||||||||||||||BBBBB   GGGGGG 22222||||", strlen("                                                        "));
	memcpy( &map[10], "||||LLLL    LLLL||||||||||||||||        CCCC        ||||", strlen("                                                        "));
	memcpy( &map[11], "||||2222    3333||||||||||||||||        CCCC        ||||", strlen("                                                        "));
	memcpy( &map[12], "||||            ||||||||||||||||                    ||||", strlen("                                                        "));
	memcpy( &map[13], "||||            ||||||||||||||||                    ||||", strlen("                                                        "));
	memcpy( &map[14], "||||LLLL    EEEEEEEEEEEEEEEE    FFFF            FFFF||||", strlen("                                                        "));
	memcpy( &map[15], "||||1111    1111DDDD11111111    1111            2222||||", strlen("                                                        "));
	memcpy( &map[16], "||||                                                ||||", strlen("                                                        "));
	memcpy( &map[17], "||||                                                ||||", strlen("                                                        "));
	memcpy( &map[18], "||||                                            WWWW||||", strlen("                                                        "));
	memcpy( &map[19], "||||                                            WWWW||||", strlen("                                                        "));
	memcpy( &map[20], "||||                                                ||||", strlen("                                                        "));
	memcpy( &map[21], "||||                                                ||||", strlen("                                                        "));
	memcpy( &map[22], "||||RRRR    EEEEDDDDEEEEEEEE    FFFF    CCCC    FFFF||||", strlen("                                                        "));
	memcpy( &map[23], "||||EEEE    2222222222222222    3333    HHHH    4444||||", strlen("                                                        "));
	memcpy( &map[24], "||||||||||||||||||||||||||||||||||||||||||||||||||||||||", strlen("                                                        "));
	memcpy( &map[25], "||||||||||||||||||||||||||||||||||||||||||||||||||||||||", strlen("                                                        "));	
}
void setup () {

	srand(time(NULL));

	for ( int i = 0; i < H; ++i ) {
		for ( int j = 0; j < W; ++j ) {
			map[i][j] = ' ';
		}
		map[i][W] = '\0';
	}
	for ( int i = 0; i < MH; ++i ) {
		for ( int j = 0; j < W; ++j ) {
			menu[i][j] = '.';
		}
		menu[i][W] = '\0';
	}

	setupMap();
}
void draw () {

	printf("세금 납부까지: %d\n",1000 - tax);
	printf("플레이어1 %d원\n", players[0].coin);
	printf("플레이어2 %d원\n", players[1].coin);

	setupMap();

	for ( int i = 0; i < 2; ++i ) {
		map[players[i].x][players[i].y] = players[i].name;
	}

	for ( int j = 0; j < W+2; ++j ) {
		printf("*");
	}
	printf("\n");

	for ( int i = 0; i < H; ++i ) {
		printf("*%s*\n", map[i]);
	}

	for ( int j = 0; j < W+2; ++j ) {
		printf("*");
	}
	printf("\n");
}
void getInput () {

	printf("Player: %c\n", players[turn].name);

	if (players[turn].wilding == 1)
	{
		playerInWild();
		return;
	}

	char inputSentense[10];
	scanf("%s", inputSentense);

	char input = inputSentense[0];

	int px = players[turn].x;
	int py = players[turn].y;

	int qx = px;
	int qy = py;

	if ( input == 'w' || input == 'i' ) {
		qx--;
	} else if ( input == 's' || input == 'k' ) {
		qx++;
	} else if ( input == 'a' || input == 'j' ) {
		qy--;
	} else if ( input == 'd' || input == 'l' ) {
		qy++;
	}

	if ( map[qx][qy] == '|' ) {
		getInput();
	}


	for ( int i = 0; i < 5; ++i ) {
		if ( (qx/2 == lands[i].x) && (qy/4 == lands[i].y) ) {
			playerInLand( i );
		}
	}

	for ( int i = 0; i < 4; ++i ) {
		if ( (qx/2 == factories[i].x) && (qy/4 == factories[i].y) ) {
			playerInFactory( i );
		}
	}

	for ( int i = 0; i < 2; ++i ) {
		if ( (qx/2 == electricFactories[i].x) && (qy/4 == electricFactories[i].y) ) {
			playerInElectricFactory( i );
		}
	}
	if ( (qx/2 == 1) && (qy/4 == 10) )
	{
		playerInJewelry();
	}

	if ( (qx/2 == 5) && (qy/4 == 10) )
	{
		playerInCasino();
	}

	if ( (qx/2 == 11) && (qy/4 == 1))
	{
		playerInRealEstate();
	}

	if ( (qx/2 == 9) && (qy/4 == 12) )
	{
		playerInWild();
	}


	players[turn].x = qx;
	players[turn].y = qy;
}
void process () {
	menu[0][cursor] = '.';
	cursor = (cursor + 1) % W;
	menu[0][cursor] = '+';

	for ( int i = 0; i < 5; ++i ) {
		lands[i].grow++;
		if (lands[i].growfast == 1){
		lands[i].grow++;
		}
	}

	for ( int i = 0; i < 2; ++i ) {
		electricFactories[i].semiConductorTime++;
		if (electricFactories[i].semiConductorTime >= 20) {
			electricFactories[i].semiConductorTime = 0;
		}
	}

	for ( int i = 0; i < 10; ++i ) {
		int percent = rand() % 140 + 40; 
		prices[i] = (prices[i] * percent) / 100;
	}

	tax++;

	if (tax == maxTurn)
	{
		printf("세금을 납부하기 위해 시청으로 이동시키겠습니다.\n");
		playerInCityHall();
	}
	if (players[turn].coin < 0)
	{
		printf(" GAME OVER \n" );
		printf(" 플래이어 %c의 승리입니다.\n" ,players[1-turn].name);
		GAME = 0;
	}

	turn = 1 - turn;
}
int main () {

	setup();

	while (GAME) {

		draw();
		getInput();
		process();

	}

	return 0;
}