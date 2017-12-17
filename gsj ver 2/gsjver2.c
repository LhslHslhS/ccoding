#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define C 43
#define R 15
 
typedef struct{	
	char name[100];
	int type;
	int durability;
	int strengh;
	char enchantName[20];
} Sword;

typedef struct {
	int x;
	int y;
	char name;
	int coin;
	int probability;
	int castleCount;
	Sword sword;
	int moves;
	int shield;
	int portalX;
	int portalY;
	int portalBuy;
} Player;

typedef struct {
	int x;
	int y;
	char name;
	char Fullname[10];
	int lives;
	int rotation;
	char owner;
	int show;
} Castle;

typedef struct{
	int x;
	int y;
	char name;
} Tile;

Sword Diamond = {"다이아", 4, 2, 60};
Sword Iron = {"철", 3, 3, 45};
Sword Stone = {"돌", 2, 4, 30};
Sword Wood = {"나무", 1, 5, 15};
Sword Fist = {"주먹", 0, -1, 10};

Sword sword[4] = { Diamond, Iron, Stone, Wood};

Player HyunseoPlayer = {R/2, 0, 'H', 50, 50, 0, Fist, (R+C)/2, 0, -1, -1, 0 };
Player ChanhoPlayer = {R/2, C-1, 'C', 50, 50, 0, Fist, (R+C)/2, 0, -1, -1, 0 };

Player players[2][10] = { {HyunseoPlayer }, { ChanhoPlayer }};
 
Castle wolhwa = { 0, 0, 'w', "월화", 3, 0, 0, 0};
Castle hyunseo = { 0, 0, 'h', "현서", 3, 0, 0, 0};
Castle chanho = { 0, 0, 'c', "찬호", 3, 0, 0, 0};
Castle daewang = { 0, 0, 'd', "대왕", 3, 0, 0, 0};
Castle joongdong = { 0, 0, 'j', "중동", 3, 0, 0, 0};
Castle samtuh = { 0, 0, 'c', "샘터", 3, 0, 0, 0};
Castle peureun = { 0, 0, 'c', "푸른", 3, 0, 0, 0};
Castle beahm = { 0, 0, 'c', "비암", 3, 0, 0, 0};
Castle apple = { 0, 0, 'c', "애플", 3, 0, 0, 0};
Castle samsung = { 0, 0, 'c', "삼성", 3, 0, 0, 0};


Castle castles[10] = {wolhwa, hyunseo, chanho, daewang, joongdong, samtuh, peureun, beahm, apple, samsung};

Tile portals[4] = { {0, C/3, 'P'}, {0, C/3*2, 'P'}, {R-1, C/3, 'P'}, {R-1, C/3*2, 'P'}};
Tile village[5] = {{ 0, 0, 'v'}, { 0, 0, 'v'}, { 0, 0, 'v'}, { 0, 0, 'v'}, { 0, 0, 'v'}};

int timestart = 180;

int coinCount = (int) sqrt(R+C); 

char map[R][C+1];

char input[10];
 
int timer = timestart * 5 / 6;
int castleShowTime;

int turn = 0;
int turnTeam = 0;

int teamCount[2] = { 1, 1 };

int px;
int py;
int qx;
int qy;

int totalCastleCount = 10;

int GAME = 1;


void getInput();
void process();

void playerPushPortal() {
	
	if (players[turn][turnTeam].portalBuy == 0)
	{
		printf("이동할 포탈이 없습니다.\n");
		return;
	}else{
		qx = players[turn][turnTeam].portalX;
		qy = players[turn][turnTeam].portalY;
		printf("성공적으로 이동했습니다.\n");
		players[turn][turnTeam].portalBuy = 0;
	}

}
void playersOnCasino () {
	int casinoing;
	int price;
	printf("도박하시겠습니까?\n1: 네 \n2: 아니요\n");
	scanf("%d",&casinoing );
	if (casinoing == 2)
	{
		printf("안녕히 가십시오\n");
		return;
	}else if (casinoing == 1)
	{
		printf("베팅금을 정해주십시오\n");
		printf("현재 재산: %d\n",players[turn][turnTeam].coin );
		scanf("%d",&price );
		if (players[turn][turnTeam].coin < price)
		{
			printf("돈이 부족합니다.\n");
			return;
		}else{
			int sign = 2 * (rand() % 2) - 1;
			int percents = rand() % 100;
			printf("결과: %+d\n", price * percents / 100 * sign);
			players[turn][turnTeam].coin += price * percents / 100 * sign;
			printf("도박 후 재산: %d\n", players[turn][turnTeam].coin);
		}
	}
}

