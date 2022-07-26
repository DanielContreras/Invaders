#include "entity.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex)
    : x(p_x), y(p_y), tex(p_tex) {
  current_frame.x = 0;
  current_frame.y = 0;
  current_frame.w = 32;
  current_frame.h = 32;
}

float Entity::GetX() { return x; }

float Entity::GetY() { return y; }

SDL_Texture* Entity::GetTexture() { return tex; }

SDL_Rect Entity::GetCurrentFrame() { return current_frame; }
