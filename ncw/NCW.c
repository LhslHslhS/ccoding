#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define R 57
#define C 118

typedef struct {
	char name[10];
	int type;
	int durability;
	int strength;   
	int enchantSharpness;
	int enchantDurability;
	int reinForce;
} Sword;

typedef struct {
	int material;
	int durability;
	int enchantProtection;
	int enchantDurability;
	int reinforce;
} Armor;
 
typedef struct {
 	int name;
 	int owner;
 	int chestMineral[8];
 	int chestMissile[5];
	int chestRocket[4];
	int chestGoldenApple;
} Chest;

typedef struct {
	int x;
	int y;
	int name;
	int healthpoint;
	int strikingPower;
	int defensivePower;
	int mineral[8];
	Armor armors[4];
	Sword sword;
	int missile[5];
	int rocket[4];
	int reinforce[3];
	int goldenApple;
	int land;
} Player;

typedef struct {
	int x;
	int y;
	char name;
} Tile;

typedef struct {
	int landNumber;
	int owner;
	char landXY[10][10];
	int groundBlock;
} Land;

Sword swordDiamond = { "다이아", 4, 4, 8, 0, 0};
Sword swordIron = { "철", 3, 6, 7, 0, 0};
Sword swordStone = { "돌", 2, 8, 6, 0, 0};
Sword swordWood = { "나무",1, 10, 5, 0, 0 };
Sword swordFist = { "주먹", -1, 1, 1, 0, 0};

Sword swords[4] = { swordDiamond, swordIron, swordStone, swordWood };

Armor helmetDiamond = {2, 10, 0, 0, 0};
Armor chestplateDiamond = {2, 10, 0, 0, 0};
Armor leggingsDiamond = {2, 10, 0, 0, 0};
Armor bootsDiamond = {2, 10, 0, 0, 0};
Armor helmetIron = {1, 8, 0, 0, 0};
Armor chestplateIron = {1, 8, 0, 0, 0};
Armor leggingsIron = {1, 8, 0, 0, 0};
Armor bootsIron = {1, 8, 0, 0, 0};
Armor helmetBase = {0, 0, 0, 0, 0};
Armor chestplateBase = {0, 0, 0, 0, 0};
Armor leggingsBase = {0, 0, 0, 0, 0};
Armor bootsBase = {0, 0, 0, 0, 0};

Armor armors[8] = {helmetIron, chestplateIron, leggingsIron, bootsIron, helmetDiamond, chestplateDiamond, leggingsDiamond, bootsDiamond};
Armor armorsBase[4] = {helmetBase, chestplateBase, leggingsBase, bootsBase};

Land land1 = {1, 3, {4, 4}, 100};
Land land2 = {2, 3, {20, 4}, 100};
Land land3 = {3, 3, {36, 4}, 100};
Land land4 = {4, 3, {52, 4}, 100};
Land land5 = {5, 1, {4, 20}, 100};
Land land6 = {6, 3, {52, 20}, 100};
Land land7 = {7, 3, {4, 36}, 100};
Land land8 = {8, 2, {52, 36}, 100};
Land land9 = {9, 3, {4, 52}, 100};
Land land10 = {10, 3, {20, 52}, 100};
Land land11 = {11, 3, {36, 52}, 100};
Land land12 = {12, 3, {52, 52}, 100};

Land lands[12] = {land1, land2, land3, land4, land5, land6, land7, land8, land9, land10, land11, land12};


Player HyunseoPlayer = { R/2, 0, 'H', 20, 0, 0, {1000, 0, 0, 0, 0, 0, 0, 0}, {helmetBase, chestplateBase, leggingsBase, bootsBase}, swordFist, {0, 0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0}, 0};
Player ChanhoPlayer = { R/2, C-2, 'A', 20, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0}, {helmetBase, chestplateBase, leggingsBase, bootsBase}, swordFist, {0, 0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0}, 0};

Player players[2][16] = { { HyunseoPlayer }, { ChanhoPlayer } };

Chest chest1 = {1, 2, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0}, 0};
Chest chest2 = {2, 2, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0}, 0};



Chest chest[2] = {chest1, chest2};

int teamCount[2] = {1, 1};

char sucessPercent[10] = {80, 60, 40, 30, 20, 15, 13, 10, 8, 5};
int sucess;
int sucessPer;
char BoomPercent[10] ={ 0, 0, 5, 7, 10, 15, 20, 30, 50, 70};
int Boom;
int BoomPer;

char map[R][C+1];

char input[10];

int timer = 0;


int turn = 0;
int turnTeam = 0;

int px;
int py;
int qx;
int qy ;

int GAME = 1;

void getInput();
void process();

void playerOnLotto() {};
void playerOnLandTeleport() {};
void playerOnConferenceRoom() {};
void playerOnJackPot() {};
void playerOnChestOne() {};
void playerOnChestTwo() {};


