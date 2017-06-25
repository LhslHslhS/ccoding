#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define R 15
#define C 43

typedef struct {
	char name[10];
	int type;
	int durability;
	int strength;
	char enchantName[20];
	bool didEnchant;
} Sword;

typedef struct {
	char name[10];
	int type;
	int duration;
} Potion;
 
typedef struct {
	int x;
	int y;
	char name;
	int coin;
	int items[3];
	int probability;
	int castleCount;
	Sword sword;
	int moves;
	int turnCount;
	int maxTurnCount;
	char enchantName[20];
	int statPiece;
	int statPearl;
	Potion potion;
	bool isUsingPotion;
	int job;
} Player;

typedef struct {
	int x;
	int y;
	char name;
	char fullName[10];
	int lives;
	int rotation;
	char owner;
} Castle;

typedef struct {
	int x;
	int y;
	char name;
} Tile;

typedef struct {
	int x;
	int y;
	char name;
	char owner;
	int coin;	
	int turn;
} Safe;

Sword Diamond = { "다이아", 4, 2, 60, "", false };
Sword Iron = { "철", 3, 3, 45, "", false };
Sword Stone = { "돌", 2, 4, 30, "", false };
Sword Wood = { "나무", 1, 5, 15, "", false };
Sword Fist = { "주먹", 0, -1, 0, "", false };

Sword swords[4] = { Diamond, Iron, Stone, Wood };

Potion Swiftness = { "신속", 5, 10 };
Potion Power = { "힘", 4, 10 };
Potion Resistence = { "저항", 3, 5 };
Potion Healing = { "회복", 2, 1 };
Potion Regeneration = { "강화", 1, 10 };
Potion Mundane = {"이상한", 0, -1 };

Potion potions[5] = { Swiftness, Power, Resistence, Healing, Regeneration };

Player HyunseoPlayer = { R/2, 0, 'H', 30, {0, 0, 0}, 50, 0, Fist, (R+C)/2, 1, 1, "", 0, 0, Mundane, false, 0 };
Player ChanhoPlayer = { R/2, C-1, 'A', 30, {0, 0, 0}, 50, 0, Fist, (R+C)/2, 1, 1, "", 0, 0, Mundane, false, 0 };

// HyunseoPlayer.moves = 3*(R+C);
// ChanhoPlayer.moves = 3*(R+C);

Player players[2][10] = { { HyunseoPlayer }, { ChanhoPlayer } };

Castle wolhwa    = { 0, 0, 'w', "월화", 3, 0, 0 };
Castle hyunseo   = { 0, 0, 'h', "현서", 3, 0, 0 };
Castle chanho    = { 0, 0, 'c', "찬호", 3, 0, 0 };
Castle daewang   = { 0, 0, 'd', "대왕", 3, 0, 0 };
Castle joongdong = { 0, 0, 'j', "중동", 3, 0, 0 };

Castle castles[5] = { wolhwa, hyunseo, chanho, daewang, joongdong };

Tile portals[4] = {{ 0, C/3, 'P' }, { 0, C/3*2, 'P' }, { R-1, C/3, 'P' }, { R-1, C/3*2, 'P' }};
Tile villages[5] = {{ 0, 0, 'V'}, { 0, 0, 'V'}, { 0, 0, 'V'}, { 0, 0, 'V'}, { 0, 0, 'V'}};

Tile enchant = { 0, 0, 'E' };

Safe safes[20] = { };
int safeCount = 0;

int coinCount = (int) sqrt(R*C);

char map[R][C+1];

char input[10];

int timer = 0;

int turn = 0;
int turnTeam = 0;

int teamCount[2] = { 1, 1 };

int px;
int py;
int qx;
int qy;

int totalCastleCount = 5;

int GAME = 1;

void getInput();
void process();

