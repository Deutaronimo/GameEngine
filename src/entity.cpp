 #include<iostream>
 #include<string>
 #include<SDL2/SDL.h>
 #include"entity.hpp"

   
   Entity::Entity()
   {
    
   }

   void Entity::update()
   {
      
   }

   void Entity::render(SDL_Renderer* _renderer)
   {
      //
   }

   std::string Entity::getTag()
   {
      return tag;
   }

   void Entity::setTag(std::string _tag)
   {
      //
   }

   SDL_Rect Entity::getRect()
   {
      return rect;
   }

   SDL_Rect Entity::getLastRect()
   {
      return lastRect;
   }

   SDL_Texture* getTexture()
   {
      return NULL;
   }

   void Entity::setPLayerControlled()
   {
      isUnderPlayerControl = true;
   }

   void Entity::setRect(float _x, float _y, float _h, float _w)
   {
      rect.x = _x;
      rect.y = _y;
      rect.h = _h;
      rect.w = _w;
   }