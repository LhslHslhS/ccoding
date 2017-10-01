#ifndef PLAYER_H
#define PLAYER_H

class Player {
    public:
        Player(float, float, float, float, float);

        void setX(float);
        void setY(float);
        void setVX(float);
        void setVY(float);

        void update(float);
        void draw();
        void logic(int, int);
        
    private:
        float x, y, dX, dY, vX, vY;
        float dT;
        float width, height;
        float s;
        float theta;
        // bool inAir;
};

#endif