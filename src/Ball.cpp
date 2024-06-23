#include "Ball.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define VELOCITY    5

Ball::Ball(int xPos, int yPos, int size, Player* player1, Player* player2)
{
    rect.x = xPos;
    rect.y = yPos;
    rect.h = rect.w = size;

    this->player1 = player1;
    this->player2 = player2;
}

Ball::~Ball()
{

}

void Ball::init()
{
    srand(time(NULL));

    int random = rand() % 2;

    switch(random)
    {
        case 0:
            velocityX = -VELOCITY;
            break;

        case 1:
            velocityX = VELOCITY;
            break;
    }

    velocityY = VELOCITY;
}

void Ball::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Ball::update()
{
    int nextX = rect.x + velocityX;
    int nextY = rect.y + velocityY;

    if (nextY <= 0 || nextY >= (450 - rect.h))
    {
        velocityY = -velocityY;
    }

    if (nextX <= (player1->getX() + player1->getW()) && nextY >= player1->getY() && nextY < (player1->getY() + player1->getH()))
    {
        velocityX = -velocityX;
        velocityY = -velocityY;
    }

    if (nextX >= (player2->getX() - player2->getW()) && nextY >= player2->getY() && nextY < (player2->getY() + player2->getH()))
    {
        velocityX = -velocityX;
        velocityY = -velocityY;
    }

    rect.x = nextX;
    rect.y = nextY;

    // std::cout << "X: " << rect.x << " Y: " << rect.y << std::endl;
}
