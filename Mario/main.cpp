#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <GLUT/GLUT.h>

#include "keyboard.h"
#include "player.h"

using namespace std;

float currentTime;
float previousTime;
float deltaTime;

int screenWidth = 640;
int screenHeight = 480;

int lastx, lasty, diffx, diffy;

vector<Player> players;

float clamp(float x, float min, float max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

void processDelta() {
    currentTime = (float)glutGet(GLUT_ELAPSED_TIME) / 1000;
    deltaTime = currentTime - previousTime;
    previousTime = currentTime;

    vector<Player>::iterator it;
    for ( it = players.begin(); it != players.end(); ++it ) {
        it->update(deltaTime);
    }
}

void mouseMovement(int x, int y) {
    diffx = x - lastx;
    diffy = y - lasty;
    lastx = x;
    lasty = y;
}

float randomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float d = b - a;
    return a + random * d;
}

typedef struct Color {
    float r;
    float g;
    float b;
} Color;

Color HSVtoRGB(GLfloat h, GLfloat s, GLfloat v) {
    float c = v * s;
    float x = c * ( 1 - abs((int)(3 * h / M_PI) % 2 - 1) );
    float m = v - c;
    float rp = 0;
    float gp = 0;
    float bp = 0;
    if (h < M_PI / 3) {
        rp = c;
        gp = x;
    } else if (h < 2 * M_PI / 3) {
        rp = x;
        gp = c;
    } else if (h < M_PI) {
        gp = c;
        bp = x;
    } else if (h < 4 * M_PI / 3) {
        gp = x;
        bp = c;
    } else if (h < 5 * M_PI / 3) {
        rp = x;
        bp = c;
    } else {
        rp = c;
        bp = x;
    }
    float r, g, b;
    r = rp + m;
    g = gp + m;
    b = bp + m;
    Color rgb;
    rgb.r = r;
    rgb.g = g;
    rgb.b = b;
    return rgb;
}

bool hitRectCircle(float a, float b, float c, float d, float w, float h, float r) {
    float closestX = clamp(c, a - w / 2, a + w / 2);
    float closestY = clamp(d, b - h / 2, b + h / 2);

    return (closestX - c)*(closestX - c) + (closestY - d)*(closestY - d) <= r*r;
}

void drawCircleFilled(GLfloat x, GLfloat y, GLfloat radius, GLfloat rot) {
    int triangleCount = 5000;

    GLfloat twicePi = 2.0 * M_PI;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for ( int i = 0; i <= triangleCount; ++i ) {
            float angle = i * twicePi / triangleCount + rot;
            Color c = HSVtoRGB(angle-rot, 0.5, 1);
            glColor3f(c.r, c.g, c.b);
            glVertex2f(
                x + (radius * cos(angle)),
                y + (radius * sin(angle))
            );
        }
    glEnd();
}

void render() {
    if(keyState[27]) exit(0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // glRectf(0, 0, screenWidth, 40);

    processDelta();

    vector<Player>::iterator it;
    for ( it = players.begin(); it != players.end(); ++it ) {
        it->logic(lastx, lasty);
        it->draw();
    }

    // glRectf(lastx - 50, lasty - 50, lastx + 50, lasty + 50);
    // glColor3f(1.0, 0.0, 0.0);
    drawCircleFilled(lastx, lasty, 50, 50);

    bool hit = hitRectCircle(250, 250, lastx, lasty, 100, 100, 50);

    if (hit) glColor3f(0.7, 0, 0);
    else glColor3f(0, 7, 0);

    glRectf(200, 200, 300, 300);

    glColor3f(1.0, 1.0, 1.0);

    glutSwapBuffers();
}

int main(int argc, char **argv) {

    for ( int i = 0; i < 100; ++i ) {
        Player *p = new Player( 0, i/2.0, 10, 10, 0.4 );
        players.push_back(*p);
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Mario ");

    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, screenWidth, screenHeight, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);

    glutPassiveMotionFunc(mouseMovement);

    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyReleased);
    glutDisplayFunc(render);
    glutIdleFunc(render);

    glutMainLoop();

}