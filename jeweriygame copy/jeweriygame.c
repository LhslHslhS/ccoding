#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playerCoin[2] = {30000, 30000};


int bosuk[9][6] = {{1000, 1000, 50, 10, 0, 0},
				   {5000, 5000, 50, 10, 0, 0},
				   {10000, 10000, 50, 10, 0, 0},
				   {50000, 50000, 50, 10, 0, 0},
				   {70000, 70000, 50, 10, 0, 0},
				   {100000, 100000, 50, 10, 0, 0},
				   {300000, 300000, 50, 10, 0, 0},
				   {500000, 500000, 50, 10, 0, 0},
				   {1000000, 1000000, 50, 10, 0, 0}};
int turn = 0;
int currentTime = 0;

int maximum[9] = {1000, 5000, 10000, 50000, 70000, 100000, 300000, 500000, 1000000}; 

int minimum[9] = {1000, 5000, 10000, 50000, 70000, 100000, 300000, 500000, 1000000};

int record[9][1000];

int nowtime = 0;


void drawGraph(int graph);



void getInput(){
	
	int input;
	int input2;
	int input3;

	if (turn == 0)
	{
		printf("턴: playerH\n");
	}else if (turn == 1)
	{
		printf("턴: playerC\n");
	}
	printf("H: %d\n", playerCoin[0]);
	printf("C: %d\n", playerCoin[1]);
	printf("--------------------------------------------------\n");
	printf("1.은           %8d원     H: %3d개  C: %3d개\n", bosuk[0][0], bosuk[0][4], bosuk[0][5] ); 
	printf("2.금           %8d원     H: %3d개  C: %3d개\n", bosuk[1][0], bosuk[1][4], bosuk[1][5] );
	printf("3.에메랄드     %8d원     H: %3d개  C: %3d개\n", bosuk[2][0], bosuk[2][4], bosuk[2][5] );
	printf("4.사파이어     %8d원     H: %3d개  C: %3d개\n", bosuk[3][0], bosuk[3][4], bosuk[3][5] );
	printf("5.루비         %8d원     H: %3d개  C: %3d개\n", bosuk[4][0], bosuk[4][4], bosuk[4][5] );
	printf("6.토파즈       %8d원     H: %3d개  C: %3d개\n", bosuk[5][0], bosuk[5][4], bosuk[5][5] );
	printf("7.수정         %8d원     H: %3d개  C: %3d개\n", bosuk[6][0], bosuk[6][4], bosuk[6][5] );
	printf("8.타파이트     %8d원     H: %3d개  C: %3d개\n", bosuk[7][0], bosuk[7][4], bosuk[7][5] );
	printf("9.다이아몬드   %8d원     H: %3d개  C: %3d개\n", bosuk[8][0], bosuk[8][4], bosuk[8][5] );
	printf("--------------------------------------------------\n");
	printf("1. 사기\n");
	printf("2. 팔기\n");
	printf("3. 잠자기\n");
	printf("4. 그래프 보기\n");
	printf("--------------------------------------------------\n");
	scanf("%d", &input);

	if (input == 1)
	{
		printf("살 주식을 정해주십시오.\n");
		scanf("%d", &input2);
		printf("살 개수를 정해주십시오.\n");
		scanf("%d", &input3);
		if (playerCoin[turn] < bosuk[input2 - 1][0] * input3)
		{
			printf("돈이 부족합니다.\n");
			getInput();
			return;
		}
		playerCoin[turn] -= bosuk[input2 - 1][0] * input3;
		bosuk[input2 - 1][turn + 4] += input3;
	}else if (input == 2)
	{
		printf("팔 주식을 정해주십시오.\n");
		scanf("%d", &input2);
		printf("팔 개수를 정해주십시오.\n");
		scanf("%d", &input3);
		if (bosuk[input2 - 1][turn + 4] < input3)
		{
			printf("주식이 부족합니다.\n");
			getInput();
			return;
		}
		playerCoin[turn] += bosuk[input2 - 1][0] * input3;
		bosuk[input2 - 1][turn + 4] -= input3;
	}else if (input == 4)
	{
		int graph;
		printf("보석을 정해주십시오.\n");
		printf("--------------------------------------------------\n");
		printf("1.은\n");
		printf("2.금\n");
		printf("3.에메랄드\n");
		printf("4.사파이어\n");
		printf("5.루비\n");
		printf("6.토파즈\n");
		printf("7.수정\n");
		printf("8.타파이트\n");
		printf("9.다이아몬드\n");
		printf("--------------------------------------------------\n");
		scanf("%d", &graph);
		drawGraph(graph);

	}else if (input != 1 || input != 2 || input != 9)
	{
		currentTime++;
		if (currentTime == 2)
		{
			currentTime = 0;
			for ( int i = 0; i < 9; ++i ) {
				bosuk[i][0] += rand() % bosuk[i][1] - (bosuk[i][1] / 2);
				if (bosuk[i][0] <= 500)
				{
					bosuk[i][0] = (bosuk[i][1] / 2) + (rand() % (bosuk[i][1] / 2));
				}
			}
		}
		for ( int i = 0; i < 9; ++i ) {
			if (maximum[i] < bosuk[i][0])
			{
				maximum[i] = bosuk[i][0];
			}
			if (minimum[i] > bosuk[i][0])
			{
				minimum[i] = bosuk[i][0];
			}
			record[i][nowtime] = bosuk[i][0];
		}
		turn = 1 - turn;
		if (turn % 2 == 1)
		{
			nowtime++;
		}
		getInput();
	}
	


	
	if (input == 9)
	{
		printf("게임이 종료되었습니다.\n");
		return;
	}
	getInput();

		return;
}

void drawGraph(int graph){
	// char grid[20][1000];
	char *grid[20];

	for ( int i = 0; i < 20; ++i ) {
		grid[i] = (char *) malloc(nowtime * sizeof(char));
	}
	int x,y;
	
	float maxhite =  maximum[graph - 1]  ;
	printf("------------------------------------------------------------------------------\n");
	printf("최댓값:%10d\n", maximum[graph - 1]);
	printf("최솟값:%10d\n", minimum[graph - 1]);
	for ( int i = 0; i < 20; ++i ) {
		for ( int j = 0; j < nowtime; ++j ) {
			x = record[graph - 1][j];
			y = (19 * x - 19 * minimum[graph - 1]) / (maximum[graph - 1] - minimum[graph - 1]);
			if ( y == i)
			{
				grid[i][j] = '*';
			}else{
				grid[i][j] = ' ';
			}
		}
	}
	for ( int i = 0; i < 20; ++i ) {
		printf("%7d : ", (maximum[graph - 1] - minimum[graph - 1]) * (19 - i) / 19 + minimum[graph - 1] );
		for ( int j = 0; j < nowtime; ++j ) {
			printf("%c",grid[19 - i][j] );
			if (j == nowtime - 1)
			{
				printf("\n");
			}
		}
	}
	/*for ( int i = 0; i < nowtime; ++i ) {
		printf("%d\n",record[0][i] );
	}*/
	printf("------------------------------------------------------------------------------\n");
	return;
}


int main () {

	srand(time(NULL));
	getInput();
	return 0;

}