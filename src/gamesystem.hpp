#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include"entity.hpp"


class GameSystem
{
    private:

    std::vector<Entity*>entityBatch;
    std::vector<Entity*>destroyBatch;
    
    int screenPosition_x;
    int screenPosition_y;
    int screenWidth;
    int screenHeight;

    public:

    SDL_Renderer* renderer = NULL;
    SDL_Window*   window   = NULL;
    SDL_Surface*  screenSurface = NULL;

    GameSystem();
    SDL_Texture* getTexture(int _name);
    void instantiate(int _entity);
    void run();
    void update();
    void render();
    void loadAssets();
    void collision();
    

};