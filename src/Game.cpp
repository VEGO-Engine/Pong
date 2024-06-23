#include "Game.h"

#define WINDOW_HEIGHT   450
#define WINDOW_WIDTH    800

#define PADDLE_WIDTH    20
#define PADDLE_HEIGHT   100

#define BALL_SIZE 20

Game::Game()
{
    playing = true;
}

Game::~Game()
{

}

void Game::gameloop()
{
    init("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

    player1 = new Player(Type::PLAYER_1, 
                            PADDLE_WIDTH,                               // xpos
                            (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2),  // ypos
                            PADDLE_WIDTH,                               // width
                            PADDLE_HEIGHT);                             // height
    player2 = new Player(Type::PLAYER_2, 
                            WINDOW_WIDTH - (2 * PADDLE_WIDTH),          // xpos
                            (WINDOW_HEIGHT / 2) - (PADDLE_HEIGHT / 2),  // ypos
                            PADDLE_WIDTH,                               // width
                            PADDLE_HEIGHT);                             // height

    ball = new Ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, BALL_SIZE, player1, player2);
    ball->init();

    while(playing)
    {
        frameStart = SDL_GetTicks();

        SDL_PollEvent(&event);

        if(event.type == SDL_QUIT)
            break;

        player1->move(event);
        player2->move(event);

        update();
        draw();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "ERROR. Subsystem couldnt be initialized! " << SDL_GetError() << std::endl;
        SDL_ClearError();
        return;
    }

    std::cout << "SDL_Init finished" << std::endl;

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (!window)
    {
        std::cout << "ERROR: Window couldnt be created! " << SDL_GetError() << std::endl;
        SDL_ClearError();
        return;
    }

    std::cout << "SDL_CreateWindow finished" << std::endl;

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
    {
        std::cout << "ERROR: Renderer couldnt be created! " << SDL_GetError() << std::endl;
        SDL_ClearError();
        return;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    std::cout << "SDL_CreateRenderer finished" << std::endl;
}

void Game::update()
{
    player1->update();
    player2->update();
    ball->update();
}

void Game::draw()
{
    SDL_RenderClear(renderer);

    player1->draw(renderer);
    player2->draw(renderer);
    ball->draw(renderer);

    SDL_RenderPresent(renderer);

    //std::cout << "drawing" << std::endl;
}