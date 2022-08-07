#include "sdlwrap/texture.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL_image.h>
#elif __linux__
#include <SDL2/SDL_image.h>
#endif

#include "log.h"
#include "sdlwrap/font.h"
#include "sdlwrap/renderer.h"
#include "sdlwrap/surface.h"

namespace SDLWrap {

Texture::Texture() { texture_ = nullptr; }

Texture::Texture(Renderer& renderer, const std::string& path) {
  texture_ = IMG_LoadTexture(renderer.get_renderer(), path.c_str());
  if (texture_ == nullptr) {
    CORE_CRITICAL("Failed to load texture. Error: {1}", path.c_str(), IMG_GetError());
    // TODO: Should throw an exception here and not allow application to continue running
    return;
  }
  CORE_DEBUG("Texture successfully initialized");
}

Texture::Texture(Renderer& renderer, const Surface& surface) {
  texture_ = SDL_CreateTextureFromSurface(renderer.get_renderer(), surface.get_surface());
  if (texture_ == nullptr) {
    CORE_CRITICAL("Failed to load texture. Error: {}", SDL_GetError());
    // TODO: Should throw an exception here and not allow application to continue running
    return;
  }
  CORE_DEBUG("Texture successfully initialized");
}

Texture::~Texture() {
  if (texture_ != nullptr)
    SDL_DestroyTexture(texture_);
  CORE_DEBUG("Texture successfully destroyed");
}

Texture& Texture::load_from_file(Renderer& renderer, const std::string& path) {
  texture_ = IMG_LoadTexture(renderer.get_renderer(), path.c_str());
  if (texture_ == nullptr) {
    CORE_CRITICAL("Failed to load texture. Error: {1}", path.c_str(), IMG_GetError());
    // TODO: Should throw an exception here and not allow application to continue running
  }
  CORE_DEBUG("Texture successfully initialized");
  return *this;
}

Texture& Texture::create_from_surface(Renderer& renderer, const Surface& surface) {
  texture_ = SDL_CreateTextureFromSurface(renderer.get_renderer(), surface.get_surface());
  if (texture_ == nullptr) {
    CORE_CRITICAL("Failed to load texture. Error: {}", SDL_GetError());
    // TODO: Should throw an exception here and not allow application to continue running
  }
  CORE_DEBUG("Texture successfully initialized");
  return *this;
}

// Texture& Texture::UpdateText(Renderer& renderer, Font& font, const char* text, SDL_Color& color)
// {
Texture& Texture::update_text(Renderer& renderer, Font& font, std::string text, SDL_Color& color) {
  SDL_DestroyTexture(texture_);
  Surface surface(TTF_RenderText_Solid(font.get_font(), text.c_str(), color));
  texture_ = SDL_CreateTextureFromSurface(renderer.get_renderer(), surface.get_surface());
  return *this;
}

void Texture::destroy() {
  SDL_DestroyTexture(texture_);
  CORE_DEBUG("Texture Destroyed!");
}

SDL_Texture* Texture::get_texture() const { return texture_; }

int Texture::get_width() const {
  int width;
  if (SDL_QueryTexture(texture_, nullptr, nullptr, &width, nullptr) != 0) {
    CORE_ERROR("Failed to get width of texture");
  }
  return width;
}

int Texture::get_height() const {
  int height;
  if (SDL_QueryTexture(texture_, nullptr, nullptr, nullptr, &height) != 0) {
    CORE_ERROR("Failed to get height of texture");
  }
  return height;
}

} // namespace SDLWrap
