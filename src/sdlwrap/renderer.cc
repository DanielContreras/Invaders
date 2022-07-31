#include "sdlwrap/renderer.h"

#include <SDL2/SDL_render.h>

#include "log.h"
#include "sdlwrap/texture.h"
#include "sdlwrap/window.h"

namespace SDLWrap {

Renderer::Renderer(Window& window, int index, uint32_t flags) : renderer_(nullptr) {
  renderer_ = SDL_CreateRenderer(window.GetWindow(), index, flags);
  if (renderer_ == nullptr) {
    CORE_CRITICAL("Renderer failed to init. Error {}", SDL_GetError());
    // TODO: Should throw an exception here and not allow application to continue running
    return;
  }
  CORE_DEBUG("Renderer successfully initialized");
}

Renderer::~Renderer() {
  if (renderer_ != nullptr) {
    SDL_DestroyRenderer(renderer_);
    CORE_DEBUG("Renderer successfully destroyed");
  }
}

SDL_Renderer* Renderer::GetRenderer() const { return renderer_; }

Renderer& Renderer::Clear() {
  SDL_RenderClear(renderer_);
  return *this;
}

Renderer& Renderer::Copy(Texture& texture, const SDL_Rect& src, const SDL_Rect& dst) {
  if (SDL_RenderCopy(renderer_, texture.GetTexture(), &src, &dst) != 0) {
    CORE_CRITICAL("Failed to render. Error: {}", SDL_GetError());
    // TODO: Should throw an exception here and not allow application to continue running
  }
  return *this;
}

Renderer& Renderer::Copy(Texture& texture) {
  if (SDL_RenderCopy(renderer_, texture.GetTexture(), nullptr, nullptr) != 0) {
    CORE_CRITICAL("Failed to render. Error: {}", SDL_GetError());
    // TODO: Should throw an exception here and not allow application to continue running
  }
  return *this;
}

Renderer& Renderer::Present() {
  SDL_RenderPresent(renderer_);
  return *this;
}

}  // namespace SDLWrap