void playerOnVillage () {

	int coin = players[turn][0].coin;
	int pearls = players[turn][0].statPearl;
	int piece = players[turn][0].statPiece;

	printf("Player %c on village!\n", players[turn][0].name );
	printf("현재: %d 금화 %d 스텟구슬 %d 스텟조각입니다.\n", coin , pearls , piece);
	printf("--------------------------------------------PRICE---------------------\n");
	printf("1. 25퍼센트 증가         15 금화   		1 스텟구슬 (현재 수: %2d)\n", players[turn][0].items[0]);
	printf("2. 20퍼센트 증가         10 금화   		1 스텟구슬 (현재 수: %2d)\n", players[turn][0].items[1]);
	printf("3. 10퍼센트 증가         5 금화    		1 스텟구슬 (현재 수: %2d)\n" , players[turn][0].items[2]);
	printf("4. 백성 모집하기         100 금화  		10 스텟구슬\n");
	printf("5. 다이아칼 사기         100 금화  		25 스텟구슬 %c\n", players[turn][turnTeam].sword.type == 4 ? '*' : ' ' );
	printf("6. 철 사기               100 금화  		15 스텟구슬 %c\n", players[turn][turnTeam].sword.type == 3 ? '*' : ' ' );
	printf("7. 돌칼 사기             90 금화   		7 스텟구슬  %c\n", players[turn][turnTeam].sword.type == 2 ? '*' : ' ' );
	printf("8. 나무칼 사기           50 금화   		5 스텟구슬  %c\n", players[turn][turnTeam].sword.type == 1 ? '*' : ' ' );
	printf("9. 턴 사기               4 개당 1 금화		   	   (현재 수:%3d)\n", players[turn][0].moves );
	printf("돈이 없으면 k를 누르세요 ...(돈을 지원해드립니다.)\n");
	printf("----------------------------------------------------------------------\n");
	scanf("%s", input );

	char inputCharacter = input[0];
	int select = inputCharacter - '1';

	int priceCoin[8] = { 15, 10, 5, 100, 100, 100, 90, 50 };
	int pricePearl[8] = { 1, 1, 1, 10, 25, 15, 7, 5 };

	char input2[100];
	char inputCharacter2;

	if ( select < 0 || select > 9 ) {
		return;
	}

	if ( select < 8 && pearls < pricePearl[select] ) {
		printf("당신은 구슬이 없습니다... :(\n");
		playerOnVillage();
		return;
	}
	if ( select < 8 && coin < priceCoin[select] ) {
		printf("당신은 돈이 없습니다... :(\n");
		playerOnVillage();
		return;
	}

	int y;

	switch(inputCharacter) {
		case '1':
		case '2':
		case '3':
			players[turn][0].coin -= priceCoin[select];
			players[turn][0].items[select] += 1;
			players[turn][0].statPearl -= pricePearl[select];
			printf("아이템성사\n");
			break;
		case '4':
			printf("백성의 이름을 정해주세요.\n");
			scanf("%s", input2);
			inputCharacter2 = input2[0];

			y = ( turn == 0 ) ? 0 : C-1;

			players[turn][teamCount[turn]] = (Player) { R/2, y, inputCharacter2, 30, {0, 0, 0}, 50, 0, Fist, (R+C)/2, 1, 1, "", 0, 0, Mundane, false, 0};
			teamCount[turn]++;
			players[turn][0].coin -= priceCoin[select];
			players[turn][0].statPearl -= pricePearl[select];
			printf("백성성사\n");
			break;
		 case '5':
		 case '6':
		 case '7':
		 case '8':
			players[turn][0].coin -= priceCoin[select];
			players[turn][turnTeam].sword = swords[select-4];
			players[turn][0].statPearl -= pricePearl[select];
			printf("칼성사\n");
			break;
		case '9':
			int inpetCharacter;
			printf("server: 턴을 얼만큼 사시겠습니까?\n");
			scanf("%d", &inpetCharacter); 
			if ( inpetCharacter < 0 || inpetCharacter > 4 * players[turn][0].coin)
			{
				printf("server: 돈이 없는 걸로 아는데?\nplayer:네? \nserver: 자네하고 거래 할 생각 없네.\nplayer: 돌아와 서버자식 당장 안돌아와? 안돼~~~~\n");
				playerOnVillage();
			}else {
				inpetCharacter = (inpetCharacter/4) * 4;
				players[turn][0].coin -= inpetCharacter/4;
				players[turn][0].moves += inpetCharacter;
			}
			printf("턴성사\n");
			break;
		default:
			printf("villager:잘가 다음에 또와~~~~~~\n");
			break;
	}

}

