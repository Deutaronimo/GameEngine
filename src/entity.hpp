#pragma once
#include<iostream>
#include<string>
#include<SDL2/SDL.h>

class Entity
{
    public:
    
    SDL_Event event;
    SDL_Texture* texture = NULL;
    int id = 0;
    bool isDestroyed    = false;
    bool isUnderPlayerControl = false;
    std::string tag = "none";

    float speed_x ;
    float speed_y ;

    SDL_Rect rect;
    SDL_Rect lastRect;
    


    Entity();
    virtual void update();
    virtual void render(SDL_Renderer* _renderer);
    std::string getTag();
    void setTexture(SDL_Texture* _texture);
    void setTag(std::string _tag);
    void setPLayerControlled();
    void setRect(float _x, float _y, float _h, float _w);
    SDL_Rect getRect();
    SDL_Rect getLastRect();
    SDL_Texture* getTexture();

};