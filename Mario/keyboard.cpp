#include "keyboard.h"

bool keyState[256];

void keyPressed (unsigned char key, int x, int y) {
    keyState[key] = true;
}

void keyReleased (unsigned char key, int x, int y) {
	keyState[key] = false;
}