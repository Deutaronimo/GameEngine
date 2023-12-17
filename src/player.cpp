#include<string>
#include<vector>
#include<SDL2/SDL.h>
#include"entity.hpp"
#include"gamesystem.hpp"
#include"player.hpp"

Player::Player()
{
    speed_x = 5;
    speed_y = 5;
    
    Direction direction;
     
}

void Player::update()
{
    getInput();    

}


void Player::getInput()
{

    
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            SDL_Quit();
        }

        else if (event.type == SDL_KEYDOWN)
        {
            
            switch (event.key.keysym.sym)
            {
                case SDLK_UP:
                    std::cout << "up\n";
                    direction = UP;
                    rect.y -= speed_y;
                    
                    break;

                case SDLK_DOWN:                   
                    std::cout << "down\n";
                    direction = DOWN;
                    rect.y += speed_y;
                    break;

                case SDLK_LEFT:  
                    std::cout << "LEFT\n";
                    direction = LEFT;
                    
                    rect.x -= speed_x;
                    break;

                case SDLK_RIGHT:
                    std::cout << "right\n";
                    direction = RIGHT;
                    rect.x += speed_x;
                    break;

                case SDLK_SPACE:                    
                    std::cout << "Space bar!!\n";
                    break;

                case SDLK_w:
                    std::cout << "w\n";
                    break;

                case SDLK_s:
                    std::cout << "s\n";
                    break;

                case SDLK_a:
                    std::cout << "a\n";
                    break;

                case SDLK_d:
                    std::cout << "d\n";
                    break;

                case SDLK_m:
                    //cout << "m\n";
                    break;

                case SDLK_F1:
                    break;

                case SDLK_ESCAPE:
                    std::cout << "Quit.\n";
                    SDL_Quit();
                    break;

                default:
                    direction = NONE;


                }

            }

        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
                
            SDL_GetMouseState(&mousePosition_x, &mousePosition_y);
            std::cout << "Mouse Click: X:" << mousePosition_x << " Y:" << mousePosition_y << std::endl;
                

        }


        
    }
    previousDirection = direction;
}

void Player::render(SDL_Renderer* _renderer)
{
    SDL_RenderCopy(_renderer, texture,NULL, &rect);
}

