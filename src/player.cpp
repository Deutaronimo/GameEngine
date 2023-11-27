#include<string>
#include<vector>
#include<SDL2/SDL.h>
#include"entity.hpp"
#include"gamesystem.hpp"
#include"player.hpp"

Player::Player()
{

}

void Player::update()
{
    std::cout << "Player" << std::endl;
}

void Player::render(SDL_Renderer* _renderer)
{
    SDL_RenderCopy(_renderer, texture,NULL, &rect);
}

