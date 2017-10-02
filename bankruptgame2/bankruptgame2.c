#include <stdio.h>
#include <string.h>

#define W 56
#define H 26
#define MH 7

int GAME = 1;

char map[H][W+1];
char menu[MH][W+1];

int cursor = 0;

int turn = 0;

typedef struct {
	int x;
	int y;
	char name;
	int coin;
	int job;
	int tax;
	char plant[2];
	char minerals[6];
	char meats[3];
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
	int plant1;
	int plant2;
	int plant3;
	int plant4;
	int plant5;
	char animals[4];
	int owner;
} Factory;

typedef struct {
	int x;
	int y;
	char name[100];
	int semiConductor;
	int machines;
	int owner;
} ElectricFactory;

Player hyunseoPlayer = { 18, 40, 'H', 30000, 0, 0,{ 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0 } };
Player chanhoPlayer = { 18, 41, 'C', 30000, 0, 0,{ 0, 0 }, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0 } };

Player players[2] = { hyunseoPlayer, chanhoPlayer };

Land land1 = { 7, 1, "land1", 0, 10, 0, 0 };
Land land2 = { 5, 1, "land2", 0, 10, 1, 0 };
Land land3 = { 5, 3, "land3", 0, 10, 3, 0 };
Land land4 = { 3, 3, "land4", 0, 10, 3, 0 };
Land land5 = { 3, 1, "land5", 0, 10, 3, 0 };

Land lands[5] = { land1, land2, land3, land4, land5 };

Factory factory1 = { 7, 8, "factory1", 0, 0, 0, 0, 0, { 0, 0, 0, 0 }, 3 };
Factory factory2 = { 7, 12, "factory2", 0, 0, 0, 0, 0, { 0, 0, 0, 0 }, 3 };
Factory factory3 = { 11, 8,  "factory3", 0, 0, 0, 0, 0, { 0, 0, 0, 0 }, 3 };
Factory factory4 = { 11, 12, "factory4", 0, 0, 0, 0, 0, { 0, 0, 0, 0 }, 3 };

Factory factories[4] = { factory1, factory2, factory3, factory4 };

ElectricFactory electricFactory1 = { 7, 4, "electricFactory1", 0, 0, 3 };
ElectricFactory electricFactory2 = { 11, 4, "electricFactory2", 0, 0, 3 };

ElectricFactory electricFactories[2] = { electricFactory1, electricFactory2 };

void process();
void getInput();
void draw();
void playerInLand(int index);
void playerInRealEstate();
void playerInElectricFactory(int index);
void playerInFactory(int index);
void playerInWild();
void playerInCityHall();
void playerInJob();
void playerInJewelry();
void playerInCasino();
void playerInMarket();


void playerInLand(int index){
	if (lands[index].owner == 1 - turn)
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
	printf("%d hello electricFactory\n", index);
}
void playerInFactory(int index){
	printf("%d hello Factory\n", index);
}
void playerInRealEstate(){
	printf("hello RealEstate\n");
}
void playerInWild(){
	printf("hello Wild\n");
}
void playerInCityHall(){
	printf("hello CityHall\n");
}
void playerInJob(){
	printf("hello Job\n");
}
void playerInJewelry(){
	printf("hello Jewelry\n");
}
void playerInCasino(){
	printf("hello Casino\n");
}
void playerInMarket(){
	printf("hello Market\n");
}
	

void setupMap () {

	memcpy( &map[0],  "||||||||||||||||||||||||||||||||||||||||||||||||||||||||", strlen("                                                        "));
	memcpy( &map[1],  "||||||||||||||||||||||||||||||||||||||||||||||||||||||||", strlen("                                                        "));
	memcpy( &map[2],  "||||||||||||||||||||||||||||||||        JJJJ        ||||", strlen("                                                        "));
	memcpy( &map[3],  "||||||||||||||||||||||||||||||||        YYYY        ||||", strlen("                                                        "));
	memcpy( &map[4],  "||||||||||||||||||||||||||||||||                    ||||", strlen("                                                        "));
	memcpy( &map[5],  "||||||||||||||||||||||||||||||||                    ||||", strlen("                                                        "));
	memcpy( &map[6],  "||||LLLL    LLLL||||||||||||||||JJJJ            MMMM||||", strlen("                                                        "));
	memcpy( &map[7],  "||||5555    4444||||||||||||||||BBBB            MMMM||||", strlen("                                                        "));
	memcpy( &map[8],  "||||            ||||||||||||||||                    ||||", strlen("                                                        "));
	memcpy( &map[9],  "||||            ||||||||||||||||                    ||||", strlen("                                                        "));
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

	for ( int i = 0; i < MH; ++i ) {
		printf("*%s*\n", menu[i]);
	}

	for ( int j = 0; j < W+2; ++j ) {
		printf("*");
	}
	printf("\n");


}

void getInput () {
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


	players[turn].x = qx;
	players[turn].y = qy;

}

void process () {
	menu[0][cursor] = '.';
	cursor = (cursor + 1) % W;
	menu[0][cursor] = '+';

	turn = 1 - turn;
	for ( int i = 0; i < 5; ++i ) {
		lands[i].grow++;
		if (lands[i].growfast == 1){
		lands[i].grow++;
		}
	}
	
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