#include "Player.h"

Player::Player(Type type, int xPos, int yPos, int width, int height)
{
    rect.x = xPos;
    rect.y = yPos;
    rect.w = width;
    rect.h = height;

    this->type = type;
}

Player::~Player()
{
}

void Player::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Player::update()
{
    if(direction == Direction::UP && this->rect.y >= 0)
    {
        this->rect.y = this->rect.y - 5;
    }

    if(direction == Direction::DOWN && this->rect.y < (450 - rect.h))
    {
        this->rect.y = this->rect.y + 5;
    }
}

void Player::move(const SDL_Event& event)
{
    keystates = SDL_GetKeyboardState(NULL);

    switch(event.type)
    {
        case SDL_KEYDOWN:
            if((keystates[SDL_SCANCODE_W] && type == Type::PLAYER_1) || (keystates[SDL_SCANCODE_UP] && type == Type::PLAYER_2))
            {
                direction = Direction::UP;
            }

            if((keystates[SDL_SCANCODE_S] && type == Type::PLAYER_1) || (keystates[SDL_SCANCODE_DOWN] && type == Type::PLAYER_2))
            {
                direction = Direction::DOWN;
            }

            break;

        case SDL_KEYUP:
            direction = Direction::NONE;
            break;
    }
}