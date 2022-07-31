#include "sdlwrap/texture.h"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>

#include "log.h"
#include "sdlwrap/renderer.h"
#include "sdlwrap/surface.h"

namespace SDLWrap {

Texture::Texture(Renderer& renderer, const std::string& path) {
  texture_ = IMG_LoadTexture(renderer.GetRenderer(), path.c_str());
  if (texture_ == nullptr) {
    CORE_CRITICAL("Failed to load texture. Error: {1}", path.c_str(), IMG_GetError());
    // TODO: Should throw an exception here and not allow application to continue running
    return;
  }
  CORE_DEBUG("Texture successfully initialized");
}

Texture::Texture(Renderer& renderer, const Surface& surface) {
  texture_ = SDL_CreateTextureFromSurface(renderer.GetRenderer(), surface.GetSurface());
  if (texture_ == nullptr) {
    CORE_CRITICAL("Failed to load texture. Error: {}", SDL_GetError());
    // TODO: Should throw an exception here and not allow application to continue running
    return;
  }
  CORE_DEBUG("Texture successfully initialized");
}

Texture::~Texture() {
  if (texture_ != nullptr) SDL_DestroyTexture(texture_);
  CORE_DEBUG("Texture successfully destroyed");
}

SDL_Texture* Texture::GetTexture() const { return texture_; }

int Texture::GetWidth() const {
  int width;
  if (SDL_QueryTexture(texture_, nullptr, nullptr, &width, nullptr) != 0) {
    CORE_ERROR("Failed to get width of texture");
  }
  return width;
}

int Texture::GetHeight() const {
  int height;
  if (SDL_QueryTexture(texture_, nullptr, nullptr, nullptr, &height) != 0) {
    CORE_ERROR("Failed to get height of texture");
  }
  return height;
}

}  // namespace SDLWrap
