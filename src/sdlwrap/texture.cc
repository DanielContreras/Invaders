#include "sdlwrap/texture.h"

#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#include "log.h"
#include "sdlwrap/font.h"
#include "sdlwrap/renderer.h"
#include "sdlwrap/surface.h"

namespace SDLWrap {

Texture::Texture() { texture_ = nullptr; }

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

Texture& Texture::LoadFromFile(Renderer& renderer, const std::string& path) {
  texture_ = IMG_LoadTexture(renderer.GetRenderer(), path.c_str());
  if (texture_ == nullptr) {
    CORE_CRITICAL("Failed to load texture. Error: {1}", path.c_str(), IMG_GetError());
    // TODO: Should throw an exception here and not allow application to continue running
  }
  CORE_DEBUG("Texture successfully initialized");
  return *this;
}

Texture& Texture::CreateFromSurface(Renderer& renderer, const Surface& surface) {
  texture_ = SDL_CreateTextureFromSurface(renderer.GetRenderer(), surface.GetSurface());
  if (texture_ == nullptr) {
    CORE_CRITICAL("Failed to load texture. Error: {}", SDL_GetError());
    // TODO: Should throw an exception here and not allow application to continue running
  }
  CORE_DEBUG("Texture successfully initialized");
  return *this;
}

// Texture& Texture::UpdateText(Renderer& renderer, Font& font, const char* text, SDL_Color& color)
// {
Texture& Texture::UpdateText(Renderer& renderer, Font& font, std::string text, SDL_Color& color) {
  SDL_DestroyTexture(texture_);
  Surface surface(TTF_RenderText_Solid(font.GetFont(), text.c_str(), color));
  texture_ = SDL_CreateTextureFromSurface(renderer.GetRenderer(), surface.GetSurface());
  return *this;
}

void Texture::Destroy() {
  SDL_DestroyTexture(texture_);
  CORE_DEBUG("Texture Destroyed!");
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
