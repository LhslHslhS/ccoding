#ifndef KEYBOARD_H
#define KEYBOARD_H

extern bool keyState[256];

void keyPressed (unsigned char key, int x, int y);
void keyReleased (unsigned char key, int x, int y);

#endif