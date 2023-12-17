#include<iostream>
#include<string>
#include<vector>
#include<time.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mixer.h>
#include"gamesystem.hpp"
#include"player.hpp"


GameSystem::GameSystem()
{
    screenPosition_x = 0;
    screenPosition_y = 0;
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
    SDL_Surface* demoBackgroundSurface = NULL;
    SDL_Texture* demoBackgroundTexture = NULL;
    
    // Randomize the randomness.
    srand(time(NULL));

    loadAssets();

}

// Gets the requested texture if its loaded. 
SDL_Texture* GameSystem::getTexture(std::string _name)
{
    if (_name == "demobackground") { return demoBackgroundTexture;}

    if (_name == "demoplayer") { return demoPlayerTexture;}

    if (_name == "skull") { return skullTexture;}
    
    // if there is no texture match, return a default texture.
    return defaultTexture;
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

    // Load all art. Create texture then free surface for each.
    demoBackgroundSurface = IMG_Load("assets/grafx/background.png");
    demoBackgroundTexture = SDL_CreateTextureFromSurface(renderer, demoBackgroundSurface);
    SDL_FreeSurface(demoBackgroundSurface);

    demoPlayerSurface = IMG_Load("assets/grafx/test2.png");
    demoPlayerTexture = SDL_CreateTextureFromSurface(renderer, demoPlayerSurface);
    SDL_FreeSurface(demoPlayerSurface);

    defaultSurface = IMG_Load("assets/grafx/default.png");
    defaultTexture = SDL_CreateTextureFromSurface(renderer, defaultSurface);
    SDL_FreeSurface(defaultSurface);

    skullSurface = IMG_Load("assets/grafx/skull.png");
    skullTexture = SDL_CreateTextureFromSurface(renderer, skullSurface);
    SDL_FreeSurface(skullSurface);    

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

    // Render the entity batch
    if (!entityBatch.empty())
    {
        for(Entity* entity : entityBatch)
        {
            entity->render(renderer);
        }
    }

    SDL_RenderPresent(renderer);
    
}

// Main game loop.
void GameSystem::run()
{
    FRAMETIMESTART = SDL_GetTicks();

    update();
    collision();
    render();

    // FPS Check and maintainer.
    if (1000 / FPS > SDL_GetTicks() - FRAMETIMESTART)
    {
        SDL_Delay(1000 / FPS - (SDL_GetTicks() - FRAMETIMESTART));
    }
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
    background->setRect(0, 0, screenHeight, screenWidth);
    background->setTexture(getTexture("demobackground"));
    entityBatch.push_back(background);
    
    // Create a player entity.
    Player* player = new Player;
    player->setTag("player");
    player->setRect(320,364,64,64);
    player->setPLayerControlled();
    player->setTexture(getTexture("demoPlayer"));
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


void GameSystem::quit()
{
    //sound
    Mix_FreeChunk(testSound);
    Mix_FreeMusic(testMusic);

}