void playerOnVillage () {

	int coin = players[turn][turnTeam].coin;
	char input;

	printf("재산: %d금화 \n",coin );
	printf("---------------------------------------------------------\n" );
	printf("1. 다이아칼 사기         100 금화 \n" );
	printf("2. 철칼 사기              90 금화 \n" );
	printf("3. 돌칼 사기             70 금화 \n" );
	printf("4. 나무칼 사기           50 금화 \n" );
	printf("5. 백성 모집하기         100 금화 \n" );  
	printf("6. 방패 사기             60금화 \n" );
	printf("7. 텔레포트             30금화\n" );
	printf("8. 포탈 사기             100금화\n" );
	printf("9. 턴 사기               4 개당 1금화 \n" );
	printf("---------------------------------------------------------\n" );
	
	scanf("%c", &input );
	scanf("%c", &input );

	int priceCoin[8] = { 100, 90, 70, 50, 100, 60, 30, 100 };

	int select = input - '0';
	int x, y;

	if ( select < 1 || select > 9 ) {
		printf("다시 입력\n");
		return;
	}

	if ( coin < priceCoin[select - 1] ) {
		printf("당신은 돈이 없습니다...\n");
		playerOnVillage();
		return;
	}

	switch(input) {
		case '1':
		case '2':
		case '3':
		case '4':
			players[turn][turnTeam].sword = sword[select-1];
			players[turn][turnTeam].coin -= priceCoin[select-1];
			break;
		case '5':
			{
				char nameString[10];
				char name;
				printf("백성의 이름?\n");
				scanf("%s", nameString );
				name = nameString[0];

				y = ( turn == 0 ) ? 0 : C-1;

				players[turn][teamCount[turn]] = (Player) {R/2, 0, name, 30, 50, 0, Fist, (R+C)/2, 0, 0, 0, 0 };
				teamCount[turn]++;
				players[turn][0].coin -= priceCoin[select];
				printf("끝!!!!!\n");
				break;
			}
		case '6':
			players[turn][0].coin -= priceCoin[select];
			players[turn][turnTeam].shield += 3;
			break;
		case '7':
			printf("텔레포트할 좌표를 적어주십시오. x는 %d y는 %d 까지입니다.\n", R, C);
			scanf("%d", &x );
			scanf("%d", &y );
			if (x < 0|| x > R) {
				printf("안녕히 가세요 돈은 감사히 받겠습니다.\n");
				return;
			} else if (y < 0|| y > C) {
				printf("안녕히 가세요 돈은 감사히 받겠습니다.\n");
				return;
			}
			players[turn][0].coin -= priceCoin[select-1];
			qx = x;
			qy = y;
			break;
		case '8':
			//players[turn].x = players[turn].portalX;
		    if (players[turn][turnTeam].portalBuy == 1)
		    {
		    	printf(" 이미 포탈을 구매했습니다.\n");
		    	return;
		    }
			printf("포탈을 설치할 좌표를 적어주십시오. x는 %d y는 %d\n" ,R, C);
			scanf("%d",&x );
			scanf("%d",&y );
			if (x < 0|| x > R) {
				printf("안녕히 가세요 돈은 감사히 받겠습니다.\n");
				return;
			} else if (y < 0|| y > C) {
				printf("안녕히 가세요 돈은 감사히 받겠습니다.\n");
				return;
			}
			players[turn][turnTeam].portalX = x;
			players[turn][turnTeam].portalY = y;
			players[turn][0].coin -= priceCoin[select];
			players[turn][turnTeam].portalBuy = 1;
			break;
		case '9':
			{
				int inpetCharacter;
				printf("server: 턴을 얼만큼 사시겠습니까?\n");
				scanf("%d", &inpetCharacter); 
				if ( inpetCharacter < 0 || inpetCharacter > 4 * players[turn][0].coin) {
					printf("server: 너 돈 없지?\nplayer:네! \nserver: 잘가 \nplayer: 안녕히 계세요 \n");
					playerOnVillage();
				} else {
					inpetCharacter = (inpetCharacter/4) * 4;
					players[turn][0].coin -= inpetCharacter/4;
					players[turn][0].moves += inpetCharacter;
				}
				printf("턴 거래 완료\n");
				break;
			}
		default:
			break;
		}
}

