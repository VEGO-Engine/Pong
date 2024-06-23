#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <iostream>

#include "Player.h"
#include "Ball.h"

#define FPS 60

class Game
{
    public:
        Game();
        ~Game();

        void gameloop();
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void update();
        void draw();

    private:
        bool playing;

        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event event;

        const int frameDelay = 1000 / FPS;
	    Uint32 frameStart;
	    int frameTime;

        Player* player1;
        Player* player2;
        Ball* ball;
};

#endif