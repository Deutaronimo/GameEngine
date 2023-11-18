#include<iostream>
#include<string>
#include<vector>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mixer.h>
#include"gamesystem.hpp"

GameSystem::GameSystem()
{
    screenPosition_x = 100;
    screenPosition_y = 100;
    screenWidth      = 640;
    screenHeight     = 480;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Title", screenPosition_x, screenPosition_y, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 100, 149, 237, 0xff);
    screenSurface = SDL_GetWindowSurface(window);

}

SDL_Texture* GameSystem::getTexture(int _name)
{
    return NULL;
}

void GameSystem::instantiate(int _entity)
{

}

void GameSystem::update()
{
    // update entity batch
}

void GameSystem::loadAssets()
{

}

void GameSystem::collision()
{
    // resolve collisions.
}

void GameSystem::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void GameSystem::run()
{
    // This is the main function.
    update();
    collision();
    render();
}
