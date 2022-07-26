#include "render_window.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    : window(nullptr), renderer(nullptr) {
  window =
      SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

  if (window == nullptr) {
    SDL_Log("Window failed to init. Error: %s", SDL_GetError());
  }

  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* RenderWindow::LoadTexture(const char* p_filePath) {
  SDL_Texture* texture = nullptr;
  texture = IMG_LoadTexture(renderer, p_filePath);

  if (texture == nullptr)
    SDL_Log("Failed to load texture. Error: %s", SDL_GetError());

  return texture;
}

int RenderWindow::GetRefreshRate() {
  int display_index = SDL_GetWindowDisplayIndex(window);

  SDL_DisplayMode mode;
  SDL_GetDisplayMode(display_index, 0, &mode);
  return mode.refresh_rate;
}

void RenderWindow::Clear() { SDL_RenderClear(renderer); }

void RenderWindow::Render(Entity& p_entity) {
  SDL_Rect src;
  src.x = p_entity.GetCurrentFrame().x;
  src.y = p_entity.GetCurrentFrame().y;
  src.w = p_entity.GetCurrentFrame().w;
  src.h = p_entity.GetCurrentFrame().h;

  SDL_Rect dst;
  dst.x = p_entity.GetX() * scaler;
  dst.y = p_entity.GetY() * scaler;
  dst.w = p_entity.GetCurrentFrame().w * scaler;
  dst.h = p_entity.GetCurrentFrame().h * scaler;

  SDL_RenderCopy(renderer, p_entity.GetTexture(), &src, &dst);
}

void RenderWindow::Render() {}

void RenderWindow::Display() { SDL_RenderPresent(renderer); }

void RenderWindow::CleanUp() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}