void playerOnCastle	( int c ) {
	printf("플레이어%c(이)가 %s성에 입성하였습니다!\n", players[turn][turnTeam].name, castles[c].fullName);
	printf("%s의 목숨: %d\n", castles[c].fullName, castles[c].lives);

	int owner = castles[c].owner;

	if ( owner == 0 ) {
		castles[c].owner = players[turn][0].name;
		players[turn][0].castleCount++;
		printf("%s성의 성주가 되셨습니다.\n", castles[c].fullName);

		int cX = castles[c].x;
		int cY = castles[c].y;

		char up = map[cX-1][cY];
		char down = map[cX-1][cY];
		char left = map[cX-1][cY];
		char right = map[cX-1][cY];

		bool upAvail =  ( up == ' ' ) || ( up == '*' ) || ( up == players[turn][turnTeam].name );
		bool downAvail  = ( down == ' ' ) || ( down == '*' ) || ( down == players[turn][turnTeam].name );
		bool leftAvail  = ( left == ' ' ) || ( left == '*' ) || ( left == players[turn][turnTeam].name );
		bool rightAvail = ( right == ' ' ) || ( right == '*' ) || ( right == players[turn][turnTeam].name );

		bool verticalAvail = upAvail && downAvail;
		bool horizontalAvail = leftAvail && rightAvail;

		bool notAvail = !verticalAvail && !horizontalAvail;

		if ( notAvail ) {
			return;
		}

		printf("성의 방향을 정해주십시오.\n");
		printf("1은 가로 2는 세로\n");
		int inpet;
		scanf("%d",&inpet );
		if (inpet == 1) {
			if (!horizontalAvail) {
				printf("설정이 불가능하여 반대방향으로 했습니다.\n");
				castles[c].rotation = 2;
			} else {
				castles[c].rotation = 1;
			}
		} else if (inpet == 2) {
			if (!verticalAvail) {
				printf("설정이 불가능하여 반대방향으로 했습니다.\n");
				castles[c].rotation = 1;
			} else {
				castles[c].rotation = 2;
			}				
		} else {
			playerOnCastle(c);
		}
	} else if ( owner == players[turn][0].name ) {
		players[turn][turnTeam].x = qx;
		players[turn][turnTeam].y = qy;
		printf("성을 파괴하시겠습니까?\n");		
		printf("1.파괴 2.파괴X\n");

		int inpat;

		scanf("%d",&inpat);
		if (inpat == 1) {
			map[castles[c].x][castles[c].y] = ' ';
			int tmpx, tmpy;

			do {

				tmpx = rand() % (R-2) + 1;
				tmpy = rand() % (C-2) + 1;

			} while ( map[tmpx][tmpy] != ' ' );

			castles[c].x = tmpx;
			castles[c].y = tmpy;
			castles[c].owner = 0;
			castles[c].lives = 3;
			castles[c].rotation = 0;

			players[turn][turnTeam].castleCount--;

		}

		getInput();
	} else {
		if ( players[turn][0].coin < 20 ) {
			printf("server:싸울 돈이 없습니다...\n");
			process();
		}
		if (10-timer > 0)
		{
			printf("지금은 평화시간입니다.\n");
			getInput();
			
		} else {
			players[turn][0].coin -= 20;
			for ( int t = turn, i = 0; i < 2; t = 1 - t, i++ ) {
				printf("%s성 전투가 일어났습니다.\n",castles[c].fullName );
				printf("%c님 아이템을 사용하십시오\n",players[t][0].name );
				
				printf("-----------------------------------\n");
				printf("1.25퍼센트증가 아이템 개수%d\n",players[t][0].items[0]);
				printf("2.20퍼센트증가 아이템 개수%d\n",players[t][0].items[1]);
				printf("3.10퍼센트증가 아이템 개수%d\n",players[t][0].items[2]);
				printf("4.server:아이템을 안 사용하시면 눌러주세요.기호4번  \n");
				printf("-----------------------------------\n");

				scanf("%s", input);
				char inputCharacter = input[0];
				int select = inputCharacter - '1';
				int probs[3] = { 25, 20, 10 };

				switch(inputCharacter) {
					case '1':
					case '2':
					case '3':
						if(players[t][0].items[select] == 0){
							printf("server:아이템이 없습니다.\n");
						} else{
							players[t][0].probability += probs[select];
							printf("완료 되었습니다.\n");
							players[t][0].items[select]--;
				        }
				        break;
				    default:
				    	break;
				}
			}
			
			timer = 0;

			int p0 = players[0][0].probability;
			int p1 = players[1][0].probability;

			int t;

			if ( rand() % (p0 + p1) < p0 ) {
				t = 0;
			} else {
				t = 1;
			}

			printf("%c이 성주가 되었습니다!!!\n", players[t][0].name);
			if ( owner == players[1-t][0].name ) {
				players[1-t][0].castleCount--;
				if ( castles[c].lives > 1 ) {
					players[t][0].castleCount++;
					castles[c].lives--;
				} else {
					map[castles[c].x][castles[c].y] = ' ';
					castles[c].x = -1;
					castles[c].y = -1;
					totalCastleCount--;
				}
			}
			castles[c].owner = players[t][0].name;
		}	
	}

}

