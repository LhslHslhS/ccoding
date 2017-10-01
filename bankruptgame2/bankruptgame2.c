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
	char minerals[6];
	char meats[3];
} Player;

typedef struct {
	int x;
	int y;
	char name[100];
	int plant;
	int owner;
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

Player hyunseoPlayer = { 18, 40, 'H', 1000, 0, 0, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0 } };
Player chanhoPlayer = { 18, 41, 'C', 1000, 0, 0, { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0 } };

Land land1 = { 1, 7, "land1", 0, 3 };
Land land2 = { 1, 5, "land2", 0, 3 };
Land land3 = { 3, 5, "land3", 0, 3 };
Land land4 = { 3, 3, "land4", 0, 3 };
Land land5 = { 1, 3, "land5", 0, 3 };

Factory factory1 = { 8, 7, "factory1", 0, 0, 0, 0, 0, { 0, 0, 0, 0 }, 3 };
Factory factory2 = { 12, 7, "factory2", 0, 0, 0, 0, 0, { 0, 0, 0, 0 }, 3 };
Factory factory3 = { 8, 11, "factory3", 0, 0, 0, 0, 0, { 0, 0, 0, 0 }, 3 };
Factory factory4 = { 12, 11, "factory4", 0, 0, 0, 0, 0, { 0, 0, 0, 0 }, 3 };

ElectricFactory electricFactory1 = { 4, 7, "electricFactory1", 0, 0, 3 };
ElectricFactory electricFactory2 = { 4, 11, "electricFactory2", 0, 0, 3 };

Player players[2] = { hyunseoPlayer, chanhoPlayer };

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
		printf("Hit wall`\n");
		getInput();
	}

	players[turn].x = qx;
	players[turn].y = qy;

}

void process () {
	menu[0][cursor] = '.';
	cursor = (cursor + 1) % W;
	menu[0][cursor] = '+';

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