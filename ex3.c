#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main () {
    //변수
	int h = 0;
	int P, C;
	int coin = 1000000;
    int bet = 0;
    char name[100];
    int highscore = coin;

    printf("이름을 적으십시오: ");

	gets(name);


	// 루프 생성
	while(h == 0)
	{
		srand(time(NULL));

		char z[100];

		printf("주식을 설정하여 주십시오 ex)00주식, ㅁㅁ주식, **주식\n");

		gets(z);


       //내 주식 설정
		if ( strcmp(z, "00주식") == 0 ) {
			P = 0;
		} else if ( strcmp(z, "ㅁㅁ주식") == 0 ) {
			P = 1;
		} else if ( strcmp(z, "**주식") == 0 ) {
			P = 2;
		} else {
			printf("베팅할 주식를 다시 설정하십시오 \n");
			continue;
		}
        //베팅금액 설정
		printf("%s: 베팅금액을 써 주십시오\n", z);
		printf(" 전재산: %d원 입니다.\n", coin);

		scanf("%d", &bet);
		if (bet > coin)
		{
			printf("@@!$#^$ㅆ#&$^&$\n" );
            printf("주식 재설정 바람 $^&#$$#&$*^&&^###@#*&*^#@$^&*^#\n");
        	continue;
        }
        //컴퓨터 주식설정
		C = rand() % 3;

		if (C == 0) {
			printf("컴퓨터:00주식\n");
		}
		if (C == 1) {
			printf("컴퓨터:ㅁㅁ주식\n");
		}
		if (C == 2) {
			printf("컴퓨터:**주식\n");
		}


  		//베팅승패 & 돈계산
		if ( P == C ) {
			printf("피해없음\n 전재산:%d",coin);
		} else if ( (P - C + 3) % 3 == 1) {
			coin = coin + bet;
			printf("%s이 사업에 성공하여 이익을 보셨습니다.\n 전재산:%d ", z, coin);
		} else if ( (P - C + 3) % 3 == 2) {
			coin = coin - bet;
			printf("%s이 사업에 실패하여 피해를 보셨습니다.\n 전재산:%d ", z, coin);
		}
		if (coin > highscore) {
			highscore = coin;
		}

		printf("최고기록: %d\n", highscore );

		//게임 이김 / 짐 판단하기

		if(coin <= 0) {
			printf("%s이(가)베팅에 실패하여 파산하셨습니다.\n GAME OVER...",name);
			break;
		}
		if (coin > 10000000)
		{
			printf("%s이(가) 베팅에 성공하여 천만장자가 되었습니다... 인생 끝!\n",name );
			break;
		}

	}

	return 0;

}
