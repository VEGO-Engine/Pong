#include <iostream>

#include "Game.h"

int main(int argc, char* argv[])
{
    Game* game = new Game();
    game->gameloop();

    delete game;

    return 0;
}