void playerOnVillage () {

	int mainMarket;
	int swordMarket;
	int armorMarket;
	int rocketMarket;
	int missileMarket;
	int landMarket;
	int landUpgradeMarket;
	int chestMarket;
	int reinforceMarket;
	int reinStoneCount;
	int reinForceUpGradeStone;
	int reinForceBoomLowerStone;
	int reinForceItem;
	int firstStoneCount;
	int secondStoneCount;
	int workerMarket;
	int exchangeHouse;


	printf("에메랄드 개수: %d\n",players[turn][turnTeam].mineral[0]);
	printf("------------------------------\n");
	printf("1. 칼 상점\n");
	printf("2. 방어구 상점\n" );
	printf("3. 미사일 상점\n" );
	printf("4. 로켓 상점\n" );
	printf("5. 땅 상점\n" );
	printf("6. 땅 업그레이드\n" );
	printf("7. 창고 상점\n" );
	printf("8. 일꾼 상점\n" );
	printf("9. 강화 상점\n" );
	printf("0. 에메랄드 교환소\n" );
	printf("------------------------------\n");

	
	scanf("%d", &mainMarket );
	
	if (mainMarket == 1) 
	{

		printf("에메랄드 개수: %d\n",players[turn][turnTeam].mineral[0]);
		printf("------------------------------\n");
		printf("1. \x1b[34m다이아몬드\x1b[0m 검\n" );
		printf("2. 철 검 \n" );
		printf("3. 돌 검\n" );
		printf("4. 나무 검\n" );
		printf("------------------------------\n");

		scanf("%d", &swordMarket);
		if (swordMarket == 1)
		{
			if (players[turn][turnTeam].mineral[0] < 9)
			{
				printf("에메랄드가 부족합니다.\n");
			}
		}
	}else if (mainMarket == 2)
	{
		char count[4] = {5, 8, 7, 4};
		int materials;
		printf("에메랄드 개수: %d\n",players[turn][turnTeam].mineral[0]);
		printf("재료를 선택하여주십시오\n");
		printf("------------------------------\n");
		printf("1. 철\n");
		printf("2. \x1b[34m다이아몬드\x1b[0m\n");
		printf("------------------------------\n");
		scanf("%d", &materials);
		printf("방어구를 선택해주십시오\n");
		printf("------------------------------\n");
		printf("1. 투구\n");
		printf("2. 흉갑\n");
		printf("3. 레깅스\n");
		printf("4. 부츠\n");
		printf("------------------------------\n");
		scanf("%d",&armorMarket );

		if (players[turn][turnTeam].mineral[0] < count[armorMarket-1] * materials)
		{
			printf("에메랄드가 부족합니다.\n");
			return;
		}
		players[turn][turnTeam].armors[armorMarket-1] = armors[(materials-1)*4 + armorMarket-1];
		players[turn][turnTeam].mineral[0] -= count[armorMarket-1] * materials;
		printf("구매가 완료되었습니다\n");
		playerOnVillage();
	}else if (mainMarket == 3)
	{
		printf("에메랄드 개수: %d\n",players[turn][turnTeam].mineral[0]);
		printf("------------------------------\n");
		printf("1. \x1b[32m핵\x1b[0m 미사일 에메랄드 500개 \n");
		printf("2. \x1b[31m빨강\x1b[0m 마사일 에메랄드 50개\n");
		printf("3. \x1b[33m요격\x1b[0m 마사일 에메랄드 80개\n");
		printf("4. 뇌관제거기 에메랄드 1개\n");
		printf("5. \x1b[32m레이더\x1b[0m 에메랄드 10개\n");
		printf("------------------------------\n");
		scanf("%d",&missileMarket );
		int price[5] = {500, 50, 80, 1, 10};
		if (players[turn][turnTeam].mineral[0] < price[missileMarket])
		{
			printf("에메랄드가 부족합니다.\n");
			return;
		}
		players[turn][turnTeam].mineral[0] -= price[missileMarket];
		players[turn][turnTeam].missile[missileMarket]++;
		printf("구매가 완료되었습니다.\n");
		playerOnVillage();
	}else if (mainMarket == 4)
	{
		printf("에메랄드 개수: %d\n",players[turn][turnTeam].mineral[0]);
		printf("------------------------------------------------------------\n");
		printf("1. 특수 로켓 (데미지 20%%) 에메랄드 20개\n");
		printf("2. 안전한 로켓 (요격 실패율 30%%) 에메랄드 20개\n");
		printf("3. 희미한 로켓 (레이더 20%%) 에메랄드 20개\n");
		printf("4. 완벽한 로켓 (데미지 15, 요격 실패율 20%%, 레이더 15%%) 에메랄드 60개\n");
		printf("------------------------------------------------------------\n");
		scanf("%d", &rocketMarket);
		int price[4] = {20, 20, 20 ,60};
		players[turn][turnTeam].mineral[0] -= price[rocketMarket];
		players[turn][turnTeam].rocket[rocketMarket]++;
	}else if (mainMarket == 5)
	{
		char name[3][50] = {"Hyunseo", "Chanho", "X"};
		printf("에메랄드 개수: %d\n",players[turn][turnTeam].mineral[0]);
		printf("------------------------------\n");
		printf("1번 땅 (주인: %s)\n", name[ lands[1].owner - 1 ]);
		printf("2번 땅 (주인: %s)\n", name[ lands[1].owner - 1 ]);
		printf("3번 땅 (주인: %s)\n", name[ lands[1].owner - 1 ]);
		printf("3번 땅 (주인: %s)\n", name[ lands[1].owner - 1 ]);
		printf("4번 땅 (주인: %s)\n", name[ lands[1].owner - 1 ]);
		printf("5번 땅 (주인: %s)\n", name[ lands[1].owner - 1 ]);
		printf("6번 땅 (주인: %s)\n", name[ lands[1].owner - 1 ]);
		printf("7번 땅 (주인: %s)\n", name[ lands[1].owner - 1 ]);
		printf("8번 땅 (주인: %s)\n", name[ lands[1].owner - 1 ]);
		printf("9번 땅 (주인: %s)\n", name[ lands[1].owner - 1 ]);
		printf("10번 땅 (주인: %s)\n", name[ lands[1].owner - 1 ]);
		printf("11번 땅 (주인: %s)\n", name[ lands[1].owner - 1 ]);
		printf("12번 땅 (주인: %s)\n", name[ lands[1].owner - 1 ]);
		printf("------------------------------\n");
		scanf("%d", &landMarket);
		if (lands[landMarket].owner == 1 || lands[landMarket].owner == 2)
		{
			printf("이미 주인이 있습니다.\n");
			return;
		}
		players[turn][turnTeam].mineral[0] -= 700;
		players[turn][0].land++;
		lands[landMarket].owner = turn + 1;
		playerOnVillage();
	}else if (mainMarket == 6)
	{

		printf("업그레이드할 땅을 선택하여주십시오.\n");


		for ( int i = 0; i < 12; ++i ) {
			if (lands[i].owner - 1 = turn)
			{
				printf("%d땅 %d레벨\n", i, lands[i].groundBlock );
			}
		}

printf("에메랄드 개수: %d\n",players[turn][turnTeam].mineral[0]);
		printf("------------------------------\n");
		printf("1번 땅 (주인: %s)\n", name[ lands[0].owner - 1 ]);
		printf("2번 땅 (주인: %s)\n", name[ lands[1].owner - 1 ]);
		printf("3번 땅 (주인: %s)\n", name[ lands[2].owner - 1 ]);
		printf("3번 땅 (주인: %s)\n", name[ lands[3].owner - 1 ]);
		printf("4번 땅 (주인: %s)\n", name[ lands[4].owner - 1 ]);
		printf("5번 땅 (주인: %s)\n", name[ lands[5].owner - 1 ]);
		printf("6번 땅 (주인: %s)\n", name[ lands[6].owner - 1 ]);
		printf("7번 땅 (주인: %s)\n", name[ lands[7].owner - 1 ]);
		printf("8번 땅 (주인: %s)\n", name[ lands[8].owner - 1 ]);
		printf("9번 땅 (주인: %s)\n", name[ lands[9].owner - 1 ]);
		printf("10번 땅 (주인: %s)\n", name[ lands[10].owner - 1 ]);
		printf("11번 땅 (주인: %s)\n", name[ lands[11].owner - 1 ]);
		printf("12번 땅 (주인: %s)\n", name[ lands[12].owner - 1 ]);
		printf("------------------------------\n");



















	}else if (mainMarket == 7)
	{
		printf("------------------------------\n");
		printf("1. 창고 사기 에메랄드 100개\n");
		printf("2. 창고 열기\n");
		printf("------------------------------\n");
		scanf("%d",&chestMarket);
		if (chestMarket == 1)
		{
			if (players[turn][turnTeam].mineral[0] < 100)
			{
				printf("에메랄드가 부족해 구매가 불가능 합니다.\n");
			} else if (chest[turn].owner == turn )
			{
				printf("이미 창고가 있어 추가 구매 불가능합니다.\n");
			}
			players[turn][turnTeam].mineral[0] -= 100;
			chest[turn].owner = turn;
		} else if (chestMarket == 2)
		{
			int action;
			int inputNumber1;
			int inputNumber2;
			int inputCount;
			int outputNumber;
			int outputCount;

			char mineralNames[8][100] = { "에메랄드", "다이아몬드", "금", "철", "레드스톤", "청금석", "석탄", "돌" };
			char missileNames[5][100] = { "핵 미사일", "빨간 미사일", "요격 미사일", "뇌관제거기", "레이더" };
			char rocketNames[5][100] = { "특수 로켓", "안전한 로켓", "희미한 로켓", "완벽한 로켓" };

			printf("--------------------chest--------inventory------\n");
			printf("1-1. 에메랄드         %3d개            %3d개\n",chest[turn].chestMineral[0] ,players[turn][turnTeam].mineral[0]);
			printf("1-2. 다이아몬드       %3d개            %3d개\n",chest[turn].chestMineral[1] ,players[turn][turnTeam].mineral[1]);
			printf("1-3. 금               %3d개            %3d개\n",chest[turn].chestMineral[2] ,players[turn][turnTeam].mineral[2]);
			printf("1-4. 철               %3d개            %3d개\n",chest[turn].chestMineral[3] ,players[turn][turnTeam].mineral[3]);
			printf("1-5. 레드스톤         %3d개            %3d개\n",chest[turn].chestMineral[4] ,players[turn][turnTeam].mineral[4]);
			printf("1-6. 청금석           %3d개            %3d개\n",chest[turn].chestMineral[5] ,players[turn][turnTeam].mineral[5]);
			printf("1-7. 석탄             %3d개            %3d개\n",chest[turn].chestMineral[6] ,players[turn][turnTeam].mineral[6]);
			printf("1-8. 돌               %3d개            %3d개\n",chest[turn].chestMineral[7] ,players[turn][turnTeam].mineral[7]);
			printf("2-1. 핵 미사일        %3d개            %3d개\n",chest[turn].chestMissile[0] ,players[turn][turnTeam].missile[0]);
			printf("2-2. 빨강 미사일     %3d개            %3d개\n",chest[turn].chestMissile[1] ,players[turn][turnTeam].missile[1]);
			printf("2-3. 요격 미사일     %3d개            %3d개\n",chest[turn].chestMissile[2] ,players[turn][turnTeam].missile[2]);
			printf("2-4. 뇌관 제거기     %3d개            %3d개\n",chest[turn].chestMissile[3] ,players[turn][turnTeam].missile[3]);
			printf("2-5. 레이더          %3d개            %3d개\n",chest[turn].chestMissile[4] ,players[turn][turnTeam].missile[4]);
			printf("3-1. 특수 로켓       %3d개            %3d개\n",chest[turn].chestRocket[0] ,players[turn][turnTeam].rocket[0]);
			printf("3-2. 안전한 로켓     %3d개            %3d개\n",chest[turn].chestRocket[1] ,players[turn][turnTeam].rocket[1]);
			printf("3-3. 희미한 로켓     %3d개            %3d개\n",chest[turn].chestRocket[2] ,players[turn][turnTeam].rocket[2]);
			printf("3-4. 완벽한 로켓     %3d개            %3d개\n",chest[turn].chestRocket[3] ,players[turn][turnTeam].rocket[3]);
			printf("4-1. 황금 사과       %3d개            %3d개\n",chest[turn].chestGoldenApple ,players[turn][turnTeam].goldenApple);		
			printf("------------------------------------------------\n");
			printf("1. 꺼내기\n");
			printf("2. 넣기\n");
			printf("------------------------------------------------\n");

			scanf("%d", &action);

			if (action == 1)
			{
				printf("꺼낼 물건 첫번쨰 번호를 정해주십시오.\n");
				scanf("%d", &inputNumber1 );
				printf("꺼낼 물건 두번쨰 번호를 정해주십시오.\n");
				scanf("%d", &inputNumber2 );
				printf("꺼낼 물건 개수를 정해주십시오.\n");
				scanf("%d", &inputCount );
				if (inputNumber1 == 1) // 광물
				{
					if (inputCount > chest[turn].chestMineral[inputNumber2-1])
					{
						printf("%s가 부족합니다.\n", mineralNames[inputNumber2-1]);
						playerOnVillage();
					}
					chest[turn].chestMineral[inputNumber2-1] -= inputCount;
					players[turn][turnTeam].mineral[inputNumber2-1] += inputCount;
				} else if (inputNumber1 == 2) // 미사일
				{
					if (inputCount > chest[turn].chestMissile[inputNumber2-1])
					{
						printf("%s이 부족합니다.\n",missileNames[inputNumber2-1]);
						playerOnVillage();
					} 
					chest[turn].chestMissile[inputNumber2-1] -= inputCount;
					players[turn][turnTeam].missile[inputNumber2-1] += inputCount;
				} else if (inputNumber1 == 3) // 로켓
				{
					if (inputCount > chest[turn].chestRocket[inputNumber2-1])
					{
						printf("%s이 부족합니다.\n",rocketNames[inputNumber2-1]);
						playerOnVillage();
					} 
					chest[turn].chestRocket[inputNumber2-1] -= inputCount;
					players[turn][turnTeam].rocket[inputNumber2-1] += inputCount;
				} else if (inputNumber1 == 4) // 황금 사고
				{
					if (inputCount > chest[turn].chestGoldenApple)
					{
						printf("황금 사과가 부족합니다.\n");
						playerOnVillage();
					}
					chest[turn].chestGoldenApple -= inputCount;
					players[turn][turnTeam].goldenApple += inputCount;
				}
				printf("아이템 %d개를 상자에서 꺼냈습니다.\n", inputCount);
				playerOnVillage();
			} else if (action == 2)
			{
				printf("넣을 물건 첫번쨰 번호를 정해주십시오.\n");
				scanf("%d", &inputNumber1 );
				printf("넣을 물건 두번쨰 번호를 정해주십시오.\n");
				scanf("%d", &inputNumber2 );
				printf("넣을 물건 개수를 정해주십시오.\n");
				scanf("%d", &inputCount );
				if (inputNumber1 == 1) // 광물
				{
					if (inputCount > players[turn][turnTeam].mineral[inputNumber2-1])
					{
						printf("%s가 부족합니다.\n", mineralNames[inputNumber2-1]);
						playerOnVillage();
					}
					players[turn][turnTeam].mineral[inputNumber2-1] -= inputCount;
					chest[turn].chestMineral[inputNumber2-1] += inputCount;
				} else if (inputNumber1 == 2) // 미사일
				{
					if (inputCount > players[turn][turnTeam].missile[inputNumber2-1])
					{
						printf("%s이 부족합니다.\n",missileNames[inputNumber2-1]);
						playerOnVillage();
					} 
					players[turn][turnTeam].missile[inputNumber2-1] -= inputCount;
					chest[turn].chestMissile[inputNumber2-1] += inputCount;
				} else if (inputNumber1 == 3) // 로켓
				{
					if (inputCount > players[turn][turnTeam].rocket[inputNumber2-1])
					{
						printf("%s이 부족합니다.\n",rocketNames[inputNumber2-1]);
						playerOnVillage();
					} 
					players[turn][turnTeam].rocket[inputNumber2-1] -= inputCount;
					chest[turn].chestRocket[inputNumber2-1] += inputCount;
				} else if (inputNumber1 == 4) // 황금 사과
				{
					if (inputCount > players[turn][turnTeam].goldenApple)
					{
						printf("황금 사과가 부족합니다.\n");
						playerOnVillage();
					}
					players[turn][turnTeam].goldenApple -= inputCount;
					chest[turn].chestGoldenApple += inputCount;
				}
				printf("아이템 %d개를 상자에 넣었습니다.\n", inputCount);
				playerOnVillage();
			}
		}
	}else if (mainMarket == 8)
	{
		if (players[turn][turnTeam].mineral[1] < 5)
		{
			 printf("다이아몬드가 부족합니다.\n");
			 return;
		}
		players[turn][turnTeam].mineral[1] -= 5;
		printf("백성의 이름을 정해주십시오\n");
		scanf("%d", &workerMarket );
		players[turn][teamCount[turn]] = (Player) { 32, 32, workerMarket, 10, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0}, {helmetBase, chestplateBase, leggingsBase, bootsBase}, swordFist, {0, 0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0}, 0};
		teamCount[turn]++;
		printf("성공적으로 채용했습니다.\n");
	}else if (mainMarket == 9)
	{
		printf("현재 재산: %d개\n",  players[turn][turnTeam].mineral[0]);
		printf("------------------------------\n");
		printf("1. 강화석 구매\n");
		printf("2. 강화 향상제 구매\n");
		printf("3. 폭파 감소제 구매\n");
		printf("4. 강화하기\n");
		printf("------------------------------\n");
		scanf("%d", &reinforceMarket);
		if (reinforceMarket == 1)
		{
			printf("사실 강화석 개수를 정해주십시오\n");
			scanf("%d", &reinStoneCount);
			if (players[turn][turnTeam].mineral[0] < 3*reinStoneCount)
			{
				printf("돈이 부족합니다.\n");
				return;
			}
			players[turn][turnTeam].mineral[0] -= 3*reinStoneCount;
			players[turn][turnTeam].reinforce[0] += reinStoneCount;
			printf("구매 완료했습니다.\n");
		}else if (reinforceMarket == 2)
		{
			printf("사실 강화 향상제 개수를 정해주십시오\n");
			scanf("%d", &reinForceUpGradeStone);
			if (players[turn][turnTeam].mineral[0] < 5*reinForceUpGradeStone)
			{
				printf("돈이 부족합니다.\n");
				return;
			}
			players[turn][turnTeam].mineral[0] -= 5*reinForceUpGradeStone;
			players[turn][turnTeam].reinforce[1] += reinForceUpGradeStone;
			printf("구매 완료했습니다.\n");
		}else if (reinforceMarket == 3)
		{
			printf("사실 폭파 감소제 개수를 정해주십시오\n");
			scanf("%d", &reinForceBoomLowerStone);
			if (players[turn][turnTeam].mineral[0] < 5*reinForceBoomLowerStone)
			{
				printf("돈이 부족합니다.\n");
				return;
			}
			players[turn][turnTeam].mineral[0] -= 5*reinForceBoomLowerStone;
			players[turn][turnTeam].reinforce[2] += reinForceBoomLowerStone;
			printf("구매 완료했습니다.\n");
		} else if (reinforceMarket == 4)
		{
			printf("강화할 아이템을 정해주십시오.\n");
			printf("1. 검\n");
			printf("2. 투구\n");
			printf("3. 흉갑\n");
			printf("4. 레깅스\n");
			printf("5. 부츠\n");
			scanf("%d", &reinForceItem);

			if (reinForceItem == 1) {
				if (players[turn][turnTeam].sword.reinForce >= players[turn][turnTeam].reinforce[0] ) {
					printf(" 강화석이 부족합니다.\n");
					return;
				}
				printf("사용하실 특수 아이템 개수를 순서대로 적어주십시오\n");
				scanf("%d", &firstStoneCount);
				scanf("%d", &secondStoneCount);

				if (players[turn][turnTeam].reinforce[1] < firstStoneCount || players[turn][turnTeam].reinforce[2] < secondStoneCount) {
					printf("특수 아이템이 부족합니다.\n");
				}

				players[turn][turnTeam].reinforce[1] -= firstStoneCount;
				players[turn][turnTeam].reinforce[2] -= secondStoneCount;
				players[turn][turnTeam].reinforce[0] -= players[turn][turnTeam].sword.reinForce + 1;
				sucessPer = sucessPercent[players[turn][turnTeam].sword.reinForce + 1] + firstStoneCount * 5;
				BoomPer = 100 - BoomPercent[players[turn][turnTeam].sword.reinForce + 1] + secondStoneCount * 5;
				sucess = rand() % 100 / 100 * sucessPer;
				Boom = rand() % 100 / 100 * BoomPer;

				if (Boom < 100) {
					players[turn][turnTeam].sword = swordFist; 
					printf("아이템이 강화하던 도중 파괴되었습니다.\n");
				} else if (sucess < 100) {
					printf("강화에 실패하였습니다.\n");
				} else {
					players[turn][turnTeam].sword.reinForce++;
					printf("\x1b[31m강\x1b[0m\x1b[33m화\x1b[0m\x1b[32m%d\x1b[0m\x1b[36m강\x1b[0m\x1b[34m성\x1b[0m\x1b[35m공\x1b[0m\n", players[turn][turnTeam].sword.reinForce);
					return;
				}
			}

			for ( int i = 0; i < 4; ++i ) {
				if (players[turn][turnTeam].armors[i].reinforce >= players[turn][turnTeam].reinforce[0]) {
					printf(" 강화석이 부족합니다.\n");
					return;
				}
			}

			printf("사용하실 특수 아이템 개수를 순서대로 적어주십시오\n");
			scanf("%d", &firstStoneCount);
			scanf("%d", &secondStoneCount);

			if (players[turn][turnTeam].reinforce[1] < firstStoneCount || players[turn][turnTeam].reinforce[2] < secondStoneCount) {
				printf("특수 아이템이 부족합니다.\n");
			}

			players[turn][turnTeam].reinforce[1] -= firstStoneCount;
			players[turn][turnTeam].reinforce[2] -= secondStoneCount;
			players[turn][turnTeam].reinforce[0] -= players[turn][turnTeam].armors[reinForceItem - 2].reinforce + 1;
			sucessPer = sucessPercent[players[turn][turnTeam].armors[reinForceItem - 2].reinforce + 1] + firstStoneCount * 5;
			BoomPer = 100 - BoomPercent[players[turn][turnTeam].armors[reinForceItem - 2].reinforce + 1] + secondStoneCount * 5;
			sucess = rand() % 100 / 100 * sucessPer;
			Boom = rand() % 100 / 100 * BoomPer;

			if (Boom < 100) {
				int material = players[turn][turnTeam].armors[reinForceItem - 2].material;

				if ( material == helmetIron.material || material == helmetDiamond.material)
				{
					players[turn][turnTeam].armors[reinForceItem - 2] = helmetBase;
				}else if (material == chestplateIron.material || material == chestplateDiamond.material)
				{
					players[turn][turnTeam].armors[reinForceItem - 2] = chestplateBase;
				}else if (material == leggingsIron.material || material == leggingsDiamond.material)
				{
					players[turn][turnTeam].armors[reinForceItem - 2] = leggingsBase;
				}else if (material == bootsIron.material || material == bootsDiamond.material)
				{
					players[turn][turnTeam].armors[reinForceItem - 2] = bootsBase;
				}
				printf("아이템이 강화하던 도중 파괴되었습니다.\n");
				return;
			} else if (sucess < 100)
			{
				printf("강화에 실패하였습니다.\n");
				return;
			} else {
				players[turn][turnTeam].armors[reinForceItem - 2].reinforce++;
				printf("\x1b[31m강\x1b[0m\x1b[33m화\x1b[0m\x1b[32m%d\x1b[0m\x1b[36m강\x1b[0m\x1b[34m성\x1b[0m\x1b[35m공\x1b[0m\n", players[turn][turnTeam].armors[reinForceItem - 2].reinforce);
				return;
			}
		}
	} else if (mainMarket == 0)
	{
		printf("------------------------------\n");
		printf("1. 석탄 ☓ 8 → 에메랄드\n");
		printf("2. 철 ☓ 7 → 에메랄드\n");
		printf("3. 금 ☓ 5 → 다이아몬드\n");
		printf("4. 돌 ☓ 16 → 다이아몬드\n");
		printf("5. 다이아 ☓ 3 → 에메랄드\n");
		printf("------------------------------\n");
		printf("에메랄드 %d개\n", players[turn][turnTeam].mineral[0] );
		printf("다이아몬드 %d개\n", players[turn][turnTeam].mineral[1] );
		printf("금 %d개\n", players[turn][turnTeam].mineral[2] );
		printf("철 %d개\n", players[turn][turnTeam].mineral[3] );
		printf("레드스톤 %d개\n", players[turn][turnTeam].mineral[4] );
		printf("청금석 %d개\n", players[turn][turnTeam].mineral[5] );
		printf("석탄 %d개\n", players[turn][turnTeam].mineral[6] );
		printf("돌 %d개\n", players[turn][turnTeam].mineral[7] );
		printf("------------------------------\n");
		scanf("%d", &exchangeHouse);
		if (exchangeHouse == 1)
		{	
			for ( int i = 0; i < players[turn][turnTeam].mineral[6] / 8; ++i ) {
				players[turn][turnTeam].mineral[1] += 1;
				players[turn][turnTeam].mineral[6] -= 8; 
			}
		}else if (exchangeHouse == 2)
		{
			for ( int i = 0; i < players[turn][turnTeam].mineral[3] / 7; ++i ) {
				players[turn][turnTeam].mineral[1] += 1;
				players[turn][turnTeam].mineral[3] -= 7;
			}
		}else if (exchangeHouse == 3)
		{
			for ( int i = 0; i < players[turn][turnTeam].mineral[2] / 5; ++i ) {
				players[turn][turnTeam].mineral[2] += 1;
				players[turn][turnTeam].mineral[2] -= 5;
			}
		}else if (exchangeHouse == 4)
		{
			for ( int i = 0; i < players[turn][turnTeam].mineral[7] / 16; ++i ) {
				players[turn][turnTeam].mineral[2] += 1;
				players[turn][turnTeam].mineral[7] -= 16;
			}
		}else if (exchangeHouse == 5)
		{
			for ( int i = 0; i < players[turn][turnTeam].mineral[2] / 3; ++i ) {
				players[turn][turnTeam].mineral[1]++;
				players[turn][turnTeam].mineral[2] -= 3;
			}
		}
	}
}