void playerOnCastle	( int c ) {

	printf("플레이어%c(이)가 %s성에 입성하였습니다. \n",players[turn][turnTeam].name , castles[c].Fullname );
	printf("%s의 목숨: %d\n",castles[c].Fullname, castles[c].lives );

	int owner = castles[c].owner;
	int t = turn;
	int i;

	if (owner == 0) {
		castles[c].owner = players[turn][0].name;
		players[turn][0].castleCount++;
		printf("%s성의 성주가 되셨습니다.\n", castles[c].Fullname);
	} else if ( owner == players[turn][0].name) {
		players[turn][turnTeam].x = qx;
		players[turn][turnTeam].y = qy;	
	} else {
		if (timer >= 0) {
			printf("지금은 평화시간입니다.\n" );
			getInput();
		} else {
			for (t = turn, i = 0;  i < 2; t = 1 - t, ++i ) {
				printf("%s성 전투가 일어났습니다. \n", castles[c].Fullname );
			}
			int winer = rand() % 2;
			if (winer == 0) {
				t = 0;
			} else {
				t = 1;
			}
			printf("%c이 성주가 되었습니다!!!\n",players[t][0].name );
			if (owner == players[1-t][0].name) {
				players[1-t][0].castleCount--;
				if ( castles[c].lives > 1){
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

	int mytype = players[turn][turnTeam].sword.type;
	int yourtype = players[1-turn][turnTeam].sword.type;

	if (mytype > yourtype){

		if (players[turn][turnTeam].sword.strengh > players[1-turn][0].coin)
		{
			players[turn][0].coin += (players[turn][0].sword.strengh) * 2 / 3;
			players[1-turn][0].coin = 0;		
		}else{
			players[turn][0].coin += players[1-turn][turnTeam].sword.strengh;
			players[1-turn][0].coin -= players[1-turn][turnTeam].sword.strengh;		
		}
		printf("-----------\n");
		printf("승리자: %c\n패배자: %c\n", players[turn][turnTeam].name , players[1-turn][i].name);
		printf("-----------\n");
		players[1-turn][i].x = R/2;
		players[1-turn][i].y = ( turn == 0 ) ? 0 : C-1;
	}else if (mytype < yourtype)
	{
		if (players[1-turn][i].sword.strengh > players[turn][0].coin) {
			players[1-turn][0].coin += (players[1-turn][turnTeam].sword.strengh) * 2 / 3;
			players[turn][0].coin = 0;		
		} else {
			players[1-turn][0].coin += players[1-turn][turnTeam].sword.strengh;
			players[turn][0].coin -= players[1-turn][turnTeam].sword.strengh;		
		}
		printf("-----------\n");
		printf("승리자: %c\n패배자: %c\n", players[1-turn][i].name , players[turn][turnTeam].name);
		printf("-----------\n");
		qx = R/2;
		qy = ( turn == 0 ) ? 0 : C-1;
	} else {
		printf("비겼습니다.\n");
		return;
	}
	players[turn][turnTeam].sword.durability--;
	players[1-turn][i].sword.durability--;
	
	if (players[turn][turnTeam].sword.durability == 0)
	{
		players[turn][turnTeam].sword = Fist;
	}
	if (players[1-turn][i].sword.durability == 0) {
		players[1-turn][i].sword = Fist;
	}
}

void playerOnCoin () {
	int value = rand() % 10;
	printf("Player %c의 금화가 %d만큼 늘었습니다.\n",players[turn][0].name, value );
	players[turn][0].coin += value;
}

void setup () {

	srand(time(NULL));

	for ( int i = 0; i < R; ++i ) {
		for ( int j = 0; j < C; ++j ) {
			map[i][j] = ' ';
		}
	}
	
	for ( int i = 0; i < 5; ++i ) {
		int tmpx, tmpy;
	
		do {
	
			tmpx = rand() % (R-2) + 1;
			tmpy = rand() % (C-2) + 1;
	
		} while ( map[tmpx][tmpy] != ' ' && map[tmpx][tmpy] != '$' );

		village[i].x = tmpx;
		village[i].y = tmpy;

	}
}
void draw () {

	for ( int i = 0; i < R; ++i ) {
		for ( int j = 0; j < C; ++j ) {
			map[i][j] = ' ';
		}
	}

	map[ (R-1)/2 ][ (C-1)/2 ] = '$';

	for ( int i = 0; i < 4; ++i ) {
		map[portals[i].x][portals[i].y] = portals[i].name;
	}


	for ( int i = 0; i < 5; ++i ) {
		map[village[i].x][village[i].y] = village[i].name;
	}

	for ( int i = 0; i < 8; ++i ) {
		if (castles[i].show)
			map[castles[i].x][castles[i].y] = castles[i].name;
	}

	for ( int i = 0; i < 2; ++i ) {
		for ( int j = 0; j < teamCount[i]; ++j ) {
			map[players[i][j].x][players[i][j].y] = players[i][j].name;
		}
	}
	
	for ( int i = 0; i < coinCount; ++i ) {
		int tmpx, tmpy;

		do{
			tmpx = rand() % (R-2) + 1;
			tmpy = rand() % (C-2) + 1;		
		}while ( map[tmpx][tmpy] != ' ' );

		map[tmpx][tmpy] = '*';
	}

	char blockHorizontal = '-';
	char blockVertical = '|';

	if (timer <= 0)
	{
		printf("현재 공격가능 \n");
		printf("공격 불가능까지: %d\n", abs(timer) );
		blockHorizontal = '*';
		blockVertical = '*';
	}else if (timer <= timestart)
	{
		printf("공격까지 남은 시간: %d\n", timer );
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
	printf("          칼: %s칼\n", players[turn][turnTeam].sword.name );
	printf("      내구도: %d\n", players[turn][turnTeam].sword.durability );
	printf("    약탈가격: %d금화\n", players[turn][turnTeam].sword.strengh );
	printf("    포탈위치: x = %d y = %d\n", players[turn][turnTeam].portalX , players[turn][turnTeam].portalY );
	printf("--------------\n");
}  

void noMoves () {
	players[turn][0].coin = 0; 
	players[turn][0].moves = (R+C)/2;
	printf("턴이 없어 돈이 0금화가 되었습니다.\n");
	process();
}

void getInput () {

	if (turnTeam == 0) {
		printf("Player %c:\n",players[turn][0].name );
	} else {
		printf("Player %c의 백성 %c:\n",players[turn][0].name, players[turn][turnTeam].name );
	}

	if (players[turn][0].moves <= 0) {
		noMoves();
	}

	scanf("%s", input );

	if ( strcmp(input, "reset") == 0) {
		setup();
		timer = timestart * 5 / 6;
		castleShowTime = 0;
		turn = 1;
		turnTeam = 0;

		players[0][0] = HyunseoPlayer;
		players[1][0] = ChanhoPlayer;
		castles[0] = wolhwa;
		castles[1] = hyunseo;
		castles[2] = chanho;
		castles[3] = daewang;
		castles[4] = joongdong,
		castles[5] = samtuh;
		castles[6] = peureun;
		castles[7] = beahm;
		castles[8] = apple;
		castles[9] = samsung;



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
		case 'q': case 'u':
			playerPushPortal();
			break;
		case 'b':
			printf("GAME OVER\n");
			GAME = 0;
			break;
		default:
			break;
	}

	for ( int i = 0; i < 4; ++i ) {
		if ( map[qx][qy] == portals[i].name) {
			int portalIndex;
			do{
				portalIndex = rand() % 4;
			}while(i == portalIndex);
				qx = portals[portalIndex].x;
				qy = portals[portalIndex].y;
		}
	}

	if ( map[qx][qy] == '|' || map[qx][qy] == '-' ||
		qx < 0 || qy < 0 || qx >= R || qy >= C) {
		qx = px;
		qy = py;
		getInput();
		return;
	}
	if ( map[qx][qy] == '$' )
	{
		playersOnCasino();
	}

	if ( map[qx][qy] == castles[0].name ) {
		printf("%s성이 공개되었습니다.\n",castles[0].Fullname);
		castles[0].show = 1;
		playerOnCastle( 0 );
	}

	castleShowTime++;

	for ( int i = 0; i < 10; ++i ) {
		if ( map[qx][qy] == castles[i].name && castles[i].show ) {
			playerOnCastle( i );
		}
	}

	for ( int i = 0; i < 10; ++i ) {
		if (castleShowTime == i * timestart) {
		printf("%s성이 공개되었습니다.\n",castles[i].Fullname);

		int tmpx, tmpy;
		do{
	
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
		castles[i].show = 1;
		}
	}

	if ( map[qx][qy] == '*' ) {
		playerOnCoin();
	}

	if (map[qx][qy] == 'v'){
		playerOnVillage();
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

	players[turn][0].moves--;

	if ( totalCastleCount == 0 ) {
		if ( players[turn][0].coin > players[1-turn][0].coin ) {
			printf("%c가 승리했습니다.", players[turn][0].name );
		} else {
			printf("%c가 승리했습니다.", players[1-turn][0].name );
		}
		GAME = 0;
	}

	if ( turnTeam < teamCount[turn] - 1) {
		turnTeam++;
	} else {
		turnTeam = 0;
		turn = 1 - turn;
	}

	if (timer < -1 * timestart / 6) {
		timer = timestart;
	}
	timer--;

}

int main () {


	printf("welcome to 공성전\n");
 	printf("게임을 시작합니다.\n");

 	setup();

	while(GAME){
		draw();
		getInput();
		process();
	}
	printf("게임이 종료되었습니다\n");

	return 0;
}