void playerOnPlayer ( int i ) {

	int myType = players[turn][turnTeam].sword.type;
	int yourType = players[1-turn][i].sword.type;
	printf("싸움이 일어났습니다.\n");

	int fightStatus;











	if (fightStatus == 0) // Draw
	{
		printf("칼의 레벨이 같아 비겼습니다.\n");
		return;
	} else if (fightStatus == 1) // I Win
	{
		if (players[turn][turnTeam].sword.strength > players[1-turn][0].coin)
		{
		 players[turn][0].coin += (players[turn][0].sword.strength)*2/3;
		 players[1-turn][0].coin = 0;
		} else
		{
			players[turn][0].coin += players[turn][turnTeam].sword.strength;
			players[1-turn][0].coin -= players[turn][turnTeam].sword.strength;
		}
		printf("%c(이)가 %c(을)를 %s칼로 이겼습니다.\n", players[turn][turnTeam].name, players[1-turn][i].name, players[turn][turnTeam].sword.name);
		players[1-turn][i].x = R/2;
		players[1-turn][i].y = ( turn == 1 ) ? 0 : C-1;
	} else { // I Lose
		if (players[1-turn][i].sword.strength > players[turn][0].coin)
		{
		 players[1-turn][0].coin += (players[1-turn][turnTeam].sword.strength)*2/3;
		 players[turn][0].coin = 0;
		} else
		{
			players[1-turn][0].coin += players[1-turn][turnTeam].sword.strength;
			players[turn][0].coin -= players[1-turn][turnTeam].sword.strength;
		}
		printf("%c(이)가 %c(을)를 %s칼로 이겼습니다.\n", players[1-turn][i].name, players[turn][turnTeam].name, players[1-turn][i].sword.name);
		qx = R/2;
		qy = ( turn == 0 ) ? 0 : C-1;
	}

	players[turn][turnTeam].sword.durability--;
	players[1-turn][i].sword.durability--;
	if (players[turn][turnTeam].sword.durability == 0)
	{
		players[turn][turnTeam].sword = Fist;
	}
	if (players[1-turn][i].sword.durability == 0)
	{
		players[1-turn][i].sword = Fist;
	}

}

void playerOnCoin () {
	int value = rand() % 10;
	printf("Player %c의 coin이 %d 만큼 늘었습니다.\n", players[turn][0].name, value);
	players[turn][0].coin += value;
}

void playerOnSafe ( int s ) {

	if (safes[s].owner == players[turn][turnTeam].name)
	{
		players[turn][0].coin += safes[s].coin;
	}else if (safes[s].turn == turn)
	{
		players[turn][turnTeam].coin += safes[s].coin;
	}else{
		players[turn][turnTeam].coin += ( safes[s].coin - 400 );
		printf("상점에서 열쇠를 사 200금화가 빠졌습니다.\n");
		players[1-turn][0].coin += 400;
		printf("%d금화를 약탈했습니다.\n", safes[s].coin);
	}
	safes[s].name = ' ';
}

