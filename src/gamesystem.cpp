#include<iostream>
#include<string>
#include<vector>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mixer.h>
#include"gamesystem.hpp"
#include"player.hpp"


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

    //Initialize SDL_mixer
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) ;

    // Load grafx, sound and music assets.    
    loadAssets();

}

// Gets the requested texture if its loaded. 
SDL_Texture* GameSystem::getTexture(int _name)
{
    return NULL;
}

// Creates and adds a new entity to the render batch.
void GameSystem::instantiate(int _entity)
{

}

// Adds an allready created entity to update batch.
void GameSystem::instantiate(Entity* _entity)
{
    entityBatch.push_back(_entity);
}

// Updates all the entities in the entityBatch.
void GameSystem::update()
{
    // update entity batch
    if (!entityBatch.empty() )
    {
        for(Entity* entity : entityBatch)
        {
            entity->update();
        }
    }
  
}

// Loads all sound, grafx and data for the game.
void GameSystem::loadAssets()
{
    //Load all music files.
    testMusic = Mix_LoadMUS( "assets/sound/testMusic.ogg" );
    if (testMusic == NULL)
    {
        std::cout << "Failed tp load music file." << std::endl;
    }

    //Load all sound FX.
    testSound = Mix_LoadWAV( "assets/sound/testSound.wav" );
    if (testSound == NULL)
    {
        std::cout << "Failed tp load sound file." << std::endl;
    }

    // Load all textures.


}

void GameSystem::collision()
{
    // resolve collisions.
    //std::cout << "Collisions" << std::endl;
}

// Renders all entities in the entityBatch.
void GameSystem::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    // Render the entity batch
    if (!entityBatch.empty())
    {
        for(Entity* entity : entityBatch)
        {
            entity->render(renderer);
        }
    }
    
}

// Main game loop.
void GameSystem::run()
{
    update();
    collision();
    render();
}

void GameSystem::playSound(std::string _sound)
{
    if (_sound == "test"){Mix_PlayChannel(-1, testSound, 0);}

    
}

void GameSystem::playMusic(std::string _song)
{
    if(_song == "test"){Mix_PlayMusic(testMusic, -1);}
}

// Demo the functionality of engine in 1 command.
void GameSystem::demo()
{
    // Create a background picture.
    Entity* background = new Entity;
    background->setTag("background");
    background->setRect(0, 0, screenWidth, screenHeight);
    entityBatch.push_back(background);
    
    // Create a player entity.
    Player* player = new Player;
    player->setTag("player");
    player->setPLayerControlled();
    entityBatch.push_back(player);

    
    
    
}

void GameSystem::pauseMusic()
{
    // Pause currently playing song.
    Mix_PauseMusic();
}

void GameSystem::unpauseMusic()
{
    // Resume play of paused song.
    Mix_ResumeMusic();
}

void GameSystem::stopMusic()
{
    // Stop currently playing music;
    Mix_HaltMusic();
}

//
void GameSystem::quit()
{
    //sound
    Mix_FreeChunk(testSound);
    Mix_FreeMusic(testMusic);

}
