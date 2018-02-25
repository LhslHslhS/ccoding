#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long coin = 1000000;
int day = 1;
char nickname[100];
unsigned long count[3] = { 0, 0, 0 };
unsigned long price[3] = { 100000, 200000, 500000 };
char name[3][100] = { "사성주식", "LPG주식", "microhard" };
int input;
int warning = 0;

unsigned long assetAfter, assetBefore, income;

int j, k, l;

long friendCoin[3] = { 1000000, 1000000, 1000000 };
unsigned long borrowCoin[3] = { 0, 0, 0 };
unsigned long borrow = 0;
int credit = 10;
int percent[3] = {0 , 0 , 0};
int repay;

int mday = 0;

unsigned long tax = 0;

unsigned long taxStage[] = { 9000000, 30000000, 90000000, 180000000, 400000000 };
float taxRate[] = { 0.10, 0.15, 0.20, 0.25, 0.30, 0.40 };

unsigned long getAsset() {
	return coin + count[0]*price[0] + count[1]*price[1] + count[2]*price[2];
}

void getInput() {

	unsigned long asset = getAsset();
	

	printf("자본:%11ld원\t전재산: %11ld원 신용도: %2d\n", coin, asset, credit);

	
	for ( int i = 0; i < 3; ++i ) {
		printf("%d.%s\t%11lu개\t%11ld원\n", i + 1, name[i], count[i], price[i] );
		if(rand() % 11 <= credit)
		{
			percent[i] = 1;
		} else
		{
			percent[i] = 0;
		}
	}

	if (coin < 0)
	{
		mday++;
	}
	if (coin > 0)
	{
		mday = 0;
	}

	if (mday > 2)
	{
		printf("GAME OVER...\n");
		return;
	}


	printf("--------------day: %03d-------------\n", day);
	printf("1.주식 매입\n");
	printf("2.주식 판매\n");
	printf("3.돈꾸기\n");
	printf("4.돈갚기\n");
	printf("5.잠자기\n");
	printf("6.소송\n");
	printf("7.신용사기(아주 비쌈)\n");
	printf("-----------------------------------\n");

	scanf("%d", &input );

	switch (input) {
		case 1:
			printf("매입 주식을 설정 하여주세용. 개수 설정\n");
			scanf("%d %d", &j, &k );

			if ( k * price[j-1] > coin) {
				printf("프로그램: 주식 한개를 파십시오.\n      안 그러면 쫓겨납니다...\n");
				getInput();
			}

			count[j-1] += k;
			coin -= k * price[j-1];

			getInput();
			break;

		case 2:
			printf("판매 주식을 설정 하여주세용. 개수 설정\n");
			scanf("%d %d", &j, &k );


			if ( k > count[j-1])
			{
				printf("프로그램: 사기 치지마 \n      경찰에 신고한다\n");
				getInput();
			}

			count[j-1] -= k;
			coin += k * price[j-1];

			getInput();
			break;

		case 3:
			printf("빌릴친구를 선택하십시오\n");
			printf("친구1 (전재산:%ld)\n", friendCoin[0]);
			printf("친구2 (전재산:%ld)\n", friendCoin[1]);
			printf("친구3 (전재산:%ld)\n", friendCoin[2]);

			scanf("%d", &l );

			if ( !(l == 1 || l == 2 || l == 3) ) {
				printf("너에겐 더 이상의 친구가 없단다...\n");
				getInput();
			}

			printf("(빌릴돈을 미리정하자)\n");
			scanf("%ld", &borrow );
			if (borrow > friendCoin[l-1]) {
				printf("친구: 잘가 나한텐 너무 큰돈이야)\n");
				getInput();
				break;
			}

			printf("나:돈좀 꿔줘\n친구%d:왜?\n나:파산위기여서 그래\n친구%d:얼마?\n나:%ld원만...", l, l, borrow);

			if (percent[l-1] == 0) {
				printf("미안...                  잘됐다.큭큭\n");          
				getInput();
				break;
			}
			
			printf("알겠어\n");
			coin += borrow;
			friendCoin[l-1] -=	borrow;	

			borrowCoin[l-1] += borrow;

			break;

		case 4:
			printf("갚을 친구를 선택하여 주십시오\n");
			scanf("%d",&l );
			if ( !(l == 1 || l == 2 || l == 3) ) {
				printf("너에겐 더 이상의 친구가 없단다...\n");
				getInput();
			}
			for ( int i = 0; i < 3; ++i ) {
				printf("친구%d (빚:%ld)\n", i + 1 , borrowCoin[i]);
			}
				if (borrowCoin[l-1] == 0)
				{
					printf("server: you don`t have any debt \n");
					printf("server: back to menu\n");
					getInput();
				}
			
			printf("갚을 금액을 설정하여 주십시오\n");
			scanf("%d", &repay );
			if (repay > borrowCoin[l-1] || repay < 0)
			{
				printf("다시 설정하여 주십시오\n");
				getInput();
			}
			borrowCoin[l-1] -= repay;
			friendCoin[l-1] += repay;
			coin -= repay;

			getInput();

			break;

		case 5:

			day++;

			if (borrowCoin[0] > 0|| 
				borrowCoin[1] > 0|| 
				borrowCoin[2] > 0 )
				{
					credit -= 1;
				}

			assetBefore = getAsset();

			for ( int i = 0; i < 3; ++i ) {
				price[i] += rand() % (3 * price[i]) - price[i] + 1;
			}

			assetAfter = getAsset();

			income = assetAfter - assetBefore;


			tax = 0;

			if ( 0 < income && income < taxStage[0] )
			{
				tax = income * taxRate[0];
			} else if ( income < taxStage[1] ) {
				tax = income * taxRate[1];
			} else if ( income < taxStage[1] ) {
				tax = income * taxRate[1];
			} else if ( income < taxStage[2] ) {
				tax = income * taxRate[2];
			} else if ( income < taxStage[3] ) {
				tax = income * taxRate[3];
			} else if ( income < taxStage[4] ) {
				tax = income * taxRate[4];
			} else {
				tax = income * taxRate[5];
			} 

			printf("----------------------------------\n");
			printf("|                                |\n");
			printf("|           ------|              |\n");
			printf("|           |t    |              |\n");
			printf("|           |  ------|           |\n");
			printf("|           |--| a   |           |\n");
			printf("|              |    x|           |\n");     
			printf("|              |------           |\n");
			printf("|          pay a tax             |\n");
			printf("|                                |\n");
			printf("|         tax: %6dwon         |\n", (int)tax);
			printf("|                                |\n");
			printf("|                                |\n");
			printf("|                                |\n");
			printf("----------------------------------\n");

			coin -= (int)tax;
		
			break;
		case 6:
			printf("소송 걸 대상을 선택하여 주십시오 \n");
			scanf("%d",&l );
			if ( !(l == 1 || l == 2 || l == 3) ) {
				printf("너에겐 더 이상의 친구가 없단다...\n");
				getInput();
			}
			coin -= 100000;
			printf("형사: 친구%d... 당신을 괘심죄로 체포한다. \n", l);
			printf("	 당신은 변호사를 선임할 수 있으며\n" );
			printf("	 묵비권을 행사할 수 있으며\n" );
			printf("     본 법정에서 불리하게 적용될 수 있습니다.가시죠 \n" );
			printf("친구%d: 이거 놔 누구야 나 신고한 사람 \n", l );
			printf("형사:보안상의 이유로 공개할 수 없습니다.\n");
			printf("친구%d: 이거 놔 이거 안 놔\n", l);
			printf("	   너 내가 누군지 알아? 나 무죄 받으면 니 부터 감방 간다.\n");
			printf("형사: 소송 사유를 작성하여 주십시오. \n");
			char why[100];
			scanf("%s",why );
			printf("재판관: 오늘 %s(이)라는 이유로 이 재판을 열겠습니다.\n 그러므로 \n", why );
			if (rand() % 2 ==0 )
			 {
			 	printf("피해자는 30만원상당의 돈을 받고 피고인은 벌금 30만원형에 처한다. 땅땅땅 \n" );
			 	coin += 300000;
			 	friendCoin[l-1] -= 300000;
			 	getInput();
			 } 
			 printf("피고인는 30만원상당의 돈을 받고 피해자은 벌금 30만원형에 처한다. 땅땅땅\n" );
			 friendCoin[l-1] += 300000;
			 coin -= 300000;
			 getInput();
			break;
		case 7:
			int credit2;
			printf("불법거래자: 신용을 얼마나 올리고 싶은가?\n");
			scanf("%d",&credit2);
			printf("나: 한%d만큼요...\n", credit2);
			printf("불법거래자: 알겠네 지금 당장 올려주지\n" );
			printf("불법거래자: 어이 친구~~~ ㅇㅇㅇ이 신용 한%d만 올려주게나 두둑히 주겠네\n", credit2);
			printf("친구1: 당장 올려주지 아주 잠깐만 기다리세\n" );
			credit += credit2;
			coin -= credit2 * 100000;
			printf("불법거래자: 다 됐네 이만가 보게나\n");
			printf("경찰: 항복해! 용의자 2명을 현장에서 검거했다.\n" );
			printf("server:결국 경찰서로 끌려가는데...\n" );
			printf("형사:자네는 용의자가 아니더군...\n" );
			printf("형사:그러나 자네를 벌금150000원형을 내리겠네...\n" );
			coin -= 150000;
			printf("형사: 그만 가 보게나\n" );
			printf("	다신 이러지 말고...\n" );
			printf("나: 나쁜...내 아까운 150000원 짜장면40개나 먹을 수 있는데... \n" );
			break;
         default:
			break;
	}


			getInput();

}

int main() {

	printf("이름을 적어 주세용.\n");
	scanf("%s", nickname );

	srand(time(NULL));

	getInput();


	return(0);
}