void playerOnEnchant () {

	int pearls = players[turn][0].statPearl;
	int piece = players[turn][0].statPiece;

	printf("Player %c on Enchant!\n", players[turn][0].name );
	printf("현재: %d 금화 %d 스텟구슬 %d 스텟조각입니다.\n", coin , pearls , piece);
	printf("-----------------------------------\n");
	printf("Item                  				PRICE\n");
	printf("1.Enchant(sword)      50 coins 				20 pearls\n");
	printf("2.Enchant(player)     75 coins 			20 pearls\n");
	printf("3.Safe                50 coins 				5 pearls\n");
	printf("4.Spell               200 coins 			10 pearls\n");
	printf("5.Potion              50 coins             0 pearls\n");
	printf("6.Stat Piece          3 coins / piece 		\n");
	printf("7.Stat Pearl          9 stat pieces / pearl 	\n");	
	printf("돈이 없으면 k를 누르세요 ...(돈을 지원해드립니다.)\n");
	printf("-----------------------------------\n");
	scanf("%s",input );

	char inputCharacter = input[0];
	int select = inputCharacter - '1';	
	int inpetCharacter2;
	int priceCoin[7] = { 50, 75, 50, 200, 50, 0, 0 };
	int pricePearl[7] = { 20, 20, 5, 10, 0, 0, 0};

	if ( select < 0 || select > 6 ) {
		return;
	}

	if ( pearls < pricePearl[select] ) {
		printf("당신은 돈이 없습니다... :(\n");
		playerOnEnchant();
		return;
	}
	if ( coin < priceCoin[select] ) {
		printf("당신은 돈이 없습니다... :(\n");
		playerOnEnchant();
		return;
	}

	players[turn][0].coin -= priceCoin[select];
	players[turn][0].statPearl -= pricePearl[select];

	if ( inputCharacter == '1' ) {
		int enchants = rand() % 9;
		int ef[9][3] = {{1,5},{2,10},{0,20},{1,0},{2,0},{0,0},{0,5},{0,10},{0,20}};
		char names[9][20] = { "날카로움I",
							  "날카로움II",
							  "날카로움III",
							  "내구도I",
							  "내구도II",
							  "내구도III",
							  "약탈I",
							  "약탈II",
							  "약탈III" };

		// players[turn][turnTeam].sword.didEnchant
		if (!players[turn][turnTeam].sword.didEnchant)
		{
			if( enchants == 2 || enchants == 5 ){
				players[turn][turnTeam].sword.durability *= 2;
			}
			players[turn][turnTeam].sword.durability += ef[enchants][0];
			players[turn][turnTeam].sword.strength += ef[enchants][1];
			strncpy(players[turn][turnTeam].sword.enchantName, names[enchants], 20);
			players[turn][turnTeam].sword.didEnchant = true;

			printf("인챈트이름:%s\n",names[enchants]);
		}else{
			printf("이 칼은 이미 인첸트가 되어있습니다.\n");
		}
	
	} else if ( inputCharacter == '2' ) {

		int p = rand() % 100;
		if (p >= 0 && p < 5)
		{
			strncpy(players[turn][turnTeam].enchantName, "신속", 20);
			players[turn][turnTeam].maxTurnCount = 2;
		}else if (p >= 5 && p < 6)
		{
			strncpy(players[turn][turnTeam].enchantName, "신속+강타II", 20);
			players[turn][turnTeam].maxTurnCount = 2;
			players[turn][turnTeam].sword.strength += 10;
		}else if (p >= 6 && p < 41)
		{	
			strncpy(players[turn][turnTeam].enchantName, "강타I", 20);
			players[turn][turnTeam].sword.strength += 5;
		}else if (p >= 41 && p < 61)
		{
			strncpy(players[turn][turnTeam].enchantName, "강타II", 20);
			players[turn][turnTeam].sword.strength += 10;
		}else if (p >= 61 && p < 71)
		{
			strncpy(players[turn][turnTeam].enchantName, "강타III", 20);
			players[turn][turnTeam].sword.strength += 20;
		}else if (p >= 71 && p < 100)
		{
			printf("인첸트가 실패 했습니다.\n");
		}
		printf("인첸트:%s\n", players[turn][turnTeam].enchantName );

	} else if ( inputCharacter == '3' ) {
		
		do{
			printf("얼마를 저장하시겠습니까?\n");
			scanf("%d", &inpetCharacter2 );
		}while(inpetCharacter2 < 0 && inpetCharacter2 > players[turn][turnTeam].coin);

		players[turn][turnTeam].coin -= inpetCharacter2;

		int safesx;
		int safesy;
		do{
			safesx = rand() % R;
			safesy = rand() % C;
		}while( map[safesx][safesy] != ' ' );

		safes[safeCount] = (Safe) {safesx, safesy, 'S', players[turn][turnTeam].name, inpetCharacter2, turn};
		safeCount++;
	
	} else if ( inputCharacter == '4' ) {

	} else if ( inputCharacter == '5') {
		int w = rand() % 6;

		players[turn][turnTeam].potion = potions[w];

		printf("%s의 포션을 얻었습니다.\n", potions[w].name);

	} else if ( inputCharacter == '6' ) {
		int inpetCharacter3;
		printf("살 양을 정해주세요. 개당 3원: ");
		scanf("%d", &inpetCharacter3 );
		if (3 * inpetCharacter3 > players[turn][0].coin)
		{
			printf("잔액이 부족합니다.\n");
			playerOnEnchant();
		}
		players[turn][0].coin -= 3 * inpetCharacter3;
		players[turn][0].statPiece += inpetCharacter3;

	} else if ( inputCharacter == '7' ) {

		printf("스탯 구슬 %d개 구매하셨습니다.\n", players[turn][0].statPiece / 9 );
		players[turn][0].statPearl += players[turn][0].statPiece / 9;
		players[turn][0].statPiece = players[turn][0].statPiece % 9;

		printf("현재: 스탯 구슬 %d개\n", players[turn][0].statPearl );
		printf("현재: 스탯 조각 %d개\n", players[turn][0].statPiece );
	}

}

