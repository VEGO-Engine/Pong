#ifndef BALL_H
#define BALL_H

#include <SDL.h>

#include "Player.h"

class Ball
{
private:
    SDL_Rect rect;

    int velocityX;
    int velocityY;

    Player* player1;
    Player* player2;

public:
    Ball(int xPos, int yPos, int size, Player* player1, Player* player2);
    ~Ball();

    void init();
    void update();
    void draw(SDL_Renderer* renderer);
};

#endif
