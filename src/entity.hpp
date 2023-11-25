#pragma once
#include<iostream>
#include<string>
#include<SDL2/SDL.h>

class Entity
{
    private:

    SDL_Rect rect;
    SDL_Rect lastRect;
    SDL_Texture* texture = NULL;
    int id = 0;
    bool isDestroyed    = false;
    bool isUnderPlayerControl = false;
    std::string tag = "none";

    public:
    


    Entity();
    virtual void update();
    virtual void render(SDL_Renderer* _renderer);
    std::string getTag();
    void setTag(std::string _tag);
    void setPLayerControlled();
    void setRect(float _x, float _y, float _h, float _w);
    SDL_Rect getRect();
    SDL_Rect getLastRect();
    SDL_Texture* getTexture();

};