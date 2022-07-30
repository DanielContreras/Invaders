#include "sdlwrap/renderer.h"

#include "log.h"
#include "sdlwrap/window.h"

namespace SDLWrap {

Renderer::Renderer(Window& window, int index, Uint32 flags) : renderer_(nullptr) {
  renderer_ = SDL_CreateRenderer(window.GetWindow(), index, flags);
  if (renderer_ == nullptr) CORE_ERROR("Renderer failed to init. Error {}", SDL_GetError());
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

Renderer& Renderer::Copy() { return *this; }

Renderer& Renderer::Present() {
  SDL_RenderPresent(renderer_);
  return *this;
}

}  // namespace SDLWrap