void setup () {

	srand(time(NULL));

	for ( int i = 0; i < R; ++i ) {
		for ( int j = 0; j < C; ++j ) {
			map[i][j] = ' ';
		}
	}

			
	castles[0].x = rand() % R;
	castles[0].y = C / 2;

	castles[1].x = rand() % (R-2) + 1;
	castles[1].y = rand() % (C/2 - 1) + 1;

	castles[2].x = rand() % (R-2) + 1;
	castles[2].y = rand() % (C/2 - 1) + 1 + C / 2;

	for ( int i = 3; i < 5; ++i ) {
		int tmpx, tmpy;

		do {

			tmpx = rand() % (R-2) + 1;
			tmpy = rand() % (C-2) + 1;

		} while ( map[tmpx][tmpy] != ' ' ||
				  map[tmpx][tmpy-1] != ' ' ||
				  map[tmpx][tmpy+1] != ' ' ||
				  map[tmpx-1][tmpy] != ' ' ||
				  map[tmpx-1][tmpy-1] != ' ' ||
				  map[tmpx-1][tmpy+1] != ' ' ||
				  map[tmpx+1][tmpy] != ' ' ||
				  map[tmpx+1][tmpy-1] != ' ' ||
				  map[tmpx+1][tmpy+1] != ' ' );

		castles[i].x = tmpx;
		castles[i].y = tmpy;

	}

	for ( int i = 0; i < 5; ++i ) {
		int tmpx, tmpy;

		do {

			tmpx = rand() % (R-2) + 1;
			tmpy = rand() % (C-2) + 1;

		} while ( map[tmpx][tmpy] != ' ' );

		villages[i].x = tmpx;
		villages[i].y = tmpy;

	}

	int tmpx, tmpy;

	do {	
		tmpx = rand() % (R-2) + 1;
		tmpy = rand() % (C-2) + 1;	
	} while ( map[tmpx][tmpy] != ' ' );	

	enchant.x = tmpx;
	enchant.y = tmpy;

	timer = 0;
	turn = 0;
	turnTeam = 0;

	players[0][0] = HyunseoPlayer;
	players[1][0] = ChanhoPlayer;

}