void playerOnPlayer ( int i ) {

}

void setupMap () {
	memcpy( &map[0],   "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", 118);
	memcpy( &map[1],   "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);	
	memcpy( &map[2],   "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);	
	memcpy( &map[3],   "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[4],   "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[5],   "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[6],   "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[7],   "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[8],   "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[9],   "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[10],  "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[11],  "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", 118);
	memcpy( &map[12],  "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", 118);
	memcpy( &map[13],  "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", 118);
	memcpy( &map[14],  "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", 118);
	memcpy( &map[15],  "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", 118);
	memcpy( &map[16],  "0000111111111111111111110000000000222222222222222222222222222222222222222222222222220000000000111111111111111111110000", 118);
	memcpy( &map[17],  "0000111111111111111111110000000000222222222266666666662233333322555555555522222222220000000000111111111111111111110000", 118);
	memcpy( &map[18],  "0000111111111111111111110000000000222222222266666666662233333322555555555522222222220000000000111111111111111111110000", 118);
	memcpy( &map[19],  "0000111111111111111111110000000000222222222266666666663333333333555555555522222222220000000000111111111111111111110000", 118);
	memcpy( &map[20],  "0000111111111111111111110000000000222222222266666666662233333322555555555522222222220000000000111111111111111111110000", 118);
	memcpy( &map[21],  "0000111111111111111111110000000000222222222266666666662233333322555555555522222222220000000000111111111111111111110000", 118);
	memcpy( &map[22],  "0000111111111111111111110000000000222222222222222222222233333322222222222222222222220000000000111111111111111111110000", 118);
	memcpy( &map[23],  "0000111111111111111111110000000000222222222222222222222233333322444444444444444444220000000000111111111111111111110000", 118);
	memcpy( &map[24],  "0000111111111111111111110000000000222222777777777722222233333322444444444444444444220000000000111111111111111111110000", 118);
	memcpy( &map[25],  "0000111111111111111111110000000000222222777777777722222233333322444444444444444444220000000000111111111111111111110000", 118);
	memcpy( &map[26],  "0000000000000000000000000000000000222222222233222222222233333322223322222222222222220000000000000000000000000000000000", 118);
	memcpy( &map[27],  "0000000000000000000000000000000000223333333333333333333333333333333333333333333333220000000000000000000000000000000000", 118);
	memcpy( &map[28],  "0000000000000000000000000000000000223333333333333333333333333333333333333333333333220000000000000000000000000000000000", 118);
	memcpy( &map[29],  "0000000000000000000000000000000000223333333333333333333333333333333333333333333333220000000000000000000000000000000000", 118);
	memcpy( &map[30],  "0000000000000000000000000000000000222222222233222222222233333322222222222222222222220000000000000000000000000000000000", 118);
	memcpy( &map[31],  "0000111111111111111111110000000000222222888888888822222233333322222222222222222222220000000000111111111111111111110000", 118);
	memcpy( &map[32],  "0000111111111111111111110000000000222222888888888822222233333322222222222222222222220000000000111111111111111111110000", 118);
	memcpy( &map[33],  "0000111111111111111111110000000000222222222222222222222233333322222222222222222222220000000000111111111111111111110000", 118);
	memcpy( &map[34],  "0000111111111111111111110000000000222222222222222222222233333322222222222222222222220000000000111111111111111111110000", 118);
	memcpy( &map[35],  "0000111111111111111111110000000000222222222222222222222233333322222222222222222222220000000000111111111111111111110000", 118);
	memcpy( &map[36],  "0000111111111111111111110000000000222222222222222222222233333322222222222222222222220000000000111111111111111111110000", 118);
	memcpy( &map[37],  "0000111111111111111111110000000000222222222222229999992233333322aaaaaa222222222222220000000000111111111111111111110000", 118);
	memcpy( &map[38],  "0000111111111111111111110000000000222222222222229999993333333333aaaaaa222222222222220000000000111111111111111111110000", 118);
	memcpy( &map[39],  "0000111111111111111111110000000000222222222222229999992233333322aaaaaa222222222222220000000000111111111111111111110000", 118);
	memcpy( &map[40],  "0000111111111111111111110000000000222222222222222222222222222222222222222222222222220000000000111111111111111111110000", 118);
	memcpy( &map[41],  "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", 118);
	memcpy( &map[42],  "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", 118);
	memcpy( &map[43],  "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", 118);
	memcpy( &map[44],  "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", 118);
	memcpy( &map[45],  "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", 118);
	memcpy( &map[46],  "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[47],  "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[48],  "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[49],  "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[50],  "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[51],  "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[52],  "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[53],  "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[54],  "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[55],  "0000111111111111111111110000000000111111111111111111110000000000111111111111111111110000000000111111111111111111110000", 118);
	memcpy( &map[56],  "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", 118);

}

void missile (int x, int y) {
	//memcpy( &map[50][5], "0000000", 7);
	for ( int i = -3; i < 4; ++i ) {
		for ( int j = -7; j < 7; ++j ) {
			if (map[x + i][y + j] == '1')
			{
				map[x + i][y + j] = '5';
			}
			
		}
	}
}

void setup () {

	setupMap();


}

void draw () {
	for ( int i = 0; i < R; ++i ) {
		for ( int j = 0; j < C; ++j ) {
			char m = map[i][j];
			
			if (m == '0') printf("\x1b[47;30m"); // 땅 
			else if (m == '1') printf("\x1b[40m" ); // 10X10땅  
			else if (m == '2') printf("\x1b[0;30m" ); // 벽  
			else if (m == '3') printf("\x1b[43;30m" ); // 스폰 길 
			else if (m == '4') printf("\x1b[44m" ); // 상점 
			else if (m == '5') printf("\x1b[41m" ); // 땅 텔포  
			else if (m == '6') printf("\x1b[45m" ); // 회의 장 
			else if (m == '7') printf("\x1b[42m" ); // 로또 
			else if (m == '8') printf("\x1b[42m" ); // 잭 팟 
			else if (m == '9') printf("\x1b[40m" ); // 창고1 
			else if (m == 'a') printf("\x1b[40m" ); // 창고 2 

			if (i == players[0][turnTeam].x && (j == players[0][turnTeam].y || j == players[0][turnTeam].y + 1)) {
				printf("\x1b[46;30mH");
			} else if (i == players[1][turnTeam].x  && (j == players[1][turnTeam].y || j == players[1][turnTeam].y + 1)) {
				printf("\x1b[45;30mC");
			} else {
				printf(" ");
			}

			printf("\x1b[0m");

		}
		printf("\n");
	}

}

void getInfo () {

}

void getInput () {
	char input[10];
	scanf("%s", input );

	qx = players[turn][turnTeam].x;
	qy = players[turn][turnTeam].y;


	switch(input[0]) {
		case 'w': 
		case 'i':
			qx = players[turn][turnTeam].x - 1;
			break;
		case 's':
		case 'k':
			qx = players[turn][turnTeam].x + 1;
			break;
		case 'a':
		case 'j':
			qy = players[turn][turnTeam].y - 2;
			break;
		case 'd':
		case 'l':
			qy = players[turn][turnTeam].y + 2;
			break;
		case 'q':
		case 'n':
			qx = 28;
			qy = 58;
		case 'e':
		case 'o':
			getInfo();
		default:
			break;
	}

	switch(map[players[turn][turnTeam].x][players[turn][turnTeam].y]) {
		case '0':
			break;
		case '1':
			break;
		case '2':
			 qx = players[turn][turnTeam].x;
			 qy = players[turn][turnTeam].y;
			break;
		case '3':
			break;
		case '4':
			playerOnVillage();
			break;
		case '5':
			playerOnLandTeleport();
			break;
		case '6':
			playerOnConferenceRoom();
			break;
		case '7':
			playerOnLotto();
			break;
		case '8':
			playerOnJackPot();
			break;
		case '9':
			playerOnChestOne();
			break;
		case 'a':
			playerOnChestTwo();
			break;
		default:
			break;
	}

	players[turn][turnTeam].x = qx;
	players[turn][turnTeam].y = qy;
}

void process () {

	if ( turnTeam < teamCount[turn] - 1 ) {
		turnTeam++;
		printf("성공적으로 턴을 끝냈습니다.\n");
	} else {
		timer++;
		turnTeam = 0;	
		turn = 1 - turn;
	}
	
}

int main () {


    setup();
    // draw();

	while (GAME) {

		draw();
		getInput();
		process();

	}  

	printf("server: 게임이 종료되었습니다.\n");	
	return 0;
}	

/*

+---------+------------+------------+
0  color  0 foreground 0 background 0
0         0    code    0    code    0
+---------+------------+------------+
0 black   0     30     0     40     0
0 red     0     31     0     41     0
0 green   0     32     0     42     0
0 yellow  0     33     0     43     0
0 blue    0     34     0     44     0
0 magenta 0     35     0     45     0
0 cyan    0     36     0     46     0
0 white   0     37     0     47     0
+---------+------------+------------+

*/