#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<SDL2/SDL.h>
#include"entity.hpp"
#include"gamesystem.hpp"

class Player : public Entity
{
    public:
    
    int mousePosition_x;
    int mousePosition_y;

    SDL_RendererFlip flipType = SDL_FLIP_NONE;

    enum Direction {NONE,UP,DOWN,LEFT,RIGHT} direction, previousDirection;

    Player();
    void update() override;
    void render(SDL_Renderer* _renderer) override;
    void getInput();
    
    


};