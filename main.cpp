#include<iostream>
#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include"src/entity.hpp"
#include"src/gamesystem.hpp"
#include"src/player.hpp"

using namespace std;


int main()
{

   GameSystem gameSystem;
   
   while(true)
   {
      gameSystem.run();
      
   }

   cout << "All ok ..." << endl;
   return 0;
}
