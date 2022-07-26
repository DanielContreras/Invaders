#ifndef RENDER_WINDOW_H_
#define RENDER_WINDOW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.h"

class RenderWindow {
 public:
  RenderWindow(const char* p_title, int p_w, int p_h);
  SDL_Texture* LoadTexture(const char* p_filePath);
  int GetRefreshRate();
  void CleanUp();
  void Clear();
  void Render(Entity& p_entity);
  void Render();
  void Display();

 private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  const int scaler = 4;
};

#endif  // RENDER_WINDOW_H_
