#ifndef ENTITY_H_
#define ENTITY_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity {
 public:
  Entity(float p_x, float p_y, SDL_Texture* p_tex);
  float GetX();
  float GetY();
  SDL_Texture* GetTexture();
  SDL_Rect GetCurrentFrame();

 private:
  float x, y;
  SDL_Rect current_frame;
  SDL_Texture* tex;
};

#endif  // ENTITY_H_
