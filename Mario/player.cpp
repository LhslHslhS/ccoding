#import <GLUT/GLUT.h>
#import <stdlib.h>

#import <math.h>

#import "player.h"
#import "keyboard.h"

Player::Player(float _x, float _y, float _width, float _height, float _s) {
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    s = _s;
    theta = 0;
}

void Player::setX(float _x) {
    x = _x;
}

void Player::setY(float _y) {
    y = _y;
}

void Player::setVX(float _vX) {
    vX = _vX;
}

void Player::setVY(float _vY) {
    vY = _vY;
}

void Player::update(float deltaTime) {
    dT = deltaTime;
}

void Player::draw() {
    glRectf(x, y, x + width, y + height);
}

void Player::logic(int mx, int my) {
    dX = vX * dT;
    dY = vY * dT;
    x += dX;
    y += dY;

    x = 320 + (mx/2.0) * sin(M_PI * y / 240 + theta);
    theta += s * dT;

    s = my / 240.0;

    vY = 0;

    // vX = M_PI * cos(M_PI*x);

    // 320 + 160 * sin(M_PI * i / 240)


    // vY = vY * s;

    // s = rand() % 10 - 5;

    // if(keyState['a']) {
    //     vX = -100;
    // } else if(keyState['d']) {
    //     vX = 100;
    // } else vX = 0;

    // if(keyState['w']) {
    //     vY = 100;
    // } else if(keyState['s']) {
    //     vY = -100;
    // } else vY = 0;
    
}


    // dY -= 100;

    // if(y <= 40) {
    //     inAir = false;
    //     dY = 0;
    //     y = 40;

    //     if(keyState['w']) {
    //         dY = 1000;
    //         inAir = true;
    //     }
    // }