#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define R 64
#define C 64

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
	int hitpoint;
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


Player HyunseoPlayer = { R/2, 0, 'H', 10, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0}, {helmetBase, chestplateBase, leggingsBase, bootsBase}, swordFist, {0, 0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0}, 0};
Player ChanhoPlayer = { R/2, C-1, 'A', 10, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0}, {helmetBase, chestplateBase, leggingsBase, bootsBase}, swordFist, {0, 0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0}, 0};

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
int qy;



int GAME = 1;

void getInput();
void process();

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
	} else if (mainMarket == 2)
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
				if (inputNumber1 == 1)
				{
					if (inputNumber2 == 1)
					{
						if (inputCount > chest[turn].chestMineral[0])
						{
							printf("에메랄드가 부족합니다.\n");
							playerOnVillage();
						}
						chest[turn].chestMineral[0] -= inputCount;
						players[turn][turnTeam].mineral[0] += inputCount;
 					}else if (inputNumber2 == 2)
					{
						if (inputCount > chest[turn].chestMineral[1])
						{
							printf("다이아몬드가 부족합니다.\n");
							playerOnVillage();
						}
						chest[turn].chestMineral[1] -= inputCount;
						players[turn][turnTeam].mineral[1] += inputCount; 
					}else if (inputNumber2 == 3)
					{
						if (inputCount > chest[turn].chestMineral[2])
						{
							printf("금이 부족합니다.\n");
							playerOnVillage();
						} 
						chest[turn].chestMineral[2] -= inputCount;
						players[turn][turnTeam].mineral[2] += inputCount;
					}else if (inputNumber2 == 4)
					{
						if (inputCount > chest[turn].chestMineral[3])
						{
							printf("철이 부족합니다.\n");
							playerOnVillage();
						}  
						chest[turn].chestMineral[3] -= inputCount;
						players[turn][turnTeam].mineral[3] += inputCount;
					}else if (inputNumber2 == 5)
					{
						if (inputCount > chest[turn].chestMineral[4])
						{
							printf("레드스톤이 부족합니다.\n");
							playerOnVillage();
						}  
						chest[turn].chestMineral[4] -= inputCount;
						players[turn][turnTeam].mineral[4] += inputCount;
					}else if (inputNumber2 == 6)
					{
						if (inputCount > chest[turn].chestMineral[5])
						{
							printf("청금석이 부족합니다.\n");
							playerOnVillage();
						}  
						chest[turn].chestMineral[5] -= inputCount;
						players[turn][turnTeam].mineral[5] += inputCount;
					}else if (inputNumber2 == 7)
					{
						if (inputCount > chest[turn].chestMineral[6])
						{
							printf("석탄이 부족합니다.\n");
							playerOnVillage();
						}  
						chest[turn].chestMineral[6] -= inputCount;
						players[turn][turnTeam].mineral[6] += inputCount;
					}else if (inputNumber2 == 8)
					{
						if (inputCount > chest[turn].chestMineral[7])
						{
							printf("돌이 부족합니다.\n");
							playerOnVillage();
						} 
						chest[turn].chestMineral[7] -= inputCount;
						players[turn][turnTeam].mineral[7] += inputCount;
					}
				}else if (inputNumber1 == 2)
				{
					if (inputNumber2 == 1)
					{
						if (inputCount > chest[turn].chestMissile[0])
						{
							printf("핵 미사일이 부족합니다.\n");
							playerOnVillage();
						} 
						chest[turn].chestMissile[0] -= inputCount;
						players[turn][turnTeam].missile[0] += inputCount;
					}else if (inputNumber2 == 2)
					{
						if (inputCount > chest[turn].chestMissile[1])
						{
							printf(" 빨강 미사일이 부족합니다.\n");
							playerOnVillage();
						} 
						chest[turn].chestMissile[1] -= inputCount;
						players[turn][turnTeam].missile[1] += inputCount;
					}else if (inputNumber2 == 3)
					{
						if (inputCount > chest[turn].chestMissile[2])
						{
							printf(" 요격 미사일이 부족합니다.\n");
							playerOnVillage();
						} chest[turn].chestMissile[2] -= inputCount;
						players[turn][turnTeam].missile[2] += inputCount;
					}else if (inputNumber2 == 4)
					{
						if (inputCount > chest[turn].chestMissile[3])
						{
							printf(" 뇌관 제거기가 부족합니다.\n");
							playerOnVillage();
						} 
						chest[turn].chestMissile[3] -= inputCount;
						players[turn][turnTeam].missile[3] += inputCount;
					}else if (inputNumber2 == 5)
					{
						if (inputCount > chest[turn].chestMissile[4])
						{
							printf(" 레이더가 부족합니다.\n");
							playerOnVillage();
						} 
						chest[turn].chestMissile[3] -= inputCount;
						players[turn][turnTeam].missile[3] += inputCount;
					}
				}else if (inputNumber1 == 3)
				{
					if (inputNumber2 == 1)
					{
						if (inputCount > chest[turn].chestRocket[0])
						{
							printf("특수 로켓이 부족합니다.\n");
							playerOnVillage();
						} 
						chest[turn].chestRocket[0] -= inputCount;
						players[turn][turnTeam].rocket[0] += inputCount;
					}else if (inputNumber2 == 2)
					{
						if (inputCount > chest[turn].chestRocket[1])
						{
							printf("안전한 로켓이 부족합니다.\n");
							playerOnVillage();
						} 
						chest[turn].chestRocket[1] -= inputCount;
						players[turn][turnTeam].rocket[1] += inputCount;
					}else if (inputNumber2 == 3)
					{
						if (inputCount > chest[turn].chestRocket[2])
						{
							printf("희미한 로켓이 부족합니다.\n");
							playerOnVillage();
						} 
						chest[turn].chestRocket[2] -= inputCount;
						players[turn][turnTeam].rocket[2] += inputCount;
					}else if (inputNumber2 == 4)
					{
						if (inputCount > chest[turn].chestRocket[3])
						{
							printf("완벽한 로켓이 부족합니다.\n");
							playerOnVillage();
						}
						chest[turn].chestRocket[3] -= inputCount;
						players[turn][turnTeam].rocket[3] += inputCount; 
					}
				}else if (inputNumber1 == 4)
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
				if (inputNumber1 == 1)
				{
					if (inputNumber2 == 1)
					{
						if (inputCount > players[turn][turnTeam].mineral[0])
						{
							printf("에메랄드가 부족합니다.\n");
							playerOnVillage();
						}
						players[turn][turnTeam].mineral[0] -= inputCount;
						chest[turn].chestMineral[0] += inputCount;
 					}else if (inputNumber2 == 2)
					{
						if (inputCount > players[turn][turnTeam].mineral[1])
						{
							printf("다이아몬드가 부족합니다.\n");
							playerOnVillage();
						}
						players[turn][turnTeam].mineral[1] -= inputCount;
						chest[turn].chestMineral[1] += inputCount; 
					}else if (inputNumber2 == 3)
					{
						if (inputCount > players[turn][turnTeam].mineral[2])
						{
							printf("금이 부족합니다.\n");
							playerOnVillage();
						} 
						players[turn][turnTeam].mineral[2] -= inputCount;
						chest[turn].chestMineral[2] += inputCount;
					}else if (inputNumber2 == 4)
					{
						if (inputCount > players[turn][turnTeam].mineral[3])
						{
							printf("철이 부족합니다.\n");
							playerOnVillage();
						}  
						players[turn][turnTeam].mineral[3] -= inputCount;
						chest[turn].chestMineral[3] += inputCount;
					}else if (inputNumber2 == 5)
					{
						if (inputCount > players[turn][turnTeam].mineral[4])
						{
							printf("레드스톤이 부족합니다.\n");
							playerOnVillage();
						}  
						players[turn][turnTeam].mineral[4] -= inputCount;
						chest[turn].chestMineral[4] += inputCount;
					}else if (inputNumber2 == 6)
					{
						if (inputCount > players[turn][turnTeam].mineral[5])
						{
							printf("청금석이 부족합니다.\n");
							playerOnVillage();
						}  
						players[turn][turnTeam].mineral[5] -= inputCount;
						chest[turn].chestMineral[5] += inputCount;
					}else if (inputNumber2 == 7)
					{
						if (inputCount > players[turn][turnTeam].mineral[6])
						{
							printf("석탄이 부족합니다.\n");
							playerOnVillage();
						}  
						players[turn][turnTeam].mineral[6] -= inputCount;
						chest[turn].chestMineral[6] += inputCount;
					}else if (inputNumber2 == 8)
					{
						if (inputCount > players[turn][turnTeam].mineral[7])
						{
							printf("돌이 부족합니다.\n");
							playerOnVillage();
						} 
						players[turn][turnTeam].mineral[7] -= inputCount;
						chest[turn].chestMineral[7] += inputCount;
					}
				}else if (inputNumber1 == 2)
				{
					if (inputNumber2 == 1)
					{
						if (inputCount > players[turn][turnTeam].missile[0])
						{
							printf("핵 미사일이 부족합니다.\n");
							playerOnVillage();
						} 
						players[turn][turnTeam].missile[0] -= inputCount;
						chest[turn].chestMissile[0] += inputCount;
					}else if (inputNumber2 == 2)
					{
						if (inputCount > players[turn][turnTeam].missile[1])
						{
							printf(" 빨강 미사일이 부족합니다.\n");
							playerOnVillage();
						} 
						players[turn][turnTeam].missile[1] -= inputCount;
						chest[turn].chestMissile[1] += inputCount;
					}else if (inputNumber2 == 3)
					{
						if (inputCount > players[turn][turnTeam].missile[2])
						{
							printf(" 요격 미사일이 부족합니다.\n");
							playerOnVillage();
						}
						chest[turn].chestMissile[2] -= inputCount;
						players[turn][turnTeam].missile[2] += inputCount;
					}else if (inputNumber2 == 4)
					{
						if (inputCount > players[turn][turnTeam].missile[3])
						{
							printf(" 뇌관 제거기가 부족합니다.\n");
							playerOnVillage();
						} 
						players[turn][turnTeam].missile[3] -= inputCount;
						chest[turn].chestMissile[3] += inputCount;
					}else if (inputNumber2 == 5)
					{
						if (inputCount > players[turn][turnTeam].missile[4])
						{
							printf(" 레이더가 부족합니다.\n");
							playerOnVillage();
						} 
						players[turn][turnTeam].missile[3] -= inputCount;
						chest[turn].chestMissile[3] += inputCount;
					}
				}else if (inputNumber1 == 3)
				{
					if (inputNumber2 == 1)
					{
						if (inputCount > players[turn][turnTeam].rocket[0])
						{
							printf("특수 로켓이 부족합니다.\n");
							playerOnVillage();
						} 
						players[turn][turnTeam].rocket[0] -= inputCount;
						chest[turn].chestRocket[0] += inputCount;
					}else if (inputNumber2 == 2)
					{
						if (inputCount > players[turn][turnTeam].rocket[1])
						{
							printf("안전한 로켓이 부족합니다.\n");
							playerOnVillage();
						} 
						players[turn][turnTeam].rocket[1] -= inputCount;
						chest[turn].chestRocket[1] += inputCount;
					}else if (inputNumber2 == 3)
					{
						if (inputCount > players[turn][turnTeam].rocket[2])
						{
							printf("희미한 로켓이 부족합니다.\n");
							playerOnVillage();
						} 
						players[turn][turnTeam].rocket[2] -= inputCount;
						chest[turn].chestRocket[2] += inputCount;
					}else if (inputNumber2 == 4)
					{
						if (inputCount > players[turn][turnTeam].rocket[3])
						{
							printf("완벽한 로켓이 부족합니다.\n");
							playerOnVillage();
						}
						players[turn][turnTeam].rocket[3] -= inputCount;
						chest[turn].chestRocket[3] += inputCount; 
					}else if (inputNumber1 == 4)
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

}

void playerOnPlayer ( int i ) {

}

void setup () {

}

void draw () {

}

void getInfo () {

}  

void getInput () {
	for ( int i = 0; i < 2; ++i ) {
		for ( int j = 0; j < teamCount[i]; ++j ) {
			map[players[i][j].x][players[i][j].y] = players[i][j].name;
		}
	}
	for ( int i = 0; i < teamCount[1-turn]; ++i ) {
		if (map[qx][qy] == players[1-turn][i].name ) {
			playerOnPlayer( i );
			break;
		}
	}
	if ( turnTeam < teamCount[turn] - 1 ) {
		turnTeam++;
		printf("성공적으로 턴을 끝냈습니다.\n");
	} else {
		timer++;
		turnTeam = 0;	
		turn = 1 - turn;
	}
}

void process () {

}

int main () {


    setup();

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
|  color  | foreground | background |
|         |    code    |    code    |
+---------+------------+------------+
| black   |     30     |     40     |
| red     |     31     |     41     |
| green   |     32     |     42     |
| yellow  |     33     |     43     |
| blue    |     34     |     44     |
| magenta |     35     |     45     |
| cyan    |     36     |     46     |
| white   |     37     |     47     |
+---------+------------+------------+

*/