void draw () {

	for ( int i = 0; i < R; ++i ) {
		for ( int j = 0; j < C; ++j ) {
			map[i][j] = ' ';
		}
	}

	for ( int i = 0; i < 5; ++i ) {
		map[castles[i].x][castles[i].y] = castles[i].name;

		if (castles[i].rotation == 2) {
			map[castles[i].x-1][castles[i].y] = castles[i].name;
			map[castles[i].x+1][castles[i].y] = castles[i].name;
		} else if ( castles[i].rotation == 1 ) {
			map[castles[i].x][castles[i].y-1] = castles[i].name;
			map[castles[i].x][castles[i].y+1] = castles[i].name;
		}

	}

 	map[enchant.x][enchant.y] = enchant.name;

	for ( int i = 0; i < 4; ++i ) {
		map[portals[i].x][portals[i].y] = portals[i].name;
	}

	for ( int i = 0; i < safeCount; ++i ) {
		map[safes[i].x][safes[i].y] = safes[i].name;
	}

	for ( int i = 0; i < 5; ++i ) {
		map[villages[i].x][villages[i].y] = villages[i].name;
	}

	for ( int i = 0; i < 2; ++i ) {
		for ( int j = 0; j < teamCount[i]; ++j ) {
			map[players[i][j].x][players[i][j].y] = players[i][j].name;
		}
	}

	for ( int i = 0; i < coinCount; ++i ) {
		int tmpx, tmpy;

		do {
			tmpx = rand() % (R-2) + 1;
			tmpy = rand() % (C-2) + 1;
		} while ( map[tmpx][tmpy] != ' ' );

		map[tmpx][tmpy] = '*';

	}

	char blockHorizontal = '-';
	char blockVertical = '|';

	if (timer < 10)
	{
		printf("공격까지 남은시간: %d\n", 10 - timer);
	} else
	{
		printf("현재 공격 가능\n");
		blockHorizontal = '*';
		blockVertical = '*';
	}

	for ( int i = 0; i < C+2; ++i ) {
		printf("%c", blockHorizontal);
	}
	printf("\n");
	for ( int i = 0; i < R; ++i ) {
		printf("%c%s%c\n", blockVertical, map[i], blockVertical);
	}
	for ( int i = 0; i < C+2; ++i ) {
		printf("%c", blockHorizontal);
	}
	printf("\n");

}

void getInfo () {
	printf("정보-----------\n");
	printf("          돈: %d금화\n", players[turn][0].coin );
	printf("          턴: %d\n", players[turn][0].moves);
	printf("    스텟조각: %d개\n",players[turn][0].statPiece );
	printf("    스텟구슬: %d개\n",players[turn][0].statPearl );
	printf("  인챈트이름: %s\n", players[turn][turnTeam].enchantName );
	printf("    포션이름:  %s\n", players[turn][turnTeam].potion.name);
	printf("포션지속시간: %d\n", players[turn][turnTeam].potion.duration );
	printf(" 포션사용중?:  %s\n", players[turn][turnTeam].isUsingPotion ? "참" : "거짓");

	printf("무기정보---------\n");
	printf("          칼: %s칼\n", players[turn][turnTeam].sword.name );
	printf("      내구도: %d\n", players[turn][turnTeam].sword.durability );
	printf("    약탈가격: %d금화\n", players[turn][turnTeam].sword.strength );
	printf("  인챈트이름: %s\n", players[turn][turnTeam].sword.enchantName );
	printf("--------------\n");

}  

void noMoves () {
	players[turn][0].coin = 0; 
	players[turn][0].moves = (R+C)/2;
	printf("턴이 없어 돈이 0금화가 되었습니다.\n");
	process();
}

