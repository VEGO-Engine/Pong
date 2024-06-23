#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

enum Type 
{
    PLAYER_1,
    PLAYER_2
};

enum Direction
{
    UP,
    DOWN,
    NONE
};

class Player
{
    private:
        SDL_Rect rect;
        Type type;
        Direction direction;
        const uint8_t* keystates;

    public:
        Player(Type type, int xPos, int yPos, int width, int height);
        ~Player();

        void draw(SDL_Renderer* renderer);
        void update();
        void move(const SDL_Event& event);

        int getX() { return rect.x; }
        int getY() { return rect.y; }
        int getW() { return rect.w; }
        int getH() { return rect.h; }
};

#endif
