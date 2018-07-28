#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define R 15
#define C 43

typedef struct {
	int x;
	int y;
	char name;
	int coin;
	int EffectFirst;
	int EffectSecond;
	int
} Player;

int GAME = 1;

void getInput();
void process();



void setup () {

}

void draw () {

}

void getInfo () {

}  



void getInput () {

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