void getInput () {

	if ( turnTeam == 0 ) {
		printf("Player %c: ", players[turn][0].name);
	} else {
		printf("Player %c의 백성 %c: ", players[turn][0].name, players[turn][turnTeam].name);
	}

	if ( players[turn][0].moves <= 0 ) {
		noMoves();
	}

	if (players[turn][turnTeam].isUsingPotion)
	{
		if (players[turn][turnTeam].potion.duration == 0) {
			players[turn][turnTeam].potion = Mundane;
			players[turn][turnTeam].isUsingPotion = false;
			int type = players[turn][turnTeam].potion.type;
			if (type == 3) {
				players[turn][turnTeam].sword.strength -= 40;
			} else if (type == 5) {
				players[turn][turnTeam].maxTurnCount = 1;
			}
		} else {
			int type = players[turn][turnTeam].potion.type;
			if (type == 1) {
				players[turn][turnTeam].coin += 100;
			} else if (type == 2) {
				players[turn][turnTeam].coin += 10;
			}
		}
	}

	scanf("%s", input);

	if ( strcmp(input, "reset") == 0 ) {
		setup();
		timer--;
		turn = 1;
		turnTeam = 0;
		return;
	}

	char inputCharacter = input[0];

	px = players[turn][turnTeam].x;
	py = players[turn][turnTeam].y;
	qx = px;
	qy = py;

	switch (inputCharacter){
		case 'w': case 'i':
			qx -= 1;
			break;
		case 'a': case 'j':
			qy -= 1;
			break;
		case 's': case 'k':
			qx += 1;
			break;
		case 'd': case 'l':
			qy += 1;	
			break;
		case 'e': case 'o':
			getInfo();
			getInput();
			break;
		case 'z': case 'm':
			if (players[turn][turnTeam].isUsingPotion)
			{
				printf("포션사용중\n");
			} else {
				players[turn][turnTeam].isUsingPotion = true;
				if (players[turn][turnTeam].potion.type == 3) {
					players[turn][turnTeam].sword.strength += 40;
				}
				if (players[turn][turnTeam].potion.type == 5) {
					players[turn][turnTeam].maxTurnCount = 3;
				}
			}
			break;
		case 'b':
			printf("server:항복으로 인해 게임이 끝났습니다.\n");
			GAME = 0;
			break;
		default:
			break;

	}

	for ( int i = 0; i < 4; ++i ) {
		if ( map[qx][qy] == portals[i].name ) {
			int portalIndex;
			do{
				portalIndex = rand() % 4;
			}while(i == portalIndex);
				qx = portals[portalIndex].x;
				qy = portals[portalIndex].y;
		}
	}

	if ( map[qx][qy] == '|' || map[qx][qy] == '-' ||
		 qx < 0 || qy < 0 || qx >= R || qy >= C ) {
		qx = px;
		qy = py;
		getInput();
	}
	for ( int i = 0; i < 5; ++i ) {
		if ( map[qx][qy] == castles[i].name ) {
			playerOnCastle( i );
		}
	}
	if ( map[qx][qy] == '*' ) {
		playerOnCoin();
	}
	for ( int i = 0; i < safeCount; ++i ) {
		if ( map[qx][qy] == safes[i].name && safes[i].name == 'S' ) {
			playerOnSafe( i );
			break;
		}
	}
	if ( map[qx][qy] == 'V' ) {
		playerOnVillage();
	}
	if ( map[qx][qy] == 'E') {
		playerOnEnchant();
	}

	for ( int i = 0; i < teamCount[1-turn]; ++i ) {
		if (map[qx][qy] == players[1-turn][i].name ) {
			playerOnPlayer( i );
			break;
		}
	}

	players[turn][turnTeam].x = qx;
	players[turn][turnTeam].y = qy;

}

void process () {
	
	players[turn][0].coin += players[turn][0].castleCount;
	players[turn][0].statPiece += 3 * players[turn][0].castleCount;
	players[turn][0].moves--;
	players[0][0].probability = 50;
	players[1][0].probability = 50;
	if (players[turn][turnTeam].isUsingPotion)
	{
		players[turn][turnTeam].potion.duration--;
	}
	
	if ( totalCastleCount == 0 ) {
		if ( players[turn][0].coin > players[1-turn][0].coin ) {
			printf("%c가 승리했습니다.", players[turn][0].name );
		} else {
			printf("%c가 승리했습니다.", players[1-turn][0].name );
		}
		GAME = 0;
	}

	if ( players[turn][turnTeam].turnCount > 1 ) {
		players[turn][turnTeam].turnCount--;
	} else {

		players[turn][turnTeam].turnCount = players[turn][turnTeam].maxTurnCount;

		if ( turnTeam < teamCount[turn] - 1 ) {
			turnTeam++;
		} else {
			timer++;
			turnTeam = 0;	
			turn = 1 - turn;
		}

	}


}

int main () {

	printf("welcome to 공성전\n");
    printf("선공 순서를 결정해주세요...\n");

    setup();

	while (GAME) {

		draw();
		getInput();
		process();

	}

	printf("server: 게임이 종료되었습니다.\n");	

	return 0;
}	
