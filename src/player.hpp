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

    Player();
    void update() override;
    void render(SDL_Renderer* _renderer) override;
    
    


};