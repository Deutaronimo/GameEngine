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


    
    int screenPosition_x;
    int screenPosition_y;
    int screenWidth;
    int screenHeight;
    int musicVolume = 128;
    int soundVolume = 128;
    
    Mix_Chunk* testSound = NULL;
    Mix_Music* testMusic = NULL;

    SDL_Surface* demoBackgroundSurface = NULL;
    SDL_Texture* demoBackgroundTexture = NULL;

    SDL_Surface* demoPlayerSurface = NULL;
    SDL_Texture* demoPlayerTexture = NULL;
    

    bool isPolyPhonicSound = true;
    bool isPaused = false;

    public:

    int FPS = 60;

    Uint32 FRAMETIMESTART;

    SDL_Renderer* renderer = NULL;
    SDL_Window*   window   = NULL;
    SDL_Surface*  screenSurface = NULL;

    std::vector<Entity*>entityBatch;
    std::vector<Entity*>destroyBatch;


    GameSystem();
    SDL_Texture* getTexture(std::string _name);
    void instantiate(int _entity);
    void instantiate(Entity* _entity);
    void run();
    void update();
    void render();
    void loadAssets();
    void collision();
    void playSound(std::string _sound);
    void playMusic(std::string _song);
    void demo();
    void pauseMusic();
    void unpauseMusic();
    void stopMusic();
    void quit();
    

};